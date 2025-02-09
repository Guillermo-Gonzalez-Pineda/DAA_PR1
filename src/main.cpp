#include "../include/Matrix.hpp"
#include "../include/include.hpp"
#include "../include/RowWiseMultiplier.hpp"
#include "../include/ColumnWiseMultiplier.hpp"

int main() {
  std::srand(std::time(nullptr));

  Matrix A(1, 1);
  Matrix B(1, 1);

  A.fillRandom();
  B.fillRandom();

  A.print();
  B.print();

  int num_filas_a, num_cols_a, num_filas_b, num_cols_b;
  std::cout << "Establece el tamaño de la matriz a: ";
  std::cin >> num_filas_a;
  std::cin >> num_cols_a;
  std::cout << "Establece el tamaño de la matriz b: ";
  std::cin >> num_filas_b;
  std::cin >> num_cols_b;

  A.resize(num_filas_a, num_cols_a);
  B.resize(num_filas_b, num_cols_b);

  A.fillRandom();
  B.fillRandom();

  A.print();
  std::cout << std::endl;
  B.print();

  RowWiseMultiplier operacion_filas;
  ColumnWiseMultiplier operacion_columnas;
  
  Matrix result_row = operacion_filas.multiply(A, B);
  Matrix result_col = operacion_columnas.multiply(A, B);

  std::cout << "Multiplicación por filas: " << std::endl;
  result_row.print();
  std::cout << std::endl;
  std::cout << "Multiplicación por columnas: " << std::endl;
  result_col.print();

  return 0;
}