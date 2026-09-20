import java.util.Scanner;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // code here
        for(int i = n - 1; i >= 0; i--) {
            String str = "*".repeat(2 * i + 1);
            String space = " ".repeat(n - i - 1);
            System.out.println(space + str);
        }
    }
}