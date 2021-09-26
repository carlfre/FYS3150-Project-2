# FYS3150-Project-2
*By Carl Fredrik Nordbø Knutsen, Didrik Sten Ingebrigtsen, and Jan Harald Aasen*

This project aims to solve a special case of a one-dimensional buckling beam problem by discretizing the given differential equation and turning it into a eigenvalue problem.

##Usage
There is a 'Makefile' included, meaning that the c++ code can be built by running 'make main'. When running the executable main, a command line argument should be included.

* './main test' runs the tests from exercises 3, 4, 5. The program prints eigenvectors and eigenvalues computed with 3 different methods, such that one can compare them.
* './main problem6' writes number of iterations calculated in problem 6 to 'data/number_of_iterations.csv
* './main problem7' writes calculated eigenvalues and eigenvectors in problem 7 to files 'data/3_eigvecs_n_equals_10.csv' and 'data/3_eigvecs_n_equals_100.csv'. Plots from problem 7 can be obtained by running 'src/plot.py'
