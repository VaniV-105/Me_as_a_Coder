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
public class ChatServer {
    public static void main(String[] args)throws Exception{
        ServerSocket ss = new ServerSocket(6666);
        System.out.println("Server Listening at port 6666");
        Socket cs = ss.accept();
        BufferedReader in = new BufferedReader(new InputStreamReader(cs.getInputStream()));
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(cs.getOutputStream(),true);
        String msg,reply;
        while(true){
            System.out.print("Server:");
            msg = input.readLine();
            out.println(msg);
            if(msg.equalsIgnoreCase("end")){
                System.out.println("End");
                break;
            }
            
            reply = in.readLine();
            if(reply.equalsIgnoreCase("end")){
                System.out.println("End");
                break;
            }
            System.out.println("Client"+reply);
        }
    }
    
}
