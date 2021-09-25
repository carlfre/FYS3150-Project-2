#include "../include/write_to_file.hpp"

void write_two_integer_vectors_to_file(std::string csv_filename, std::vector<int> v1, std::vector<int> v2)
{
    std::ofstream csvFile(csv_filename);
    int n = v1.size();
    for (int i= 0; i < n; i++)
    {
        csvFile << v1[i] << "," << v2[i] << std::endl;
    }
    csvFile.close();
}