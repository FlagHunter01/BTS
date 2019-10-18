<?php //login;pswd;EtatCivil;prenom;nom;tel;date;heure;CRLF
	setlocale(LC_TIME,"fr");
	$jour = strftime("%A %d %B %Y");
	$heure = date("H:i:s");
	$login_correct = false;
	$fp = fopen("login.csv","r"); // ouverture en lecture seule
	//echo "Nous sommes le ",$jour, ", il est ",$heure,'<br>';
	while (Feof($fp)==false) {
		$pers = fgets($fp);
		//echo $pers ;// copie toute la ligne jusqu'au CRLF
		$P = explode(";", $pers); // récupère les infos séparées par le ;
		$Login = $P[0] ; $pswd = $P[1] ; $Etatcivil = $P[2] ; $Prenom = $P[3] ; $Nom = $P[4] ; $Tel = $P[5] ; 
		$Date = $P[6] ; $Heure = $P[7] ; // récupération des paramètres de la ligne
		if(  $_GET['login']==$P[0]  ) { // =0, si les chaînes sont identiques, vérification du Login
			$login_correct = true; 
			echo "Login ok";  
			break; 
		}
		else{ 
			echo "Pas de login correspondant";
		}
	}
	
	// on peut quitter la boucle car on a trouvé le bon login 
	if($login_correct == true)  {
		echo "<br>",$Login, " est un login correct";
		if(  $_GET['pswd']==$P[1]  ) //  =0, si les chaînes sont identiques, vérification du Mot de passe
		{	echo "<br>Bonjour $Etatcivil $Prenom $Nom, bienvenu sur notre site réservé.";
			echo "<br>Vous vous êtes inscrit le $Date à $Heure",'<br>';
		}
	} 
		else echo "<br>Mot de passe incorrect";	
	//fclose( ... ); 
?>
