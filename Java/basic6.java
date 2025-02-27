import java.util.Scanner;

public class basic6 {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of terms:");
        int product=1;
        n = sc.nextInt();
        for(int i=1;i<=n;i++){
            if (i%2==1){
                product*=i;
            }
        }
        System.out.println("The product is "+product);
        sc.close();
    }
}
