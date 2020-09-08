<!DOCTYPE html>
<head>
<title>Traitement</title>
<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<?php
	$host ="localhost:3306";
	$user ="root";
	$password ="";
	$dbname ="Transport_aérien";
	$connect = mysql_connect($host, $user, $password);
	if (!$connect)    
			die("<div class='bad'>Impossible de se connecter : " . mysql_error()."</div>");  
	else 	echo "<div class='good'>Connexion réussie</div>";
	$db_selected = mysql_select_db($dbname, $connect);
	if (!$db_selected) 
			die ("<div class='bad'>Impossible de sélectionner la bd : " . mysql_error()."</div>");  
	else 	echo "<div class='good'>Sélection BD réussie</div>";
	echo "<div class='info'>Requête : SELECT PLNUM,PLNOM FROM PILOTE :<br>";
	$reponse = mysql_query('SELECT PLNUM,PLNOM FROM PILOTE');
	echo "<table style='border: 1px solid black;'><tr>";
	$N = mysql_num_fields($reponse); // N = nombre de colonnes du tableau $reponse
	for ($i=0; $i<$N; $i++) printf("<th style='background: red'>%s</th>", mysql_field_name($reponse,$i));
	echo "</tr>";
	while ( $ligne = mysql_fetch_array( $reponse, MYSQL_NUM ))            
	{	
		echo "<tr>";
		for($n=0; $n<$N ; $n++)  printf("<td style='background: lightblue;'>%s</td>", $ligne[$n]);
		echo "</tr>";
	}
	echo "</table></div>";
	mysql_close($connect);  
?>
</body>
</html>


