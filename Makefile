headers := $(wildcard include/*.hpp)
sources := $(wildcard src/*.cpp)

main: main.cpp $(headers) $(sources)
	g++ main.cpp $(sources) -I include -o main -std=c++11 -larmadillo

latex: main problem6 problem7
	pdflatex latex/project.tex
	pdflatex latex/project.tex
	rm -f project.log
	rm -f project.aux
	rm -f texput.log
	rm -f project.out
	rm -f projectNotes.bib
	rm -f amsmath.aux

test: main
	./main test

problem6: main
	./main problem6
	python3 src/plot.py problem6

problem7: main
	./main problem7
	python3 src/plot.py problem7

clean:
	rm -f main
	rm -f -rf data/*.csv
	rm -f -rf plots/*.pdf
