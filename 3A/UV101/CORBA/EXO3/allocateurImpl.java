package tpcorba.exo3;

import org.omg.CORBA.*;
import java.lang.*;
import org.omg.PortableServer.*;


public class allocateurImpl extends allocateurPOA{


	// Reference sur la POA
	//
	protected  POA poa_;


	public  allocateurImpl(POA poa){
		poa_=poa;
	}

	public void nouveau_compte(compteHolder cptHolder, String t, int num){
		compteImpl cpt = new compteImpl(t,num);
		try{
			org.omg.CORBA.Object cpt_ref = poa_.servant_to_reference(cpt);
			cptHolder.value = compteHelper.narrow(cpt_ref); ///////tres important !!!!!!!
		}catch(Exception e){
			System.out.println(e);
		}
	}


}
