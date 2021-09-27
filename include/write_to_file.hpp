#ifndef __write_to_file__
#define __write_to_file__

#include <iostream>
#include <fstream>
#include <vector>
#include <armadillo>

void write_two_integer_vectors_to_file(std::string csv_filename, std::vector<int> v1, std::vector<int> v2);

void write_3_armadillo_vectors_to_file(std::string csv_filename, arma::vec header,
                                       arma::vec v1, arma::vec v2, arma::vec v3);

#endif
