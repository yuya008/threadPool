CC = clang
programname = test
flag = -g
obj = main.o queue.o

test: $(obj)
	$(CC) $(flag) $(obj) -o $(programname)

main.o: main.c tpool.h
	$(CC) $(flag) main.c -c

queue.o: queue.c queue.h tpool.h
	$(CC) $(flag) queue.c queue.h tpool.h -c

clean:
	rm -rf *.o $(programname) *.gch
