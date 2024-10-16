CXX = g++
OBJECTS = MazeGenerator.o Labyrinth.o Main.o
#FLAGS = -std=c++2a
SOURCE = $(wildcard *.cpp)

demo: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o demo

# $< refers to the first prequisite
# $@ refers to the target
%.o: %.cpp %.h
	$(CXX) -c $< -o $@

run: demo
	./demo

echo:
	echo $(SOURCE)

debug:
	g++ MazeGenerator.cpp Labyrinth.cpp Main.cpp -o demo -g
	gdb demo

clean: 
	rm -f *.o demo
