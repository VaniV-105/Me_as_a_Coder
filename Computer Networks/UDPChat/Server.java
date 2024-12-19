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
public class Server {
    public static void main(String[] args) throws Exception{
        int c_port = 4444 , s_port = 5555;
        DatagramSocket server = new DatagramSocket(s_port);
        byte[] buf = new byte[1024];
        DatagramPacket packet = new DatagramPacket(buf, buf.length);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        InetAddress addr = InetAddress.getLocalHost();
        System.out.println("Server started... Enter end to end:");
        while(true){
            server.receive(packet);
            String str = new String(packet.getData(),0,packet.getLength());
            buf = str.getBytes();
            if(str.equalsIgnoreCase("end")){
                System.out.println("End");
                break;
            }
            System.out.println("CLIENT:"+str);
            System.out.println("Enter Message:");
            buf = in.readLine().getBytes();
            server.send(new DatagramPacket(buf,buf.length,addr,c_port));
        }
        server.close();
    }
    
}
