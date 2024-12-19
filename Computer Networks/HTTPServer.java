/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author apaas
 */
import java.io.*;
import java.net.*;
public class HTTPServer {
    static String sendPOST(String url) throws Exception{
        URL urlObj = new URL(url);
        HttpURLConnection con = (HttpURLConnection)urlObj.openConnection();
        con.setRequestMethod("POST");
        con.setRequestProperty("User-Agent", "Edge");
        con.setRequestProperty("Accept", "application/json");
        con.setRequestProperty("Content-Type", "application/json;utf-8");
        con.setDoOutput(true);
        String jsoninput = "{\"name\" : \"aashin\",\"subject\" :\"math\"}";
        DataOutputStream out = new DataOutputStream(con.getOutputStream());
        byte[] sendData = jsoninput.getBytes();
        out.write(sendData,0,sendData.length);
        return "";
        
    }
    public static void main(String[] args) throws Exception {
        
    }
}