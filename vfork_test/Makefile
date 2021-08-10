object=test.o
CFLAG=-o
test:${object}
	cc ${CFLAG} $@ ${object}
test.o:test.c
	cc -c $<
clean:
	rm -rf ./*.o
