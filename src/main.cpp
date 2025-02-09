#include "../include/Matrix.hpp"
#include "../include/include.hpp"
#include "../include/RowWiseMultiplier.hpp"
#include "../include/ColumnWiseMultiplier.hpp"

void autoProductOperarion(const std::string& nombre_fichero) {
  std::ofstream archivo_salida(nombre_fichero);

  if (!archivo_salida) {
    std::cerr << RED << "[ERROR] Error al Abrir el Archivo de Salida\n" << RESET;
    return;
  }

  RowWiseMultiplier rowMultiplier;
  ColumnWiseMultiplier columnMultiplier;

  int max_size;
  std::cout << "Ingrese el tamaño máximo para las multiplicaciones: ";
  std::cin >> max_size;

  // Preguntar si se desea Imprimir los resultados de cada Operación
  char imprimir_resultado;
  std::cout << "¿Desea Imprimir el Resultado de Cada Operación? (y/n): ";
  std::cin >> imprimir_resultado;

  // Encabezado del Archivo
  archivo_salida << "Tamaño Matriz, Tiempo Fila, Tiempo Columna\n";

  for (int i = 0; i < max_size; i += 50) {
    for (int j = 0; j < max_size; j += 50) {
      Matrix matrix_a(i, j);
      Matrix matrix_b(j, i); 
      matrix_a.fillRandom();
      matrix_b.fillRandom();

      auto start_row = std::chrono::high_resolution_clock::now();
      Matrix result_row = rowMultiplier.multiply(matrix_a, matrix_b);
      auto end_row = std::chrono::high_resolution_clock::now();
      auto duration_row = std::chrono::duration_cast<std::chrono::milliseconds>(end_row - start_row).count();

      auto start_column = std::chrono::high_resolution_clock::now();
      Matrix result_column = columnMultiplier.multiply(matrix_a, matrix_b);
      auto end_column = std::chrono::high_resolution_clock::now();
      auto duration_column = std::chrono::duration_cast<std::chrono::milliseconds>(end_column - start_column).count();

      // Escribir los Resultados en el Archivo
      if (imprimir_resultado == 'y' || imprimir_resultado == 'Y') {
        archivo_salida << "Resultado Matriz " << i << "x" << j << " Recorrido por Filas:\n";
        result_row.print(archivo_salida);
        archivo_salida << "Tiempo en Completar la Operación: " << duration_row << "(ms).\n\n";

        archivo_salida << "Resultado Matriz " << i << "x" << j << " Recorrido por Columnas:\n";
        result_column.print(archivo_salida);
        archivo_salida << "Tiempo en Completar la Operación: " << duration_column << "(ms).\n\n";
      } else {
        archivo_salida << i << "x" << j << ", " << duration_row << ", " << duration_column << "\n";
      }
    }
  }
  archivo_salida.close();

}

void clearScreen() {
  std::system("clear");
}

void printMenu() {
  clearScreen();
  std::cout << BOLD << CYAN << "╔══════════════════════════════════════╗\n";
  std::cout << "║        " << YELLOW << "MENU PRINCIPAL - MATRICES" << CYAN << "     ║\n";
  std::cout << "╠══════════════════════════════════════╣\n"; 
  std::cout << "║ " << GREEN  << "1. " << RESET << "Establecer nuevas dimensiones     ║\n";
  std::cout << "║ " << GREEN  << "2. " << RESET << "Mostrar Matrices                  ║\n";
  std::cout << "║ " << GREEN  << "3. " << RESET << "Producto por Filas                ║\n";
  std::cout << "║ " << GREEN  << "4. " << RESET << "Producto por Columnas             ║\n";
  std::cout << "║ " << GREEN  << "5. " << RESET << "Calculo Automático                ║\n";
  std::cout << "║ " << RED    << "6. " << RESET << "Salir del Programa                ║\n";
  std::cout << "╚══════════════════════════════════════╝\n";
  std::cout << BOLD << "Seleccione una opción: " << RESET;
}

int main(int argc, char* argv[]) {

  if (argc < 2) {
    std::cerr << RED << "[ERROR] Debe Ingresar el Nombre del Archivo de Salida.\n" << RESET;
    return 1;
  }

  std::string nombre_fichero = argv[1];

  std::srand(std::time(nullptr));
  Matrix matrix_a(1, 1);
  Matrix matrix_b(1, 1);

  IMatrixMultiplier* selection_mode = nullptr;

  int option, rows1, cols1, cols2;
  do {
    printMenu();
    std::cin >> option;
    
    switch (option) {
    case 1:
      std::cout << BLUE << "\n[INFO] Opción 1 seleccionada: Establecer nuevas dimensiones.\n" << RESET;
      std::cout << "Ingrese el Número de Filas de la Primera Matriz: ";
      std::cin >> rows1;
      std::cout << "Ingrese el Número de Columnas de la Primera Matriz: ";
      std::cin >> cols1;
      std::cout << "Ingresa el Número de Columnas de la Segunda Matriz: ";
      std::cin >> cols2;

      matrix_a.resize(rows1, cols1);
      matrix_a.fillRandom();

      matrix_b.resize(cols1, cols2);
      matrix_b.fillRandom();
      std::cout << BLUE << "[INFO] Matrices Redimensionadas.\n" << RESET;
      break;

    case 2:
      std::cout << YELLOW << "\nPrimera Matriz:\n" << RESET;
      matrix_a.print();

      std::cout << YELLOW << "\nSegunda Matriz:\n" << RESET;
      matrix_b.print();
      
      std::cout << "\nPresione ENTER para continuar...";
      std::cin.ignore(); 
      std::cin.get();    
      break;
    
    case 3: {
      RowWiseMultiplier rowMultiplier;
      Matrix matrix_result;
      selection_mode = &rowMultiplier;

      auto start = std::chrono::high_resolution_clock::now();
      matrix_result = selection_mode->multiply(matrix_a, matrix_b);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

      std::cout << YELLOW << "\nMatriz Resultado:\n" << RESET;
      matrix_result.print();
      std::cout << BLUE << "\nTiempo en Completar la Operación: " << duration << "(ms)." << RESET;

      std::cout << "\nPresione ENTER para continuar...";
      std::cin.ignore(); 
      std::cin.get();
    }
    break;

    case 4: {
      ColumnWiseMultiplier columnMultiplier;
      Matrix matrix_result;
      selection_mode = &columnMultiplier;

      auto start = std::chrono::high_resolution_clock::now();
      matrix_result = selection_mode->multiply(matrix_a, matrix_b);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

      std::cout << YELLOW << "\nMatriz Resultado:\n" << RESET;
      matrix_result.print();
      std::cout << BLUE << "\nTiempo en Completar la Operación: " << duration << "(ms)." << RESET;

      std::cout << "\nPresione ENTER para continuar...";
      std::cin.ignore(); 
      std::cin.get();
    }
    break;

    case 5:
      autoProductOperarion(nombre_fichero);
      std::cout << BLUE << "\n[INFO] Resultados Guardados en el Archivo" << nombre_fichero << ".\n" << RESET;
      break;

    case 6:
      std::cout << BLUE << "\n[INFO] Saliendo del Programa...\n" << RESET;
      break;

    default:
      std::cout << RED << "\n[ERROR] Opción Inválida. Intente de Nuevo.\n" << RESET;
      break;
    }

  } while (option != 6);

  return 0;
}