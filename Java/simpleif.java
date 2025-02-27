import java.util.Scanner;
public class simpleif{
    public static void main(String[] args) throws Exception {
        int no;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a no:");
        no = sc.nextInt();
        sc.close();
        if(no>0)
            System.out.println("Positive");        
    }
}