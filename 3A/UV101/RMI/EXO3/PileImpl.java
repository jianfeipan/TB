import java.io.*;
import java.net.*;
import java.rmi.*;
import java.rmi.server.*;
import java.util.Stack;
public class PileImpl implements Serializable, Pile{
	private final int max_size;
	private Stack<Integer> stack;
	public PileImpl(int max) throws java.rmi.RemoteException{
		max_size = max;
		stack = new Stack<Integer>();
	}

	public void empiler(int data) throws java.rmi.RemoteException{
		if(stack.size()>=max_size){
			throw new java.rmi.RemoteException();
		}
		stack.push(data);
	}

	public int haut() throws java.rmi.RemoteException{
		return stack.size();
	}

	public int depiler() throws java.rmi.RemoteException{
		if(stack.empty()){
			throw new java.rmi.RemoteException();
		}
		return stack.pop();
	}

	public void vider() throws java.rmi.RemoteException{
		stack = new Stack<Integer>();
	}
		
	public int lire_taille_courante() throws java.rmi.RemoteException{
		return stack.size();
	}

	public int lire_taille_max() throws java.rmi.RemoteException{
		return max_size;
	}
}
