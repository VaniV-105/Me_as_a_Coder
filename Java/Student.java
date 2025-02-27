
import java.util.Scanner;

public class Student {
    int regno,phy,chem,maths;
    String name;
    public int total(){
        return (phy+chem+maths);
    }
    public double average(){
        return (total()/3);
    }
    public void grade(){
        double avg = average();
        if (avg>90){
            System.out.println("O Grade");
        }
        else if (avg>80){
            System.out.println("A+ Grade");
        }
        else if (avg>70){
            System.out.println("A Grade");
        }
        else if (avg>60){
            System.out.println("B Grade");
        }
        else if (avg>50){
            System.out.println("C Grade");
        }
        else{
            System.out.println("RA");
        }
    }
    public static void main(String[] args) {
        Student s1 = new Student();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Student Name:");
        s1.name = sc.nextLine();
        System.out.println("Enter Reg No:");
        s1.regno = sc.nextInt();
        System.out.println("Enter Marks in Phy,Chem and Maths:");
        s1.phy = sc.nextInt();
        s1.chem = sc.nextInt();
        s1.maths = sc.nextInt();
        sc.close();
        System.out.println("Total: "+s1.total());
        System.out.println("Average: "+s1.average());
        System.out.println("Grade: ");
        s1.grade();
    }
}
