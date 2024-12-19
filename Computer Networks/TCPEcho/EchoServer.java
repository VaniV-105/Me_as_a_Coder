/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package TCPEcho;

/**
 *
 * @author apaas
 */
import java.io.*;
import java.net.*;
public class EchoServer {
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
            System.out.println("Client:"+msg);
        }
        in.close();
        ss.close();
        cs.close();
    }
}
