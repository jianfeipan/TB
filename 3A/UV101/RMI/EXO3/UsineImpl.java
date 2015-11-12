import java.io.*;
import java.net.*;
import java.rmi.*;
import java.rmi.server.*;
public class UsineImpl extends UnicastRemoteObject implements UsinePile{
	private final int portNumber;
	public UsineImpl(int port) throws java.rmi.RemoteException{
		portNumber = port;
	}

	public Pile creation_pile(String nom, int max_size) throws java.rmi.RemoteException{
		Pile aPil = new PileImpl(max_size);
		//MyHostName machine = new MyHostName();
        //String nomService = "//" + machine.QualifiedHost() + ":" + portNumber + "/"+nom;
		//Naming.rebind(nomService, aPil);
		return aPil;
	}

	public static void main(String args[]) throws IOException{
		if (args.length != 1)
		{
			System.out.println("Un arguments : port-rmiregistry ! ");
			System.exit(1);
		}	
		
		// Creation et installation du security manager
		//
		if (System.getSecurityManager() == null) 
			System.setSecurityManager(new RMISecurityManager());

		try 
		{
			UsineImpl usineImpl = new UsineImpl(Integer.parseInt(args[0]));
			MyHostName machine = new MyHostName();

            String nomService = "//" + machine.QualifiedHost() + ":" + args[0] + "/UsinePile";

			Naming.rebind(nomService, usineImpl);

			System.out.println("UsinePile enregistre : " + nomService);
		} 
		catch (RemoteException e) 
		{
			System.out.println("UsinePile err: " + e.getMessage());
			e.printStackTrace();
		}
	}
}
