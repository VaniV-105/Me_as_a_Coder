/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package UDPChat;

/**
 *
 * @author apaas
 */
import java.io.*;
import java.net.*;
public class Client {
    public static void main(String[] args) throws Exception{
        int c_port = 4444 , s_port = 5555;
        DatagramSocket client = new DatagramSocket(c_port);
        InetAddress addr = InetAddress.getByName("localhost");
        byte[] buf = new byte[1024];
        DatagramPacket packet = new DatagramPacket(buf, buf.length);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("CLient Started");
        while(true){
            System.out.print("Enter message:");
            String str = in.readLine();
            buf = str.getBytes();
            client.send(new DatagramPacket(buf, buf.length,addr,s_port));
            if(str.equalsIgnoreCase("end")){
                System.out.println("End");
                break;
            }
            client.receive(packet);
            String msg = new String(packet.getData(),0,packet.getLength());
            if(msg.equals("end")){
                System.out.println("end");
                break;
            }
            System.out.println("Server:"+msg);
        }
        client.close();
    }
    
    
}
