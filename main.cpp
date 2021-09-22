#include <iostream>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"

using namespace std;

int main(int argc, char *argv[]) 
{
    arma::mat tridiagonal = create_symmetric_tridiagonal(4, 0.5, 1.0);
    tridiagonal.print();
    return 0;
}