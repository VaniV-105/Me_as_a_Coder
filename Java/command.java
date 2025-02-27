public class command {
    public static void main(String[] args) throws Exception {
        if(args.length!=0){
            System.out.println("Student Names:\n");
            System.out.println("Student 1: "+args[0]);
            System.out.println("Student 2: "+args[1]);
        }
        else{
            System.out.println("No Arguments.");
        }
    }    
}
