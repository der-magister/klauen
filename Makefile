CC = 		lcc -Wa-l -Wl-m -Wl-j

BIN = 		klauen.gb

all:		$(BIN)

clean:		
		rm -rf obj/* bin/*

showromusage:	
		romusage obj/klauen.map -sRe -sRp


tilesets.o:	daten/tilesets/tilesets.c
		$(CC) -c -o obj/tilesets.o daten/tilesets/tilesets.c

sprites.o:	daten/spritesets/sprites.c
		$(CC) -c -o obj/sprites.o daten/spritesets/sprites.c

guidata.o:	daten/gui/guidata.c 
		$(CC) -c -o obj/guidata.o daten/gui/guidata.c

shieldtxt.o:	daten/txt/shields/shieldtxt.c
		$(CC) -c -o obj/shieldtxt.o daten/txt/shields/shieldtxt.c

chesttxt.o:	daten/txt/chest/chesttxt.c
		$(CC) -c -o obj/chesttxt.o daten/txt/chest/chesttxt.c

othertxt.o:	daten/txt/other/othertxt.c 
		$(CC) -c -o obj/othertxt.o daten/txt/other/othertxt.c

lvldat.o:	daten/lvl/lvldat.c
		$(CC) -c -o obj/lvldat.o daten/lvl/lvldat.c

klauen.o:	klauen.c
		$(CC) -c -o obj/klauen.o klauen.c 

globals.o:	globals.c
		$(CC) -c -o obj/globals.o globals.c

engine.o:	engine.c
		$(CC) -c -o obj/engine.o engine.c

init.o:		init.c
		$(CC) -c -o obj/init.o init.c

player.o:	player.c
		$(CC) -c -o obj/player.o player.c

gui.o:		gui.c
		$(CC) -c -o obj/gui.o gui.c

environment.o:	environment.c
		$(CC) -c -o obj/environment.o environment.c

text.o:		text.c 
		$(CC) -c -o obj/text.o text.c

level.o:	level.c
		$(CC) -c -o obj/level.o level.c

enemy.o:	enemy.c 
		$(CC) -c -o obj/enemy.o enemy.c

others.o:	others.c
		$(CC) -c -o obj/others.o others.c

klauen.gb:	globals.o klauen.o tilesets.o sprites.o guidata.o shieldtxt.o othertxt.o lvldat.o engine.o init.o player.o gui.o environment.o text.o level.o enemy.o others.o chesttxt.o

		$(CC) -Wl-yt0x019 -Wl-ya1B -Wm-yn"KLAUEN" -o obj/klauen.gb obj/klauen.o obj/globals.o obj/tilesets.o obj/guidata.o obj/shieldtxt.o obj/othertxt.o obj/lvldat.o obj/sprites.o obj/engine.o obj/init.o obj/player.o obj/gui.o obj/environment.o obj/text.o obj/level.o obj/enemy.o obj/others.o obj/chesttxt.o

		romusage obj/klauen.map -sRe -sRp
		cp -rf obj/klauen.gb bin/
