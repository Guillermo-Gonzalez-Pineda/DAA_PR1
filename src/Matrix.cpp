#include "../include/Matrix.hpp"

Matrix::Matrix(int rows, int cols, int semilla, bool randomize) : rows(rows), cols(cols) {
  matrix_.resize(rows, std::vector<int>(cols, 0));
  if (randomize) {
    unsigned seed = static_cast<unsigned>(time(nullptr)) + semilla;
    std::srand(seed);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        matrix_[i][j] = std::rand() % 10;
      }
    }
  }
}

void Matrix::fillRandom(int semilla) {
  unsigned seed = static_cast<unsigned>(time(nullptr) + semilla);
  std::srand(seed);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix_[i][j] = std::rand() % 10;
    }
  }
}

void Matrix::resize(int new_rows, int new_cols, int semilla) {
  rows = new_rows;
  cols = new_cols;
  matrix_.assign(rows, std::vector<int>(cols));
  fillRandom(semilla);
}

void Matrix::print() const {
  for (const auto& row : matrix_) {
    for (int value : row) {
      std::cout << value << " ";
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