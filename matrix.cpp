#include "matrix.hpp"
#include <iostream>
#include <vector>

// Constructor that initializes an NxN matrix filled with 0's
Matrix::Matrix(size_t N) {
    data.resize(N, std::vector<int>(N, 0));
}

// Constructor that initializes a matrix with a given array
Matrix::Matrix(std::vector<std::vector<int>> numbers) {
    data = numbers;
}

// Returns the sum of two matrices
Matrix Matrix::operator+(const Matrix &rhs) const {
    std::size_t N = data.size(); // Gets the size of the matrices we are working with
    Matrix result(N); // Creates a matrix of correct size to store the result

    for (std::size_t i = 0; i < N; i++) { // Iterates over the rows of the matrices
        for (std::size_t j = 0; j < N; j++) { // Iterates over the columns of the matrices
            result.data[i][j] = data[i][j] + rhs.data[i][j]; // Puts the sum in the resultant matrix
        }
    }
    return result; // Returns the resultant matrix
}

// Returns the dot product of two matrices
Matrix Matrix::operator*(const Matrix &rhs) const {
    std::size_t N = data.size(); // Gets the size of the matrices we are working with
    Matrix result(N); // Creates a matrix of correct size to store the result

    for (std::size_t i = 0; i < N; i++) { // Iterates over the rows of this matrix
        for (std::size_t j = 0; j < N; j++) { // Iterates over the columns of the rhs matrix
            result.data[i][j] = 0; // Initializes the value at 0 in the resulting matrix
            for (std::size_t k = 0; k < N; k++) { // Iterates over the elements for the dot product
                result.data[i][j] += data[i][k] * rhs.data[k][j]; // Puts the dot product in the resultant matrix
            }
        }
    }
    return result; // Returns the resultant matrix
}

// Sets a given value in a matrix
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    data[i][j] = n;
}

// Returns a value from a given place in a matrix
int Matrix::get_value(std::size_t i, std::size_t j) const {
    return data[i][j];
}

// Returns the size of the matrix
int Matrix::get_size() const {
    return data.size();
}

// Returns the sum of the major diagonal
int Matrix::sum_diagonal_major() const {
    int sum = 0; // Initializes the sum at 0

    for (std::size_t i = 0; i < data.size(); i++) { // Iterates over the size of the matrix
        sum += data[i][i]; // Adds each element along the major diagonal to the sum
    }

    return sum; // Returns the sum
}

// Returns the sum of the minor diagonal
int Matrix::sum_diagonal_minor() const {
    int sum = 0; // Initializes the sum at 0

    for (std::size_t i = 0; i < data.size(); i++) { // Iterates over the size of the matrix
        sum += data[i][data.size() - i - 1]; // Adds each element along the minor diagonal to the sum
    }

    return sum; // Returns the sum
}

// Swaps two rows in a matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {

}

// Swaps two columns in a matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {

}

// Prints the matrix
void Matrix::print_matrix() const {
    std::size_t N = data.size(); // Gets the size of the matrices we are working with

    for (std::size_t i = 0; i <  N; i++) {
        for (std::size_t j = 0; j <  N; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}