CLANGXX = clang++ 
CFLAGS = -g -Wall -Wextra 

INCLUDE = ./include/
SDIR = ./src/
BDIR = ./bin/ 

OBJ = ./bin/annorna.o
SRC = $(wildcard ./src/*.cpp)

STD= c++14 
STDLIB = libc++

I = /usr/local/include 

annorna: $(SRC)
	$(CLANGXX) \
		$(CFLAGS) \
		-std=$(STD) \
		-stdlib=$(STDLIB) \
		-I /usr/local/include/boost \
		-L /usr/local/lib \
		-l boost_program_options \
		-l boost_filesystem \
		-l boost_system \
		$(SRC) \
		-o $(OBJ)
