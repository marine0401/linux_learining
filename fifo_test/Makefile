.PHONY=all
all:fifo_read fifo_write

fifo_write:fifo_write.o
	cc -o $@ $<
fifo_write.o:fifo_write.c
	cc -c $<
fifo_read:fifo_read.o
	cc -o $@ $<
fifo_read.o:fifo_read.c
	cc -c $<
clean:
	rm -rf ./*.o
