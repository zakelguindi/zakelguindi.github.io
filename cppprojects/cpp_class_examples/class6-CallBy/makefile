# target  : prerequisites/dependencies
# tab command
#
#	$@ target
# $< first prerequisite
# $^ all prerequisites

# -I for the include path, adding the current directory (.)
flags = -std=c++17 -Wall -I .

myfunctions.o : myfunctions.cc myfunctions.h
	g++ $(flags) -c $<

testGCD.o : testGCD.cc myfunctions.h
	g++ $(flags) -c $<

testGCD : testGCD.o myfunctions.o
	g++ $(flags) $^ -o $@
	./testGCD

testQuadraticFormula.o : testQuadraticFormula.cc myfunctions.h
	g++ $(flags) -c $<

testQuadraticFormula : testQuadraticFormula.o myfunctions.o
	g++ $(flags) $^ -o $@
	./testQuadraticFormula

testavg : testmean.cc myfunctions.o
	g++ $(flags) $^ -o $@
	./$@

clean :
	rm *.o testQuadraticFormula testGCD

