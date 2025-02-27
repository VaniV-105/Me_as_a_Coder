public class basic4 {
    public static boolean ispalindrome(int n){
        int a = n;
        int sum = 0;
        while (a>0){
            int d = a%10;
            sum = sum*10+d;
            a = a/10;
        }
        return (sum==n);
    }
    public static void main(String[] args) {
        for(int i = 1000;i>0;i--){
            if(ispalindrome(i)){
                System.out.println("The largest palindrome less than 1000 is "+i);
                break;
            }
        }
    }
}
