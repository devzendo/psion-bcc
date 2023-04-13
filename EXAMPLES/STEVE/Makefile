CC=bcc

all: hello.img notify.img

clean:	
	rm -f *.o *.s

realclean:
	@make clean
	rm -f *.img

hello.img: hello.o
	bcc -v -s4096 -o hello.img hello.o -lepoc

notify.img: notify.o
	bcc -v -s1024 -o notify.img notify.o -lepoc
