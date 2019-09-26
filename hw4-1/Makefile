all: dynamic_array function_overloading string
dynamic_array: dynamic_array.o
	g++ -o dynamic_array dynamic_array.o
function_overloading: function_overloading.o
	g++ -o function_overloading function_overloading.o
string: string.o
	g++ -o string string.o
dynamic_array.o: dynamic_array.cc
	g++ -c dynamic_array.cc
function_overloading.o: function_overloading.cc
	g++ -c function_overloading.cc
string.o: string.cc
	g++ -c string.cc
clean:
	rm dynamic_array dynamic_array.o string string.o function_overloading function_overloading.o