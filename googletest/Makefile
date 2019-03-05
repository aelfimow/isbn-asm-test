CXXFLAGS += -O2
# CXXFLAGS += -Wall
# CXXFLAGS += -Wextra
# CXXFLAGS += -pedantic
# CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

CXXFLAGS += -I.
CXXFLAGS += -I./include

OBJDIR = .

.PHONY: all

all:
	${CXX} -c src/gtest-all.cc -o ${OBJDIR}/gtest-all.o ${CXXFLAGS}
	@echo No errors
