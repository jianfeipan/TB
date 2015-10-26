package tpcorba.exo3;

import org.omg.CORBA.*;

import java.io.*;
import java.lang.*;
import java.util.*;


public class Client {
    public static void main(String[] args) throws IOException {
        ////////////////////////////////////////////////////
        ORB orb = ORB.init(args, null);

        if(args.length!=0)
               {
               System.err.println("utilisation : pas de parametre ");
               System.exit(1);
               }

        ////////////////////////////////////////////////////
        String ior = null;

        try {
            String ref = "cpt.ref";
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

        allocateur alloc= allocateurHelper.narrow(obj);

        if (alloc == null) {
            System.err.println("Erreur sur narrow() ");
            throw new RuntimeException();
        }

        ////////////////////////////////////////////////////
        // Invocation du serveur
        ////////////////////////////////////////////////////

        // Creation de deux comptes
        //
        compteHolder Hcpt = new compteHolder();
        compte cpt1, cpt2;

        alloc.nouveau_compte(Hcpt,"toto",1);	
        cpt1=Hcpt.value;
        System.out.println("titulaire cpt1 = " + cpt1.titulaire());//**********************null pointor 

	alloc.nouveau_compte(Hcpt,"tata",2);
        cpt2=Hcpt.value;
	System.out.println("titulaire cpt2 = " + cpt2.titulaire());
	
        ////////////////////////////////////////////////////
        // Senario 1 cpt1 crediter 100, cpt2 crediter 200
        ////////////////////////////////////////////////////
	IntHolder intholder1= new IntHolder();
	IntHolder intholder2= new IntHolder();
	cpt1.crediter(100);
	cpt2.crediter(200);
	System.out.println("num c =   " + cpt1.numero_compte()+ "  |  " + cpt2.numero_compte());
	System.out.println("solde = " + cpt1.solde()+ " | " + cpt2.solde());
	cpt1.nombre_operations(intholder1);
	cpt2.nombre_operations(intholder2);
	System.out.println("nbOpe = " + intholder1.value+ " | " + intholder2.value);
	////////////////////////////////////////////////////
        // Senario 2 cpt1 prelevement 50 au cpt2
        ////////////////////////////////////////////////////
	cpt1.prelevement(50,cpt2);
	System.out.println("num c =   " + cpt1.numero_compte()+ "  |  " + cpt2.numero_compte());
	System.out.println("solde = " + cpt1.solde()+ " | " + cpt2.solde());
	cpt1.nombre_operations(intholder1);
	cpt2.nombre_operations(intholder2);
	System.out.println("nbOpe = " + intholder1.value+ " | " + intholder2.value);
        System.exit(0);
    }
}
