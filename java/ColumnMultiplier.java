package java;
public class ColumnMultiplier implements InnerMatrixProduct {
  @Override
  public int[][] multiply(int[][] matrixA, int[][] matrixB) {
      int rowsA = matrixA.length;
      int colsA = matrixA[0].length;
      int colsB = matrixB[0].length;

      int[][] result = new int[rowsA][colsB];

      for (int j = 0; j < colsB; j++) {
          for (int i = 0; i < rowsA; i++) {
              for (int k = 0; k < colsA; k++) {
                  result[i][j] += matrixA[i][k] * matrixB[k][j];
              }
          }
      }
      return result;
  }
}
