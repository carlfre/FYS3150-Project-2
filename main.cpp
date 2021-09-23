#include <iostream>
#include <cmath>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"
#include "test_matrix.hpp"

using namespace std;

int main(int argc, char *argv[]) 
{
    test_6_by_6_symmetric_with_eig_sym();
    return 0;
}