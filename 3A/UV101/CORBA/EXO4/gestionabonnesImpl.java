package tpcorba.exo4;

import org.omg.CORBA.*;
import java.lang.*;
public class gestionabonnesImpl extends gestionabonnesPOA{
	HashMap<int,abonneImpl> abonnes;

	public gestionabonnesImpl(POA poa_){
		abonnes = new HashMap<int,abonneImpl>();
	}
	void creation_abonne(int numero, 
						String nom, 
						String pernom, 
						AbonneHolder ref) throws dejaExistant{
			if(abonnes.containsKey(numero)){
				throw new dejaExistant();
			}else{
				abonneImpl anAbonneImpl = new abonneImpl(numero, nom+"_"+prenom);
				abonnes.put(numero,anAbonneImpl);
				try{
					org.omg.CORBA.Object  = poa_.servant_to_reference(anAbonneImpl);
					ref.value =  = abonneHelper.narrow(abon_ref); ///////tres important !!!!!!!
				}catch(Exception e){
					System.out.println(e);
				}				
			}		
	}

	void resilier_abonne(int numero) throws numeroInconnu{
		if(abonnes.containsKey(numero)){
			abonnes.remove(numero);
		}else{
			throw new numeroInconnu();
		}
	}

	void rechercher_abonne(int numero,
							AbonneHolder ref) throws numeroInconnu{
		if(abonnes.containsKey(numero)){
			try{
					org.omg.CORBA.Object  = poa_.servant_to_reference(abonnes.get(numero));
					ref.value =  = abonneHelper.narrow(abon_ref); ///////tres important !!!!!!!
			}catch(Exception e){
					System.out.println(e);
			}		
		}else{
			throw new numeroInconnu();
		}
	}
}
