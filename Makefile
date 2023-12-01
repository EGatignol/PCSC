
CXXFLAGS=-g -Wall
CC_FILES     = result_method.cc function.cc polynomial_1_to_n.cc m_to_n.cc find_root.cc fixed_point.cc newton.cc classic_chord.cc bissection.cc
OBJ_FILES    = result_method.o function.o polynomial_1_to_n.o m_to_n.o find_root.o fixed_point.o newton.o classic_chord.o bissection.o
HEADER_FILES = result_method.hh function.hh polynomial_1_to_n.hh m_to_n.hh find_root.hh fixed_point.hh newton.hh classic_chord.hh bissection.hh

EXEC=main

$(EXEC): $(OBJ_FILES) main.o
	g++ -g $(OBJ_FILES) main.o -o $@

.o: $(HEADER_FILES)
	g++ -c $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o *~ $(EXEC)

