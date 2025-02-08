package java;
public class MatrixContext {
  private InnerMatrixProduct strategy;

  public MatrixContext(InnerMatrixProduct multiplier) {
      this.strategy = multiplier;
  }

  public int[][] executeStrategy(int[][] matrixA, int[][] matrixB) {
      return strategy.multiply(matrixA, matrixB);
  }

  public void setStrategy(InnerMatrixProduct multiplier) {
      this.strategy = multiplier;
  }
}
