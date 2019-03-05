CXXFLAGS += -O2
# CXXFLAGS += -Wall
# CXXFLAGS += -Wextra
# CXXFLAGS += -pedantic
# CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

CXXFLAGS += -I../googletest/include
CXXFLAGS += -I../../isbn-asm/src

GTEST_OBJ = ../googletest/gtest-all.o
ISBN_FUNC_OBJ = ../../isbn-asm/src/*.o

OBJDIR = ./obj

all:
	${CXX} -c main.cpp -o ${OBJDIR}/main.o ${CXXFLAGS}
	${CXX} ${GTEST_OBJ} ${ISBN_FUNC_OBJ} ${OBJDIR}/*.o -o cppasm-test.exe
