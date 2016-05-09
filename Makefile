CC = clang
override CFLAGS += -target armv7a-linux-gnueabihf \
		-mcpu=cortex-a9 -mfloat-abi=hard \
		-I/usr/arm-linux-gnueabihf/include/c++/4.7.3/arm-linux-gnueabihf/ \
		-I/usr/arm-linux-gnueabihf/include/ \
		-ccc-gcc-name arm-linux-gnueabihf-gcc
ifeq ($(NO_OPT),1) 
	override CFLAGS += -O0
else
	override CFLAGS += -O3
endif

SRCDIR = suite
BINDIR = bin

AUTOC_SCRIPT  = scripts/autoc.pl
AUTOC_DIR     = suite/auto
JSONDIR       = json
JSON         := $(shell find $(JSONDIR) -type f -name '*.json')

SOURCES := $(shell find $(SRCDIR) -type f -name '*.c')
LL      := $(SOURCES:.c=.ll)
ASM     := $(SOURCES:.c=.s)
PNG     := $(SOURCES:.c=.png)
DOT     := $(SOURCES:.c=.dot)
PS      := $(SOURCES:.c=.ps)
OBJS    := $(patsubst $(SRCDIR)%, $(BINDIR)%, $(SOURCES:.c=))
OBJDIRS := $(patsubst $(SRCDIR)%, $(BINDIR)%, $(shell find $(SRCDIR) -type d))

all: autoc $(ASM) $(LL) $(OBJS) $(PNG)

asm: autoc $(ASM)

ll: autoc $(LL)

objs: autoc $(OBJS)

png: $(PNG)

$(AUTOC_DIR) $(OBJDIRS):
	mkdir -p $@

# This targt builds c files from assembly, specified in json.
autoc: $(JSON) | $(AUTOC_DIR)
	$(foreach obj, $?, $(AUTOC_SCRIPT) $(obj) $(AUTOC_DIR);)
	touch autoc

%.s : CFLAGS += -S
%.s : %.c
	$(CC) $(CFLAGS) -o $@ $<

%.ll : CFLAGS += -S -emit-llvm
%.ll : %.c
	$(CC) $(CFLAGS) -o $@ $<

$(BINDIR)/% : $(SRCDIR)/%.c | $(OBJDIRS)
	$(CC) $(CFLAGS) -o $@ $<

# opt will print reg.<func>.dot for each function in $<
# currently only use reg.main.dot
%.dot : %.ll
	opt -disable-output -dot-regions $<
	$(foreach obj, $(wildcard *.dot), echo $(obj);)
	mv reg.main.dot $@

%.ps : %.dot
	dot -Tps -o $@ $<

%.png : %.ps
	convert $< $@

test: $(OBJS)
	@$(foreach obj, $(shell find $(BINDIR) -type f), \
		echo $(obj); \
		qemu-arm -L /usr/arm-linux-gnueabihf $(obj);)

clean:
	rm -f $(ASM) $(LL) $(OBJS) $(PNG) $(DOT) $(PS)
	rm -rf $(BINDIR) $(AUTOC_DIR)
	rm -f autoc
