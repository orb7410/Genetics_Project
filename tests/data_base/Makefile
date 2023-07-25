CXX= g++
CC = $(CXX)

CXXFLAGS  = -pedantic -Wall -Werror -Wextra
CXXFLAGS += -ggdb
CXXFLAGS += -std=c++17

LDLIBS = -ljsoncpp -lcurl -lcurlpp -lgumbo
LDFLAGS = -L/usr/local/lib

CPPFLAGS = -DDEBUG
CPPFLAGS = -I$(INCLUDES_DIR) -I$(CURL_INCLUDES_DIR)

INCLUDES_DIR = ../../inc
CURL_INCLUDES_DIR = /usr/local/include
SOURCES_DIR = ../../src

SOURCE := utest.cpp \
			$(SOURCES_DIR)/data_base.cpp \

TARGET := utest

all: $(TARGET)

utest : $(SOURCE)

check : $(TARGET)
	@./$(TARGET) -v

recheck: clean check

clang_check: CXX = clang++
clang_check: check

clean:
	@$(RM) ./$(TARGET) *.o

vala: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

hell: $(TARGET)
	valgrind  --tool=helgrind ./$(TARGET) 2> hell.txt

.PHONY : make clean check recheck all vala hell
