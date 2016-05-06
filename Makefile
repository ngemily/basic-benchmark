CC = clang
ifeq ($(NO_OPT),1) 
	CFLAGS += -O0
else
	CFLAGS += -O3
endif

SRCDIR = suite
BINDIR = bin

SOURCES := $(wildcard suite/*.c)
LL      := $(SOURCES:.c=.ll)
ASM     := $(SOURCES:.c=.s)
PNG     := $(SOURCES:.c=.png)
DOT     := $(SOURCES:.c=.dot)
PS      := $(SOURCES:.c=.ps)
OBJS    := $(patsubst $(SRCDIR)%, $(BINDIR)%, $(SOURCES:.c=))

all: $(ASM) $(LL) $(OBJS) $(PNG)

%.s : override CC = arm-linux-gnueabi-gcc-4.7
%.s : CFLAGS += -S -std=c99
%.s : %.c
	$(CC) $(CFLAGS) -o $@ $<

%.ll : CFLAGS += -S -emit-llvm
%.ll : %.c
	$(CC) $(CFLAGS) -o $@ $<

$(BINDIR)/% : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

# opt will print reg.<func>.dot for each function in $<
# currently only use reg.main.dot
%.dot : %.ll
	opt $(CFLAGS) -disable-output -dot-regions $<
	$(foreach obj, $(wildcard *.dot), echo $(obj);)
	mv reg.main.dot $@

%.ps : %.dot
	dot -Tps -o $@ $<

%.png : %.ps
	convert $< $@

test: $(OBJS)
	$(foreach obj, $(OBJS), $(obj);)

clean:
	rm -f $(ASM) $(LL) $(OBJS) $(PNG) $(DOT) $(PS)
