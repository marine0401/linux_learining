
.PHONY=all
all:test file_creat
test:test.o
	cc -o test test.o
test.o:test.c
	cc -c test.c
file_creat:file_creat.o
	cc -o $@ $<
file_creat.o:file_creat.c
	cc -c $<
