CHIBICC=../chibicc/chibicc

ifeq ($(shell test -e $(CHIBICC) && echo yes),)
$(error "chibicc binary not found; did you compile it?")
endif

all: 01 02 03 04 05

%: %.c
	$(CHIBICC) -o $@.bin $<

test:
	./01.bin
	./02.bin
	./03.bin
	./04.bin
	./05.bin

clean:
	rm -f *.bin
