#include "../include/include.hpp"
#include "../include/Matrix.hpp"
#include "../include/IMatrixMultiplier.hpp"
#include "../include/RowWiseMultiplier.hpp"
#include "../include/ColumnWiseMultiplier.hpp"

void runMultiplication(IMatrixMultiplier* multiplier, 
    const Matrix& A, const Matrix& B, const std::string& methodName) {

  auto start = std::chrono::high_resolution_clock::now();
  Matrix result = multiplier->multiply(A, B);

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

  std::cout << "Tiempo de ejecución (" << methodName << "): " 
  << duration << " ms\n";
}

void printMenu() {
  std::cout << "Elige una opción:\n"
            << "  1. Establecer los Valores de las Matrices.\n"
            << "  2. Mostrar las Matrices.\n"
            << "  3. Calcular Producto con Recorrido por Filas.\n"
            << "  4. Calcular Producto con Recorrido por Columnas.\n"
            << "  5. Modo de Cálculo de Productos Automático.\n"
            << "  6. Salir...\n";
}


#include <fstream>
#include <iostream>
#include <chrono>

// Tu declaración de las clases debe ir aquí

void autoModeMultiplication(const std::string& nombre_fichero) {
  std::ofstream archivo_salida(nombre_fichero);

  if (!archivo_salida) {
    std::cerr << "Error al abrir el fichero de salida.\n";
    return;
  }

  RowWiseMultiplier rowMultiplier;
  ColumnWiseMultiplier columnMultiplier;

  int maxSize;
  std::cout << "Ingresa el tamaño máximo para las multiplicaciones: ";
  std::cin >> maxSize;

  // Preguntar si se desea imprimir el resultado de cada operación
  char imprimirResultado;
  std::cout << "¿Desea imprimir el resultado de cada operación? (y/n): ";
  std::cin >> imprimirResultado;

  // Encabezado del archivo
  archivo_salida << "Tamaño,RowWise (ms),ColumnWise (ms)\n";

  for (int i = 0; i <= maxSize; i += 50) {
    for (int j = 0; j <= maxSize; j += 50) {
      Matrix A(i, j, true);
      Matrix B(j, i, true);  // Para multiplicación válida (AxB)

      auto startRowWise = std::chrono::high_resolution_clock::now();
      Matrix resultRowWise = rowMultiplier.multiply(A, B);
      auto endRowWise = std::chrono::high_resolution_clock::now();
      auto durationRowWise =
          std::chrono::duration_cast<std::chrono::milliseconds>(endRowWise -
                                                                startRowWise)
              .count();

      auto startColumnWise = std::chrono::high_resolution_clock::now();
      Matrix resultColumnWise = columnMultiplier.multiply(A, B);
      auto endColumnWise = std::chrono::high_resolution_clock::now();
      auto durationColumnWise =
          std::chrono::duration_cast<std::chrono::milliseconds>(endColumnWise -
                                                                startColumnWise)
              .count();

      // Escribir resultados en el archivo
      if (imprimirResultado == 'y' || imprimirResultado == 'Y') {
        archivo_salida << "Resultado Matriz AxB Recorrido por Filas:\n";
        resultRowWise.print(archivo_salida);
        archivo_salida << "Tiempo de cálculo de Producto " << i << "x" << j
                       << ": " << durationRowWise << " ms\n\n";

        archivo_salida << "Resultado Matriz AxB Recorrido por Columnas:\n";
        resultColumnWise.print(archivo_salida);
        archivo_salida << "Tiempo de cálculo de Producto " << i << "x" << j
                       << ": " << durationColumnWise << " ms\n\n";
      } else {
        archivo_salida << "Tiempo de cálculo de Producto " << i << "x" << j
                       << " Recorrido por Filas: " << durationRowWise << " ms\n\n";
        archivo_salida << "Tiempo de cálculo de Producto " << i << "x" << j
                       << " Recorrido por Columnas: " << durationColumnWise << " ms\n\n";
      }
    }
  }

  archivo_salida.close();
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Uso: " << argv[0] << " <nombre_fichero_salida>" << std::endl;
    return 1;
  }

  std::string nombre_archivo = argv[1];

  int rows1 = 3, cols1 = 3;
  int cols2 = cols1;
  Matrix A(rows1, cols1, true);
  Matrix B(rows1, cols2, true);

  RowWiseMultiplier rowMultiplier;
  ColumnWiseMultiplier columnMultiplier;
  IMatrixMultiplier* selection_mode = nullptr;
  // IMatrixMultiplier* automatic_mode = nullptr;

  std::srand(static_cast<unsigned int>(std::time(0)));
  int semilla = std::rand() % 10;

  int option;
  do {
    printMenu();
    std::cout << "Selecciona una opción: ";
    std::cin >> option;

    switch (option) {
      case 1: {
        std::cout << "Ingresa el número de Filas de la Primera Matriz: ";
        std::cin >> rows1;
        std::cout << "Ingresa el número de Columnas de la Primera Matriz: ";
        std::cin >> cols1;
        std::cout << "Ingresa el número de Columnas de la Segunda Matriz: ";
        std::cin >> cols2;
        A.resize(rows1, cols1, semilla);
        B.resize(cols1, cols2);
        std::cout << "Matrices redimensionadas.\n\n" << std::endl;
        break;
      }

      case 2:
        std::cout << "Matriz A:\n";
        A.print();
        std::cout << "\nMatriz B:\n";
        B.print();
        std::cout << "\n" << std::endl;
        break;

      case 3: {
        selection_mode = &rowMultiplier;
        auto start = std::chrono::high_resolution_clock::now();
        selection_mode->multiply(A, B).print();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nTiempo de Operación: " << duration << " (ms).";
        std::cout << "\n" << std::endl;
        break;
      }

      case 4: {
        selection_mode = &columnMultiplier;
        auto start = std::chrono::high_resolution_clock::now();
        selection_mode->multiply(A, B).print();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nTiempo de Operación: " << duration << " (ms).";
        std::cout << "\n" << std::endl;
        break;
      }

      case 5:
        autoModeMultiplication(nombre_archivo);
        break;

      case 6:
        std::cout << "Saliendo...\n";
        break;
        
      default:
        std::cout << "Opción inválida. Intenta de nuevo.\n";
    }
  } while (option != 6);

  return 0;
}