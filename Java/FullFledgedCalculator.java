import java.util.*;
public class FullFledgedCalculator{
    int a,b;
    FullFledgedCalculator(int a,int b){
        this.a=a;
        this.b=b;
    }
    int sum(){
        return (a+b);
    }
    int diff(){
        return (a-b);
    }
    int product(){
        return (a*b);
    }
    int quo(){
        return (a/b);
    }
    int rem(){
        return a%b;
    }
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter No 1:");
        int a = sc.nextInt();
        System.out.println("Enter No 2:");
        int b = sc.nextInt();
        FullFledgedCalculator f1 = new FullFledgedCalculator(a,b);
        System.out.println("Sum:"+f1.sum());
        System.out.println("Difference:"+f1.diff());
        System.out.println("Product:"+f1.product());
        System.out.println("Quotient:"+f1.quo());
        System.out.println("Remainder:"+f1.rem());

    }
}