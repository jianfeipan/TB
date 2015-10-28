
package tpcorba.exo4;

import org.omg.CORBA.*;

import java.io.*;

import java.lang.*;

import java.util.*;
public Server {
	public static void main(String[] args){
		try {
			//init ORB
			ORB orb = ORB.init(args, null);

		    //init POA
			POA poa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));
			poa.the_POAManager().activate();
	
			gestionabonnesImpl agestionabonImpl = new gestionabonnesImpl(poa);
			org.omg.CORBA.Object gestion = poa.servant_to_reference(agestionabonImpl);

	
            String gestion_ref = orb.object_to_string(gestion);
            String refFile = "gestion.ref";
            PrintWriter out = new PrintWriter(new FileOutputStream(refFile));
            out.println(gestion_ref);
            out.close();

            System.out.println("Le serveur est pret ");

            orb.run();

            System.exit(0);
     	} catch (IOException ex) {
            System.err.println("Impossible d'ecrire la reference dans cpt.ref");
            System.exit(1);
        } catch (Exception e) {
            System.out.println(e);
        }
		
	}
	
}
