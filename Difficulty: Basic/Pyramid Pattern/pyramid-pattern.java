import java.util.Scanner;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for(int i = 0; i < n; i++) {
            String space = " ".repeat(n - i - 1);
            String str = "*".repeat(2 * i + 1);
            System.out.println(space + str);    
        }

        sc.close();
    }
}