import java.util.Scanner;
import java.lang.Math;
public class noofdigits {
    public static void main(String[] args) {
        int no;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a no:");
        no = sc.nextInt();
        double a=Math.log10(no);
        int b = (int)a;
        System.out.println("No of digits in "+no+" is "+ (b+1));
        sc.close();
    }
}
