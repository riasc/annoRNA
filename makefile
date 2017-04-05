#
main: ./src/main.cpp
	clang++ \
		-g \
		-Wall \
		-Wextra \
		-I /usr/local/include \
		-L /usr/local/lib/ \
		-std=c++14 \
		./src/main.cpp \
		./src/GeneralFeatureFormat.h \
		./src/GeneralFeatureFormat.cpp 
