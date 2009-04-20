ifeq ($(DEBUG),yes)
	CXXFLAGS=-Wall -g  
	LDFLAGS=-Wall -g -framework CoreServices -framework Cocoa -framework OpenGL -lpng12
	DEFENITIONS= -D DEBUG=1
else
	CXXFLAGS=-Wall
	LDFLAGS=-O3 -Wall -framework CoreServices -framework Cocoa -framework OpenGL -lpng12
	DEFENITIONS=
endif

PROJECT=t00
CC=g++
SRCPATH=src
OBJECTS=$(BINPATH)/main.o
OBJFILES := $(patsubst %.cpp,%.o,$(wildcard $(SRCPATH)/*.cpp))
TARGETS=pixeltoaster $(PROJECT)
HOMEINC=$(HOME)/include
INCLUDES=-I$(HOMEINC)
T00PATH=$(PWD)
PTMAKEVAR=-f makefile.apple
PTOBJ=PixelToaster*.o
PTDIR=../pixeltoaster

main: $(TARGETS)

pixeltoaster:
#	ifneq ($(@test -d $(PTDIR)),)
#		echo "Could not find pixeltoaster.\nDownload from pixeltoaster.com"
#		@exit 1
#	else
	cd $(PTDIR) && make $(PTMAKEVAR)
	cp $(PTDIR)/PixelToaster*h $(HOMEINC)
#	endif

readpng:
	$(CC) $(CXXFLAGS) -c src/readpng.c -o src/readpng.o	

$(PROJECT): $(OBJFILES)
	$(CC) $(INCLUDES) $(OBJFILES) $(wildcard $(PTDIR)/*.o) $(LDFLAGS) -o $(@)

$(SRCPATH)/%.o: $(SRCPATH)/%.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) $(DEFENITIONS) -c $< -o $@

clean:
	@rm -f $(SRCPATH)/*.o $(SRCPATH)/*.gch $(LIBPATH)/*.gch $(TARGETS)