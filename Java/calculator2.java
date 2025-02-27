import java.util.Scanner;

public class calculator {
    static void sum(int a,int b){
        System.out.println(a+" + "+b+" = "+(a+b));
    }
    static void diff(int a,int b){
        System.out.println(a+" - "+b+" = "+(a-b));
    }
    static void mul(int a,int b){
        System.out.println(a+" * "+b+" = "+(a*b));
    }
    static void div(int a,int b){
        if(b==0){
            System.out.println("Undefined");
        }
        else
        System.out.println(a+" / "+b+" = "+(a/b));
    }
    public static void main(String[] args) {
        System.out.println("Menu\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\nEnter your choice:");
        Scanner sc = new Scanner(System.in);
        int ch = sc.nextInt();
        System.out.println("Enter two numbers:");
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.close();
        switch(ch){
            case 1:
                sum(a,b);
                break;
            case 2:
                diff(a, b);
                break;
            case 3:
                mul(a, b);
                break;
            case 4:
                div(a,b);
                break;
            default:
                System.out.println("Wrong Choice.");
        }

    }
    
}
