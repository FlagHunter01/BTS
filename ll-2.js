function Mail() 
{
	m = document.Verif.email.value; 
	arobase = 0; 
	point = 0;
	if(m =='') 
	{
		alert("Le mail est obligatoire."); 
		return false; 
	}
	for (j=0; j< m.length; j++) 
	{
		if (m.charAt(j) == '@') 
		{
			arobase++;
		}
	}
	if (arobase!=1) 
	{ 
		alert("Saisir une adresse valide. (@)"); 
		return false; 
	}
	for (i=0; i < m.length; i++)
	{
		if (m.charAt(i)== '.')  
		{
			point++;
		}
	}
	if (point ==  0) 
	{ 
		alert("Saisir une adresse valide.(.)"); 
		return false; 
	}
	return true;
}

function Password()
{
	p = document.Verif.pswd.value;
	if (p.length < 6) 
	{ 
		alert("votre mot de passe a moins de 6 caractères"); 
		return false; 
	}
	for ( var k=0; k<p.length; k++ )  
	{ 
		var c = p.charAt(k); 
		if (c=='_' || c=='-' || c=='!' || c=='#' || c=='%' || c=='$')  
		{
			return true; 
		}
	}
	alert("Il faut au moins un des caractères suivants : _-!#%$"); 
	return false; 

}

function Verification()
{	
	if(Mail() == false) 
	{
		return false; // erreur Mail
	}
	if(Password() == false) 
	{
		return false; // erreur Password
	}
	return true; 
}

