
import java.util.Scanner;

public class basic2 {
    public static int HCF(int a,int b){
        if (a%b==0){
            return b;
        }
        return HCF(b,a%b);
    }
    public static void main(String[] args) {
        int a,b;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no 1:");
        a = sc.nextInt();
        System.out.println("Enter no 2:");
        b = sc.nextInt();
        System.out.println("The HCF of "+a+" and "+b+" is "+HCF(a,b));
        sc.close();
    }
}
