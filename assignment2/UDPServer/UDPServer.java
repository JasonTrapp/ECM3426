import java.io.*;
import java.net.*;

public class UDPServer{
	public static void main(String[] args){
		DatagramSocket aSocket = null;
		try{
			aSocket = new DatagramSocket(6789);
			byte[] buffer = new byte[100];

			while(true){
				DatagramPacket request = new DatagramPacket(buffer, buffer.length);
				aSocket.receive(request);
				String message = new String(request.getData());
				System.out.println(message);
				DatagramPacket reply = new DatagramPacket(request.getData(), request.getLength(), request.getAddress(), request.getPort());
				aSocket.send(reply);
			}
		}catch(SocketException e){
			System.out.println("Socket: " + e.getMessage());
		}catch(IOException e){
			System.out.println("IO: " + e.getMessage());
		}finally{
			if(aSocket != null){
				aSocket.close();
			}
		}
	}
}
