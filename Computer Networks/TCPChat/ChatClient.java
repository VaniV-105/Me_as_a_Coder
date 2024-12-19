/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package TCPChat;

/**
 *
 * @author apaas
 */
import java.io.*;
import java.net.*;
public class ChatClient {
    public static void main(String[] args)throws Exception{
        Socket s = new Socket("localhost",6666);
        BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(s.getOutputStream(),true);
        while(true){
            String msg = in.readLine();
            if(msg.equalsIgnoreCase("end")){
                System.out.println("End");
                break;
            }
            System.out.println("Server:"+msg);
            System.out.print("Client:");
            String reply = input.readLine();
            out.println(reply);
            if(reply.equalsIgnoreCase("end")){
                System.out.println("End");
                break;
            }
            else{
                
                out.flush();
            }
        }
    }
}
