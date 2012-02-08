OBJ = main.o \
	video.o \
	SDL_prim.o \
	led_panel.o \
	load_png.o \
	led.o \
	FileFactory.o \
	FileObject.o

CPPFLAGS += `sdl-config --cflags` -g -I/usr/local/include
LDFLAGS += `sdl-config --libs` -lm -lpng -L/usr/local/lib

PROG = t

all: $(OBJ)
	g++ -Wall -o $(PROG) $(OBJ) $(LDFLAGS) $(CPPFLAGS)

.cpp.o:
	g++ -c -Wall $(CPPFLAGS) $<
.c.o:
	gcc -c -Wall $(CPPFLAGS) $<

clean:
	rm *.o $(PROG) 2>/dev/null
