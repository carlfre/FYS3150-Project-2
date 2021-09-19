headers := $(wildcard include/*.hpp)
sources := $(wildcard src/*.cpp)

main: main.cpp $(headers) $(sources)
	g++ main.cpp $(sources) -I include -o main -std=c++11 -larmadillo

latex: main
	cd latex
	pdflatex project.tex
	rm -f project_1.log
	rm -f project_1.aux
	rm -f texput.log
	cd ../
	mv latex/project.pdf project.pdf

clean:
	rm -f main
	rm -f -rf data
	rm -f -rf plots
