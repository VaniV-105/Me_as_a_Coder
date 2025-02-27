public class productodd {
    static int product(){
        int pro = 1;
        for(int i=0;i<50;i++){
            if(i%2!=0){
                pro = pro*i;
            }
        }
        return pro;
    }
    public static void main(String[] args) {
        int a =product();
        System.out.println("Product: "+a);
    }
}
