import java.io.*;

import java.net.*;


public class Contact {
     private String host;
     private String port;
    
     public Contact(String name){
	try {
		BufferedReader in = new BufferedReader(new FileReader(name));
		host = in.readLine();
		port = in.readLine();
	}catch(IOException e) {
        }

    }
    public String port() {
	return port;
    }
    public String host() {
	return host;
    }
}
