/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Ping;

/**
 *
 * @author apaas
 */
import java.io.*;
import java.net.*;
public class Client {
    public static void main(String[] args) throws Exception{
        Socket s = new Socket("localhost",6666);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(s.getOutputStream(),true);
        while(true){
            System.out.print("Enter Host Name:");
            String msg = in.readLine();
            out.println(msg);
            if(msg.equalsIgnoreCase("end")){
                System.out.println("End");
                break;
            }
        }
        in.close();
        out.close();
        s.close();
    }
}


