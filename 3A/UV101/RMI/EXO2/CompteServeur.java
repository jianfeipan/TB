
import java.io.*;
import java.net.*;
import java.rmi.*;
import java.rmi.server.*;

public class CompteServeur extends UnicastRemoteObject implements Compte{
	private double sold = 0;
	
    public  CompteServeur() throws java.rmi.RemoteException{
	}

	public void debiter(double montant) throws java.rmi.RemoteException{
		if(0>montant || montant>sold){
			throw new java.rmi.RemoteException();
		}
		sold-= montant;
	}

	public void crediter(double montant) throws java.rmi.RemoteException{
		if(0>montant){
			throw new java.rmi.RemoteException();
		}
		sold+= montant;
	}

	public double lire_solde() throws java.rmi.RemoteException{
		return sold;
	}


	public static void main(String args[]){
     
		if (args.length != 1)
		{
			System.out.println("Deux arguments : port-rmiregistry! ");
			System.exit(1);
		}
      
		if (System.getSecurityManager() == null) 
			System.setSecurityManager(new RMISecurityManager());
 
		try 
		{


			CompteServeur acompteServeur = new CompteServeur();

			MyHostName machine = new MyHostName();

                        String nomService = "//" + machine.QualifiedHost() + ":" + args[0] + "/acompteServeur";

			Naming.rebind(nomService, acompteServeur);

			System.out.println("acompteServeur enregistre : " + nomService);
		} 
		catch (Exception e) 
		{
			System.out.println("acompteServeur err: " + e.getMessage());
			e.printStackTrace();
		}

	}
}
