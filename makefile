# COMPILER/FLAGS
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g

#OBJECTS
OBJS = desert.o forest.o game.o space.o main.o menu.o snow.o helpers.o

# SOURCES (.CPP)
SRCS = game.cpp desert.cpp forest.cpp game.cpp main.cpp snow.cpp space.cpp helpers.cpp menu.cpp

# HEADERS (.HPP)
HEADERS = game.hpp desert.hpp forest.hpp game.hpp snow.hpp space.hpp helpers.hpp menu.hpp

${PROJNAME}: ${OBJS}
	${CXX} ${OBJS} -o ${PROJNAME}

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#Remove executable and object files
clean:
	rm -f ${PROJNAME} ${OBJS}