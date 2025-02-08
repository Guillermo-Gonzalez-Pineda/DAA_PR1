package java;
import java.util.Random; // Importamos la clase Random para generar numeros aleatorios
import java.util.Scanner;

public class MatrixProduct {
  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);

    System.out.println("Bienvenido al programa de producto de matrices.");

    if (args.length < 3) {
      System.out.println("Uso: java MatrixProduct <rowsA> <colsA> <colsB>");
      scanner.close();
      return;
    }

    int rowsA, colsA, colsB;
    try {
      rowsA = Integer.parseInt(args[0]);
      colsA = Integer.parseInt(args[1]);
      colsB = Integer.parseInt(args[2]);
    } catch (NumberFormatException e) {
      System.out.println("Por favor, ingresa números enteros válidos.");
      scanner.close();
      return;
    }

    int rowsB = colsA;

    // Generamos las matrices aleatorias con las dimensiones proporcionadas
    int[][] matrixA = generateRandomMatrix(rowsA, colsA);
    int[][] matrixB = generateRandomMatrix(rowsB, colsB);

    // Imprimir matrices
    System.out.println("Matriz A (" + rowsA + " x " + colsA + "):");
    printMatrix(matrixA);

    System.out.println("Matriz B (" + rowsB + " x " + colsB + "):");
    printMatrix(matrixB);

    // Selección de Estrategia
    System.out.print("Seleccione la estrategia de multiplicación (1 para filas, 2 para columnas): ");
    int choice = scanner.nextInt();
    MatrixContext context;

    if (choice == 1) {
      context = new MatrixContext(new RowMultiplier());
    } else {
      context = new MatrixContext(new ColumnMultiplier());
    }

    // Ejecutamos la multiplicacion
    int[][] result = context.executeStrategy(matrixA, matrixB);

    // Imprimimos resultado
    System.out.println("Resultado de la Multiplicación");
    printMatrix(result);

    scanner.close();
  }

  private static int[][] generateRandomMatrix(int rows, int cols) {
    Random rand = new Random();
    int[][] matrix = new int[rows][cols];
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        matrix[i][j] = rand.nextInt(10);
      }
    }
    return matrix;
  }

  private static void printMatrix(int[][] matrix) {
    for (int[] row : matrix) {
      for (int val : row) {
        System.out.print(val + "\t");
      }
      System.out.println();
    }
  }
}