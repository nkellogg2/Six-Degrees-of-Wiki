CC = g++
executable = wikipedia_game.exe
source = $(wildcard *.cpp)
wikipedia: clean
	$(CC) -o $(executable) $(source) -std=c++11
	$(executable)
clean:
	del $(executable)