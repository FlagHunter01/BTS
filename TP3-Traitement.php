<?PHP
	$host ="localhost:3306";
	$user ="root";
	$password ="";
	$dbname ="Transport_aérien";
	$connect = mysql_connect($host, $user, $password);
	if (!$connect)    
			die('Impossible de se connecter : ' . mysql_error());  
	else 	echo 'Connexion réussie<br/>';
	$db_selected = mysql_select_db($dbname, $connect);
	if (!$db_selected) 
			die ('Impossible de sélectionner la bd : ' . mysql_error());  
	else 	echo 'Sélection BD réussie<br/>';
	echo "Requête : SELECT PLNUM,PLNOM FROM PILOTE :<br>";
	$reponse = mysql_query('SELECT PLNUM,PLNOM FROM PILOTE');
	echo '<table style="border: 1px solid black;"><tr><th style="background: red">';
	$N = mysql_num_fields($reponse); // N = nombre de colonnes du tableau $reponse
	echo "</th></tr>";
	for ($i=0; $i<$N; $i++) printf("%s", mysql_field_name($reponse,$i));
	while ( $ligne = mysql_fetch_array( $reponse, MYSQL_NUM ))            
	{	
		echo '<tr><td style="background: lightblue;">';
		for($n=0; $n<$N ; $n++)  printf("%s", $ligne[$n]);
		echo "</td></tr>";
	}
	echo "</table>";
	mysql_close($connect); 
?>


