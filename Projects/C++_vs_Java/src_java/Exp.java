public class Exp {
    
    // Calculates function exp(value) using series expantion.
    // Calculations are performed up to a given index.
    public static double exp(double value, int accuracy) {
        double factor = 1;
        double result = factor;

        for (double iter = 1; iter <= accuracy; iter++) {
            factor = factor * value / iter;
            result += factor;
        }
        return result;
    }

    // Calculates function exp(matrix) using series expantion.
    // Calculations are performed up to a given index.
    public static Matrix exp(Matrix matrix, int accuracy) throws Exception {
        Matrix factor = Matrix.identity(matrix);
        Matrix result = new Matrix(factor);

        for (double iter = 1; iter <= accuracy; iter++) {
            factor.multiplyInPlace(matrix);
            factor.multiplyInPlace(1 / iter);
            result.addInPlace(factor);
        }
        return result;
    }
}
