#include "../include/write_to_file.hpp"

void write_two_integer_vectors_to_file(std::string csv_filename, std::vector<int> v1, std::vector<int> v2)
{
    std::ofstream csvFile(csv_filename);
    int n = v1.size();
    for (int i=0; i<n; i++)
    {
        csvFile << v1[i] << "," << v2[i] << std::endl;
    }
    csvFile.close();
}

void write_3_armadillo_vectors_to_file(std::string csv_filename, arma::vec header,
                                       arma::vec v1, arma::vec v2, arma::vec v3)
{
    //assuming equal length of v1, v2, v3
    std::ofstream csvFile(csv_filename);
    int n = v1.size();
    csvFile << header(0) << "," << header(1) << "," << header(2) << std::endl;
    for (int i=0; i<n; i++)
    {
        csvFile << std::endl << v1(i) << "," << v2(i) << "," << v3(i);
    }
    csvFile.close();
}