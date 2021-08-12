object=test.o

test:${object}
	cc -o $@ $<
test.o:test.c
	cc -c $<
clean:
	rm -rf ./*.o
