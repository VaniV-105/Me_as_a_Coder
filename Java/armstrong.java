import java.util.*;
public class armstrong{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number:");
        int a = sc.nextInt();
        sc.close();
        int num=a,sum=0;
        while(num>0){
            int d = num%10;
            sum+=d*d*d;
            num = num/10;   
        }
        if(a==sum){
            System.out.println("Armstrong");
        }
        else{
            System.out.println("Not Armstrong");
        }
    }
}