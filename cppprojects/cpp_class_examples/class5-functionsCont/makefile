#target : prerequisites/dependencies 
# tab command 
#
# $@ target 
# $< target 
# $^ all prereqs 

# -I for the include path, adding the current directory (.)
flags = -std=c++17 -Wall -I . 

myfunctions.o : myfunctions.cc myfunctions.h 
	g++ $(flags) -c $<

functionscont.o : functionscont.cc myfunctions.h 
	g++ $(flags) -c $<

functionscont : functionscont.o myfunctions.o
	g++ $(flags) $^ -o $@ 
	./functionscont

clean : 
	rm functionscont.o functionscont