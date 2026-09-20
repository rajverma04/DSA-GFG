import java.util.Scanner;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for(int j = 0; j < n; j++) {
            for(int k = 1; k <= j + 1; k++) {
                System.out.print(k + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}