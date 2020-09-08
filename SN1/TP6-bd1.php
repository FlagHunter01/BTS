<?PHP	// TP6_pdo
		// classe Cbdr et PDO, test fait en PHP v5.3.4
		// aidez-vous de pdo.php
		// Déclaration et remplissage d'un tableau associatif $config de dimension 1
	$config['host'] = "localhost:3306"; 
	$config['username'] = "root";
	$config['password'] = "";
	$config['database'] = "transport_aérien";
	
	$choix = $_GET['choix'] ;
	echo '<div style="color: blue; font-family: arial; font-size: 10px;">';
	$Obdr = new Cbdr($config);   // passage de paramètre à l'objet $Obdr lors de l'instantiation de la classe Cbdr
	$requette = $Obdr->formulaire($choix); // appel de la méthode formulaire
	$reponse = $Obdr->connexion($requette);
	$Obdr->tab_out($reponse, $requette);
	echo'</div>';
	
class Cbdr      {
	var $config;
	function Cbdr($conf)	{  // on peut aussi la nommer  : function __construct($conf)
		$this->config = $conf;  // affectation du contenu de la variable $conf à l'attribut $config
		echo "host     = ".$this->config['host']."<br>";
		echo "username = ".$this->config['username']."<br>";
		echo "password = ".$this->config['password']."<br>";
		echo "database = ".$this->config['database']."<br>";
	} 
	function formulaire($NumReq)	{
		switch($NumReq)  {  
			case 1: $req = 'SELECT PLPRENOM, PLNOM, VILLE, SALAIRE FROM pilote';    break;
			case 2: $req = 'SELECT DISTINCT PLPRENOM,PLNOM,SALAIRE FROM pilote WHERE SALAIRE>=18000 '; break;
			case 3: $req = 'SELECT DISTINCT VOLNUM,HEUREDEP FROM vol WHERE(HEUREDEP >= "09:00" && HEUREDEP <= "13:00")'; break;
			default:    echo "Entrer un choix : 1, 2 ou 3";    break;
		}				
		return $req; 
	}
	function connexion($req)	{
		$host = $this->config["host"];
		$utilisateur = $this->config["username"];
		$mot_passe = $this->config["password"];
		$database = $this->config["database"];
		
		$connect = new PDO('mysql:host='.$host.';dbname='.$database,$utilisateur,$mot_passe);
		if (!$connect)  echo 'Impossible de se connecter';   else echo 'Connexion réussie<br/>';
		$rep = $connect->query($req);  // réponse de query issue de PDO
		return $rep ; 
	}
	function tab_out($result, $req)    {
		printf("Requête : $req => réponse :<br>");
		$N = $result->columnCount();
		echo("<table border=0 cellpadding='1' cellspacing='1'><tr>");
		echo("<tr style='color: black;' bgcolor=#D0D0D0>");
		for($i = 0; $i < $N; $i++)
		{
				$a= $result->getColumnMeta($i);
				echo("<th><font face=arial size=1>".$a['name']."</th>");
				echo("</td></font>");
		}
		while( ($ligne = $result->fetch()) != false )
		{
			echo("<tr bgcolor='#E8E8E8'>");
			for($i = 0; $i < $N; $i++)		echo("<td><font face=arial color=maroon size=1>$ligne[$i]</font></td>");
			echo("</tr>");	
		}
		echo("</table>");
	}
}
?>


