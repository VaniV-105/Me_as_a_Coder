import java.util.Scanner;

public class basic5 {
    public static void printseries(int n){
        int a = 0;
        int b = 1;
        int c = 1;
        for(int i=0;i<n;i++){
            System.out.print(a+" ");
            a = b;
            b = c;
            c = a+b;
        }
    }
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no of terms:");
        n = sc.nextInt();
        printseries(n);
    }
}
