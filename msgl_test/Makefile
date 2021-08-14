.PHONY=all
all: test1 test2

test1:test1.o
	cc -o $@ $<
test1.o:test1.c
	cc -c $<
test2:test2.o
	cc -o $@ $<
test2.o:test2.c
	cc -c $<
clean:
	rm -rf ./*.o
