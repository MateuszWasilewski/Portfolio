import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        try {
            Scanner input = new Scanner(System.in);
            int accuracy = input.nextInt();

            Matrix matrix = new Matrix(input);

            System.out.println(Exp.exp(matrix, accuracy));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
