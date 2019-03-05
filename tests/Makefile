CXXFLAGS += -O2
# CXXFLAGS += -Wall
# CXXFLAGS += -Wextra
# CXXFLAGS += -pedantic
# CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

CXXFLAGS += -I../googletest/include
CXXFLAGS += -I../../isbn-asm/isbn-10
CXXFLAGS += -I../../isbn-asm/isbn-13

GTEST_OBJ = ../googletest/gtest-all.o
ISBN_FUNC_OBJ  = ../../isbn-asm/isbn-10/*.o
ISBN_FUNC_OBJ += ../../isbn-asm/isbn-13/*.o

OBJDIR = ./obj

all:
	${CXX} -c main.cpp -o ${OBJDIR}/main.o ${CXXFLAGS}
	${CXX} -c test-isbn-10.cpp -o ${OBJDIR}/test-isbn-10.o ${CXXFLAGS}
	${CXX} ${GTEST_OBJ} ${ISBN_FUNC_OBJ} ${OBJDIR}/*.o -o isbn-test.exe
