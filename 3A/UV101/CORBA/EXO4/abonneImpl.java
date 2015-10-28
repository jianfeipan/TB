package tpcorba.exo4;

import org.omg.CORBA.*;
import java.lang.*;
public class abonneImpl extends abonnePOA{
	private int numero,
	private String nom_prenom;
    
	public abonneImpl(int numero, String nom_prenom){
		this.numero = numero;
		this.nom_prenom = nom_prenom;
	}	

	public int numero(){
		return numero;
	}
	
	public String nom_prenom(){
		return nom_prenom;
	}
}
