import java.util.Scanner;

public class HCF {
    static int hcf(int a,int b){
        if(a%b==0){
            return b;
        }
        return hcf(b%a,a);
    }
    public static void main(String[] args) {
        int a,b;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no 1:");
        a = sc.nextInt();
        System.out.println("Enter no 2:");
        b = sc.nextInt();
        sc.close();
        System.out.println("The HCF of "+a+" and "+b+" is "+ hcf(a,b));
    }
}
