import java.util.*;
public class Calculator{
    int a,b;
    Calculator(int a,int b){
        this.a = a;
        this.b = b;
    }
    void sum(){
        System.out.println("Sum of "+a+" and "+b+" is "+(a+b));
    }
    void diff(){
        System.out.println("Diff of "+a+" and "+b+" is "+(a-b));
    }
    void product(){
        System.out.println("Product of "+a+" and "+b+" is "+(a*b));
    }
    void quo(){
        System.out.println("Quotient of "+a+" and "+b+" is "+(a/b));
    }
    public static void main(String[] args){
        Calculator c1 = new Calculator(5,2);
        c1.sum();
        c1.diff();
        c1.product();
        c1.quo();
    }
}
