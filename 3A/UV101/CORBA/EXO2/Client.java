package tpcorba.exo2;

import org.omg.CORBA.*;

import java.io.*;

import java.lang.*;

import java.util.*;


public class Client {
    public static void main(String[] args) throws IOException {

        ORB orb = ORB.init(args, null);
	char car;
	double donnee;
        if (args.length != 0) {
            System.err.println("pas de parametre svp");
            System.exit(1);
        }

        ////////////////////////////////////////////////////

        String ior = null;

        try {
            String ref = "calcul.ref";
            FileInputStream file = new FileInputStream(ref);
            BufferedReader in = new BufferedReader(new InputStreamReader(file));
            ior = in.readLine();
            file.close();
        } catch (IOException ex) {
            System.err.println("Impossible de lire fichier : `" +
                ex.getMessage() + "'");
            System.exit(1);
        }

        ////////////////////////////////////////////////////

        org.omg.CORBA.Object obj = orb.string_to_object(ior);

        if (obj == null) {
            System.err.println("Erreur sur string_to_object() ");
            throw new RuntimeException();
        }

        calcul calc = calculHelper.narrow(obj);

        if (calc == null) {
            System.err.println("Erreur sur narrow() ");
            throw new RuntimeException();
        }

        ////////////////////////////////////////////////////
        // Invocation du serveur
        ////////////////////////////////////////////////////
	
        try
                        {

				//*** Afficher l'etat initial de la 
				//*** memoire de la calculatrice
				System.out.println("l'etat initial :  "+calc.memoire());

				//*** Ajouter ici des operations sur la 
				//*** memoire de la calculatrice 
				System.out.println(" Que faire (ajouter, soustraire, multiplier, diviser ou mettreAZero ; saisir a,s,m,d ou z)?  ");
				car = (char) System.in.read();
				switch (car){
					
					case 'a': 
						System.out.println(" ajouter combien ??! ");
						donnee = (double) System.in.read();
						System.out.println(donnee);
						calc.ajouteMemoire(donnee);
						break;
					case 's': 
						System.out.println(" soustraire combien ??! ");
						donnee = (double) System.in.read();
						System.out.println(donnee);
						calc.soustraitMemoire(donnee);
						break;
					case 'm': 
						System.out.println(" multiplier combien ??! ");
						donnee = (double) System.in.read();
						System.out.println(donnee);
						calc.multiplieMemoire(donnee);
						break;
					case 'd': 
						System.out.println(" diviser combien ??! ");
						donnee = (double) System.in.read();
						System.out.println(donnee);
						calc.diviseMemoire(0);
						break;
					case 'z': 
						calc.miseAZero();
						break;
					default :
						break;
				}
				//*** Afficher l'etat final de la 
				//*** memoire de la calculatrice
				System.out.println("l'etat final : " + calc.memoire() );

				
				// Regarder le fonctionnement des 
				// exceptions
				//
				//calc.diviseMemoire(0);

                        }
                catch(divisionParZero ex)
                        {
                        System.err.println("Exception : division par zero" );
                        System.exit(1);
                        }

        System.exit(0);
    }
}
