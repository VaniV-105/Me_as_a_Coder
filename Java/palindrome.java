import java.util.Scanner;

public class palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a no:");
        int no = sc.nextInt();
        int num = no,sum=0;
        while(num>0){
            int digit = num%10;
            sum = sum*10+digit;
            num = num/10;
        }
        if(sum==no){
            System.out.println(no+" is a palindrome number");
        }
        else{
            System.out.println(no+" is not a palindrome number");
        }
        sc.close();
    }
}
