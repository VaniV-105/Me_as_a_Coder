import java.util.Scanner;
public class reverseno{
    static int reverse(int n){
        int sum=0;
        while(n>0){
            int digit = n%10;
            sum = sum*10+digit;
            n = n/10;
        }
        return sum;
    }
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a no:");
        n = sc.nextInt();
        int result = reverse(n);
        System.out.println("The reversed no is "+result );
        sc.close();
    }
}