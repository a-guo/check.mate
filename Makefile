CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = checkmate
OBJECTS = main.o board.o piece.o pawn.o knight.o bishop.o rook.o queen.o king.o textdisplay.o player.o human.o engine.o level1.o level2.o level3.o trashbin.o window.o
DEPENDS = ${OBJECTS:.o=.d}
LIBDIR  = -L/usr/X11/lib -L/usr/X11R6/lib
XLIBS   = -lX11 

${EXEC}: ${OBJECTS}
	${CXX} -g ${CXXFLAGS} ${OBJECTS} -o ${EXEC} $(LIBDIR) $(XLIBS)

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
