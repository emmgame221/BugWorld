CC=g++

ODIR=obj
DEPS=Bug.h Button.h ButtonSprite.h Entity.h Game.h InfoMenu.h Tile.h Utilities.h
_OBJ=main.o Game.o Entity.o Bug.o Button.o ButtonSprite.o Tile.o InfoMenu.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -std=c++17 -c -o $@ $< $(LIBS)

bugworld: $(OBJ)
	$(CC) -std=c++17 -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o