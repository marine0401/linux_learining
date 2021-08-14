.PHONY=all
all:test1 test2

test1:test1.o
	cc -o $@ $< -lpthread
test1.o:test1.c
	cc -c $<
test2:test2.o
	cc -o $@ $< -lpthread
test2.o:test2.c
	cc -c $<



clean:
	rm ./*.o -rf
