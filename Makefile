CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = check.mate
OBJECTS = main.o board.o piece.o pawn.o knight.o bishop.o rook.o queen.o king.o textdisplay.o player.o human.o engine.o level1.o level2.o level3.o level4.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} -g ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
