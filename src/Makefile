main: interface.o history.o
	gcc -o exe interface.o history.o

interface.o: interface.c tokenizer.h
	gcc -c interface.c

history.o: history.c history.h
	gcc -c history.c

clean:
	rm -f exe *.o *~ *#
