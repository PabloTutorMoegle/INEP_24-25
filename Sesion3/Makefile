CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

# List of source files
SRCS = Menu.cpp CapaDePresentacio.cpp ConnexioDB.cpp singleton.cpp

TARGET = Menu.exe
# Compile and link
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) -lmysqlcppconn

# Clean up
clean:
	rm -f $(TARGET) *.o

