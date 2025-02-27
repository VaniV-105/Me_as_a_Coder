public class basic3 {
    public static void main(String[] args) {
        int c=0;
        for (int i=20;i<80;i++){
            if (i%3==0)
                c+=1;
        }
        System.out.print("The no of multiples of 3 between 20 and 80 is "+c);
    }
}
