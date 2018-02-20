CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = die.o creature.o goblin.o barbarian.o reptilepeople.o bluemen.o theshadow.o team.o pile.o assignment4.o

SRCS = die.cpp creature.cpp goblin.cpp barbarian.cpp reptilepeople.cpp bluemen.cpp theshadow.cpp team.cpp pile.cpp assignment4.cpp

HEADERS = die.hpp creature.hpp goblin.hpp barbarian.hpp reptilepeople.hpp bluemen.hpp theshadow.hpp team.hpp pile.hpp

assignment4: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o assignment4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm -f *.o a.out assignment4
