.PHONY=all;
all:shm1 shm2

shm1:shm1.o
	cc -o $@ $<
shm1.o:shm1.c shm_com.h
	cc -c $< -I ./
shm2:shm2.o
	cc -o $@ $<
shm2.:shm2.c shm_com.h
	cc -c $< -I ./
clean:
	rm -rf ./*.o
