# this is how we write a comment in makefiles 
# target : prerequisites/dependencies 
# $@ = target 
# $< = first prerequisite/dependency
# $^ = all prerequisites/dependencies

flags = -std=c++17 -Wall
functions.o : functions.cc
	g++ $(flags) $< -c 

functions : functions.o 
	g++ $(flags) functions.cc -o $@ 
	./functions


clean : 
	rm functions.o functions