import java.io.*;
public class runtimeinput {
    public static void main(String[] args) {
        String name,place;
        int id;
        DataInputStream ds = new DataInputStream(System.in);
        System.out.println("Enter Student ID:");
        String sid = ds.readLine();
        id= Integer.parseInt(sid);
        System.out.println("Enter Student Name:");
        name = ds.readLine();
        System.out.println("Enter Student Place:");
        place = ds.readLine();
        System.out.println("Student ID:"+id+"\nStudent Name:"+name+"\nStudent Place:"+place);
    }    
}
