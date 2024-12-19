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
public class Server {
    public static void main(String[] args) throws Exception{
        DatagramSocket server = new DatagramSocket(4444);
        byte[] buf = new byte[1024];
        DatagramPacket packet = new DatagramPacket(buf, buf.length);
        System.out.println("Server started");
        while(true){
            server.receive(packet);
            String msg = new String(packet.getData(),0,packet.getLength());
            if(msg.equalsIgnoreCase("terminate")){
                System.out.println("End");
                break;
                
            }
            System.out.println("Client:"+msg);
        }
    }
    
}
