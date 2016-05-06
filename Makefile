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

SOURCES := $(shell find $(SRCDIR) -type f -name '*.c')
LL      := $(SOURCES:.c=.ll)
ASM     := $(SOURCES:.c=.s)
PNG     := $(SOURCES:.c=.png)
DOT     := $(SOURCES:.c=.dot)
PS      := $(SOURCES:.c=.ps)
OBJS    := $(patsubst $(SRCDIR)%, $(BINDIR)%, $(SOURCES:.c=))

all: $(ASM) $(LL) $(OBJS) $(PNG)

$(BINDIR):
	mkdir -p $(BINDIR)

%.s : CFLAGS += -S
%.s : %.c
	$(CC) $(CFLAGS) -o $@ $<

%.ll : CFLAGS += -S -emit-llvm
%.ll : %.c
	$(CC) $(CFLAGS) -o $@ $<

$(BINDIR)/% : $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)/$(@F) $<

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
	$(foreach obj, $(shell find $(BINDIR) -type f), \
		qemu-arm -L /usr/arm-linux-gnueabihf $(obj);)

clean:
	rm -f $(ASM) $(LL) $(OBJS) $(PNG) $(DOT) $(PS)
