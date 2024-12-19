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
public class Server {
    public static void main(String[] args) throws Exception{
        ServerSocket ss = new ServerSocket(6666);
        System.out.println("Server Listening at port 6666");
        Socket cs = ss.accept();
        BufferedReader in = new BufferedReader(new InputStreamReader(cs.getInputStream()));
        while(true){
            String msg = in.readLine();
            if(msg.equalsIgnoreCase("end")){
                System.out.println("End");
                break;
            }
            int timeout = 5000;
            System.out.println("Pinging " + msg + "...");
            
            // Get the InetAddress of the host
            InetAddress inet = InetAddress.getByName(msg);
            
            // Check if the host is reachable
            boolean status = inet.isReachable(timeout);
            
            if (status) {
                System.out.println(msg + " is reachable.");
                for(int i=0;i<5;i++){
                    System.out.println("Reply from "+inet+":bytes=32,TTL="+(57-i)+",time="+(15-i));
                }
            } else {
                System.out.println(msg + " is not reachable.");
            }
        }
        in.close();
        ss.close();
        cs.close();
    }
}
