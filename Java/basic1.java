import java.util.*;
public class basic1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter a number:");
        n = sc.nextInt();
        System.out.println("The number is "+n);
        int rev = 0;
        while (n>0){
            int d = n%10;
            rev = rev*10+d;
            n = n/10;
        }
        System.out.println("The reversed number is "+rev);
        sc.close();
    }
}