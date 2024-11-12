CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

Menu.exe: Menu.o ConnexioDB.o 
	$(LINK.cc) -o $@ $^ -lmysqlcppconn
Menu.o: Menu.cpp ConnexioDB.hpp

ConnexionDB.o: ConnexioDB.cpp ConnexioDB.hpp

