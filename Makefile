# Example 10
EXE=hw3

# Main target
all: $(EXE)

# Variables for readability
AUX=src/auxiliary/
OBJ=src/objects/
AUXLIB=$(AUX)print.o $(AUX)project.o $(AUX)params.o $(AUX)loadtexbmp.o $(AUX)errcheck.o $(AUX)fatal.o $(AUX)vertex.o
OBJLIB=$(OBJ)cube.o $(OBJ)axes.o $(OBJ)plane.o $(OBJ)grass_blade.o $(OBJ)grass_block.o $(OBJ)fencepost.o $(OBJ)fence.o $(OBJ)moon.o

#  MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall
LIBS=-lglut32cu -lglu32 -lopengl32
CLEAN=del *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -Wno-deprecated-declarations
LIBS=-framework GLUT -framework OpenGL
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall
LIBS=-lglut -lGLU -lGL -lm
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) src/*.o src/*.a $(AUX)*.o $(OBJ)*.o
endif

# Dependencies
src/hw3.o: src/hw3.c src/hw3_defs.h
src/auxiliary/print.o: $(AUX)print.c src/hw3_defs.h
src/auxiliary/project.o: $(AUX)project.c src/hw3_defs.h
src/auxiliary/params.o: $(AUX)params.c src/hw3_defs.h
src/auxiliary/loadtexbmp.o: $(AUX)loadtexbmp.c src/hw3_defs.h
src/auxiliary/errcheck.o: $(AUX)errcheck.c src/hw3_defs.h
src/auxiliary/fatal.o: $(AUX)fatal.c src/hw3_defs.h
src/auxiliary/vertex.o: $(AUX)vertex.c src/hw3_defs.h
src/objects/cube.o: $(OBJ)cube.c src/hw3_defs.h
src/objects/axes.o: $(OBJ)axes.c src/hw3_defs.h
src/objects/plane.o: $(OBJ)plane.c src/hw3_defs.h
src/objects/grass_blade.o: $(OBJ)grass_blade.c src/hw3_defs.h
src/objects/grass_block.o: $(OBJ)grass_block.c src/hw3_defs.h
src/objects/fencepost.o: $(OBJ)fencepost.c src/hw3_defs.h
src/objects/fence.o: $(OBJ)fence.c src/hw3_defs.h
src/objects/moon.o: $(OBJ)moon.c src/hw3_defs.h

# Create archives
src/hw3_defs.a:$(AUXLIB) $(OBJLIB)
	ar -rcs $@ $^

# Compile rules
src/%.c.o:
	gcc -c $(CFLG) $<
src/%.cpp.o:
	g++ -c $(CFLG) $<
src/auxiliary/%.c.o:
	gcc -c $(CFLG) $<
src/%.cpp.o:
	g++ -c $(CFLG) $<

# Link
hw3:src/hw3.o src/hw3_defs.a
	gcc -O3 -o $@ $^ $(LIBS)

# Clean
clean:
	$(CLEAN)	