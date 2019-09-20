all: array_struct_point print_point score_graph
array_struct_point: array_struct_point.o
	g++ -o array_struct_point array_struct_point.o
print_point: print_point.o
	g++ -o print_point print_point.o
score_graph: score_graph.o
	g++ -o score_graph score_graph.o
array_struct_point.o: array_struct_point.cc
	g++ -c array_struct_point.cc
print_point.o: print_point.cc
	g++ -c print_point.cc
score_graph.o: score_graph.cc
	g++ -c score_graph.cc
clean:
	rm array_struct_point array_struct_point.o score_graph score_graph.o print_point print_point.o