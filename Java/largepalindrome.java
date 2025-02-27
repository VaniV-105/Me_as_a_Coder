public class largepalindrome {
    static boolean palindrome(int no){
        int num = no,sum=0;
        while(num>0){
            int digit = num%10;
            sum = sum*10+digit;
            num = num/10;
        }
        return (no==sum);
    }
    public static void main(String[] args) {
        for(int i=1000;i>0;i--){
            if(palindrome(i)){
                System.out.println(i);
                break;
            }
        }
    }
}
