import java.util.Arrays;
import java.util.Scanner;

public class Matrix {
    private int width;
    private int height;
    private double[][] data;

    // Default constructor which allow positive width and height of new matrix.
    // Otherwise, exception is thrown.
    public Matrix(int height, int width) throws Exception {
        if (width <= 0) throw new Exception("Width cannot be non positive");
        if (height <= 0) throw new Exception("Height cannot be non positive");

        this.width = width;
        this.height = height;
        data = new double[height][width];
    }

    // Returns identity matrix with size equal to given matrix.
    public static Matrix identity(Matrix matrix) throws Exception {
        if (matrix.width != matrix.height) throw new Exception("Matrix needs to be square");

        Matrix result = new Matrix(matrix.height, matrix.width);
        for (int iter = 0; iter < result.width; iter++) {
            result.data[iter][iter] = 1;
        }
        return result;
    }

    // Read information about new matrix from given scanner.
    public Matrix(Scanner input) throws Exception {
        this(input.nextInt(), input.nextInt());
        for (double[] row : this.data) {
            for (int iter = 0; iter < this.width; iter++) {
                row[iter] = input.nextDouble();
            }
        }
    }

    // Copy constructor which creates new matrix, which is independent of the old one.
    public Matrix(Matrix that) {
        this.width = that.width;
        this.height = that.height;

        this.data = new double[this.height][this.width];
        for (int row = 0; row < height; row++) {
            this.data[row] = Arrays.copyOf(that.data[row], that.width);
        }
    }

    // Method used to return whole Matrix as a string.
    @Override
    public String toString() {
        String result = new String();
        for (double[] row : this.data) {
            result += "( ";
            for (double value : row) {
                result += value + " ";
            }
            result += ")\n";
        }
        return result;
    }

    // Matrix multiplication using n^3 algorithm.
    public Matrix multiply(Matrix that) throws Exception {
        if (this.width != that.height) throw new Exception("Matrixes cannot be multiplied together, dimensions don't match");

        Matrix result = new Matrix(this.height, that.width);

        for (int row = 0; row < result.height; row++) {
            for (int column = 0; column < result.width; column++) {
                for (int iter = 0; iter < this.width; iter++) {
                    result.data[row][column] += this.data[row][iter] * that.data[iter][column];
                }
            }
        }
        return result;
    }

    // Matrix multiplication, which sets result to first multiplied matrix.
    public Matrix multiplyInPlace(Matrix that) throws Exception {
        Matrix result = this.multiply(that);
        this.data = result.data;
        this.width = result.width;
        this.height = result.height;
        return this;
    }

    // Multiply matrix by constant value, return result.
    public Matrix multiply(double value) {
        Matrix result = new Matrix(this);
        for (double[] row : result.data) {
            for (int iter = 0; iter < result.width; iter++) {
                row[iter] *= value;
            }
        }
        return result;
    }

    // Multiply matrix by constant, set result to matrix.
    public Matrix multiplyInPlace(double value) {
        for (double[] row : this.data) {
            for (int iter = 0; iter < this.width; iter++) {
                row[iter] *= value;
            }
        }
        return this;
    }

    // Add two matrixes, sets result to first.
    public Matrix addInPlace(Matrix that) throws Exception {
        if (this.width != that.width) throw new Exception("Width doesn't match during matrix addition");
        if (this.height != that.height) throw new Exception("Height doesn't match during matrix addition");

        for (int row = 0; row < this.height; row++) {
            for (int column = 0; column < this.width; column++) {
                this.data[row][column] += that.data[row][column];
            }
        }
        return this;
    }

    // Add two matrixes, returns result.
    public Matrix add(Matrix that) throws Exception {
        return new Matrix(this).addInPlace(that);
    }
}