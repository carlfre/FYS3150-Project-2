headers := $(wildcard include/*.hpp)
sources := $(wildcard src/*.cpp)

main: main.cpp $(headers) $(sources)
	g++ main.cpp $(sources) -I include -o main -std=c++11 -larmadillo

latex: main
	pdflatex latex/project.tex
	rm -f project.log
	rm -f project.aux
	rm -f texput.log
	rm -f project.out
	rm -f projectNotes.bib
	rm -f amsmath.aux

clean:
	rm -f main
	rm -f -rf data
	rm -f -rf plots
