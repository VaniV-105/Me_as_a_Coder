import java.util.Scanner;
public class oddoreven {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a no:");
        int no = sc.nextInt();
        sc.close();
        if(no%2==0)
            System.out.println(no+" is an even no");
        else    
            System.out.println(no+" is an odd no");
    }    
}
