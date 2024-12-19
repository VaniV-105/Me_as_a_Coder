/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Ping;

/**
 *
 * @author apaas
 */
import java.io.IOException;
import java.net.InetAddress;

public class PingClass {
    public static void main(String[] args) {
        // Replace with the host you want to ping
        String host = "google.com";
        
        // Timeout in milliseconds
        int timeout = 5000; // 5 seconds
        
        try {
            System.out.println("Pinging " + host + "...");
            
            // Get the InetAddress of the host
            InetAddress inet = InetAddress.getByName(host);
            
            // Check if the host is reachable
            boolean status = inet.isReachable(timeout);
            
            if (status) {
                System.out.println(host + " is reachable.");
                for(int i=0;i<5;i++){
                    System.out.println("Reply from "+inet+":bytes=32,TTL="+(57-i)+",time="+(15-i));
                }
            } else {
                System.out.println(host + " is not reachable.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred while trying to ping the host.");
            e.printStackTrace();
        }
    }
}
