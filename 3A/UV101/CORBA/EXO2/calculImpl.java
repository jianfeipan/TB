

package tpcorba.exo2;

import org.omg.CORBA.*;
import java.lang.*;


public class calculImpl extends calculPOA
	{


	private	double contenu;


	public calculImpl()
		{
		contenu=0;
		}


	public double memoire()
		{
		return contenu;
		}



	public void ajouteMemoire(double donnee){
		contenu += donnee;	
	}

	public void soustraitMemoire(double donnee){
		contenu -= donnee;	
	}

	public void multiplieMemoire(double donnee){
		contenu *= donnee;		
	}

	public void miseAZero(){
		contenu = 0;
	}



	public void diviseMemoire(double valeur) 
		throws divisionParZero
		{
		if(valeur==0)
			throw new divisionParZero();

		contenu=contenu/valeur;
		}


        public void incrementer(IntHolder data)
                {
                System.out.println("Invocation d'incrementer()");

                data.value=data.value+1;
                }


        public void decrementer(IntHolder data)
                {
                System.out.println("Invocation de decrementer()");

                data.value=data.value-1;
                }




	}
