#
main: ./src/main.cpp
	clang++ \
		-g \
		-Wall \
		-Wextra \
		-I /usr/local/include \
		-L /usr/local/lib/ \
		-std=c++14 \
		-o annorna \
		./src/main.cpp \
		./src/gff.cpp
