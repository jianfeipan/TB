
package tpcorba.exo3;

import org.omg.CORBA.*;
import java.lang.*;


public class compteImpl extends comptePOA{
	private int numero_compte;
	private String titulaire;
	private double solde;
	private int nbOperation;

	public compteImpl(String t, int num)
	{
		this.titulaire = t;
		this.numero_compte = num;
		this.solde = 0;
		this.nbOperation = 0;
	}
	
	public String titulaire(){
		return titulaire;
	}	

	public double solde(){
		return solde;
	}

	public int numero_compte(){
		return numero_compte;
	}


	public void nombre_operations(IntHolder nombre){
		nombre.value = new Integer(nbOperation); /////tres important!
	}
		
	public void debiter(double montant){
		solde -= montant;
		nbOperation++; 
	}
	
	public void crediter(double montant){
		solde += montant;
		nbOperation++; 
	}

	public void prelevement(double montant, compte destination){
		debiter(montant);
		destination.crediter(montant);
	}
	
}


