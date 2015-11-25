
public interface Pile extends java.rmi.Remote 
{

	void empiler(int data)
		throws java.rmi.RemoteException;

	int haut()
		throws java.rmi.RemoteException;

	int depiler()
		throws java.rmi.RemoteException;

	void vider()
		throws java.rmi.RemoteException;
		
	int lire_taille_courante()
		throws java.rmi.RemoteException;

	int lire_taille_max()
		throws java.rmi.RemoteException;
};


