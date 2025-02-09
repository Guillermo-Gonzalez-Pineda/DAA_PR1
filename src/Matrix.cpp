#include "../include/Matrix.hpp"

void Matrix::fillRandom(int min_value, int max_value) {
  for (int i = 0; i < num_rows_; i++) {
    for (int j = 0; j < num_colums_; j++) {
      matrix_[i][j] = min_value + std::rand() % (max_value - min_value + 1);
    }
  }
}

void Matrix::resize(int new_rows, int new_cols) {
  num_rows_ = new_rows;
  num_colums_ = new_cols;
  matrix_.assign(num_rows_, std::vector<int>(num_colums_));
}

void Matrix::print() const {
  for (const auto& row : matrix_) {
    for (int value : row) {
      std::cout << value << "\t";
    }
    std::cout << "\n";
  }
}

void Matrix::print(std::ofstream& archivo) const {
  for (const auto& row : matrix_) {
    for (int value : row) {
      archivo << value << " ";
    }
    archivo << "\n";
  }
}