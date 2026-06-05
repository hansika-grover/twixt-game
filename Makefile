twixt: main.o game.o board.o valid.o geom.o links.o win.o
	gcc -o twixt main.o game.o board.o valid.o geom.o links.o win.o

main.o: main.c game.h
	gcc -c main.c

game.o: game.c game.h board.h valid.h links.h win.h
	gcc -c game.c

board.o: board.c board.h game.h
	gcc -c board.c

valid.o: valid.c valid.h board.h game.h
	gcc -c valid.c

geom.o: geom.c geom.h
	gcc -c geom.c

links.o: links.c links.h board.h geom.h game.h
	gcc -c links.c

win.o: win.c win.h game.h
	gcc -c win.c

clean:
	rm -f main.o game.o board.o valid.o geom.o links.o win.o twixt