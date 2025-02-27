
import java.util.Scanner;

public class whileloop {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        int sum =0;
        while(n>0){
            int d = n%10;
            sum = sum*10+d;
            n = n/10;
        }
        System.out.println(sum);
    }
}
