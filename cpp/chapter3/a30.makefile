# This is a makefile to compile a1 & a2 programs & subsequently run them.

CPP = g++
CPPFLAGS = -c
LINKER_FLAGS = -o

all: a1_main.out a2_main.out
	./a1_main.out
	echo -e '\n'
	./a2_main.out

clean:
	rm -f *.out *.o

a1_main.out: a1_main.o a1_func.o
a2_main.out: a2_main.o

a1_func.o: a1_func.cpp a1_func.h
a1_main.o: a1_main.cpp
a2_main.o: a2_main.cpp

%.out: %.o
	$(CPP) $(LINKER_FLAGS) $@ $^

.SUFFIXES = .o .cpp .out
.cpp.o:
	$(CPP) $(CPPFLAGS) $<

.o.out:
	$(CPP) $(LINKER_FLAGS) $@ $<

