#ifndef MATRIX_H
#define MATRIX_H

#include "include.hpp"

class Matrix {
  public:
    // Constructores
    Matrix(int num_rows = 1, int num_colums = 1) : num_rows_(num_rows), num_colums_(num_colums), matrix_(num_rows, std::vector<int>(num_colums)) {}

    // Getters
    int getRows() const {return num_rows_; }
    int getCols() const {return num_colums_; }
    int getValue(int row, int col) const { return matrix_[row][col]; }

    // Setter
    void setValue(int row, int col, int value) { matrix_[row][col] = value; }
  
    // Redimensionar y Rellenar Matriz
    void fillRandom(int min_value = 0, int max_value = 99);
    void resize(int new_num_rows, int new_num_colums);

    // Imprimir Matriz
    void print() const;
    void print(std::ofstream& archivo) const;

  private:
    int num_colums_;
    int num_rows_; 
    std::vector<std::vector<int>> matrix_;
};


#endif 