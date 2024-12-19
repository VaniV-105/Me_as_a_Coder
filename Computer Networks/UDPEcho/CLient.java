/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package UDPEcho;

/**
 *
 * @author apaas
 */
import java.io.*;
import java.net.*;
public class CLient {
    public static void main(String[] args) throws Exception{
        DatagramSocket client = new DatagramSocket();
        InetAddress addr = InetAddress.getByName("localhost");
        byte[] buf;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Client started:Enter 'terminate' to end connection:");
        while(true){
            System.out.print("Client:");
            String str = in.readLine();
            buf = str.getBytes();
            client.send(new DatagramPacket(buf, str.length(),addr,4444));
            if(str.equals("terminate")){
                System.out.println("Terminated");
                break;
            }
            
        }
        
    }
    
}
