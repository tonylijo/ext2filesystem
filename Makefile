OBJECTS = main.o readsuper.o readbg.o readinode.o readdir.o
CC = cc
readroot:$(OBJECTS)
	$(CC) $(OBJECTS) -o readroot -g
main.o:inode.h superblock.h bg.h dirent.h prototypes.h main.c
	$(CC) -c main.c
readsuper.o:superblock.h readsuper.c
	$(CC) -c readsuper.c -g
readinode.o:inode.h readinode.c
	$(CC) -c readinode.c -g
readbg.o:bg.h readbg.c
	$(CC) -c readbg.c -g
readdir.o:dirent.h readdir.c
	$(CC) -c readdir.c -g
clean:$(OBJECTS)	
	rm -f $(OBJECTS)
install:
	install readroot /bin

