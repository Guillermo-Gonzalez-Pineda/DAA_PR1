#ifndef MATRIX_H
#define MATRIX_H

#include "include.hpp"
#include <ctime>
#include <cstdlib>

class Matrix {
  public:
    // Constructor
    Matrix(int rows, int cols, int semilla = 0, bool randomize = true);

    void resize(int new_rows, int new_columns, int semilla = 0);
    void fillRandom(int semilla = 0);

    // Getters
    int getRows() const {return rows; }
    int getCols() const {return cols; }
    int getValue(int row, int col) const { return matrix_[row][col]; }
    void setValue(int row, int col, int value) { matrix_[row][col] = value; }

    void print() const;
    void print(std::ofstream& archivo) const;

    std::vector<std::vector<int>> matrix_;
  private:
    int rows, cols;
};
 


#endif 