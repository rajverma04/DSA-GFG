import java.util.Scanner;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // code here
        for(int i = 1; i <= n; i++) {
            String space = " ".repeat(n - i);
            String str = "* ".repeat(i);
            System.out.println(space + str);
        }
        
        for(int i = n; i >= 1; i--) {
            String space = " ".repeat(n - i);
            String str = "* ".repeat(i);
            System.out.println(space + str);
        }
    }
}