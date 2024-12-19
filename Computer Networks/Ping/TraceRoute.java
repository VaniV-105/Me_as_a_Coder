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
import java.net.*;

public class TraceRoute {
    public static void main(String[] args) {
        final int MAX_HOPS = 30;     // Maximum number of hops
        final int TIMEOUT = 3000;    // Timeout in milliseconds
        final int PORT = 33434;      // Port used for the UDP packet
        
        try {
            // Input the target host
            System.out.print("Enter the target host (e.g., google.com): ");
            String targetHost = new java.util.Scanner(System.in).nextLine();
            InetAddress target = InetAddress.getByName(targetHost);
            
            System.out.println("Traceroute to " + targetHost + " (" + target.getHostAddress() + "):\n");

            boolean reached = false;

            for (int ttl = 1; ttl <= MAX_HOPS && !reached; ttl++) {
                // Create a socket for sending the packet
                DatagramSocket socket = new DatagramSocket();
                socket.setSoTimeout(TIMEOUT);

                // Set up the packet
                byte[] buffer = new byte[32]; // Dummy payload
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length, target, PORT);

                // Set TTL on the socket
                socket.setTrafficClass(ttl);

                // Measure time and send the packet
                long startTime = System.currentTimeMillis();
                socket.send(packet);

                // Attempt to receive a response
                try {
                    // Set up a buffer to receive the response
                    DatagramPacket responsePacket = new DatagramPacket(new byte[512], 512);
                    socket.receive(responsePacket);

                    // Calculate round-trip time
                    long roundTripTime = System.currentTimeMillis() - startTime;

                    // Get the IP address of the responding hop
                    InetAddress router = responsePacket.getAddress();

                    System.out.println(ttl + " \t" + router.getHostAddress() + " \t" + roundTripTime + " ms");

                    // Check if the target has been reached
                    if (router.equals(target)) {
                        reached = true;
                    }
                } catch (SocketTimeoutException e) {
                    System.out.println(ttl + " \t* \tRequest timed out");
                } finally {
                    socket.close();
                }
            }

            if (!reached) {
                System.out.println("Unable to reach the target within " + MAX_HOPS + " hops.");
            }
        } catch (UnknownHostException e) {
            System.out.println("Unable to resolve the target host.");
        } catch (IOException e) {
            System.out.println("An error occurred during traceroute.");
            e.printStackTrace();
        }
    }
}

