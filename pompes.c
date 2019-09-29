#include <stdio.h>
#include <stdlib.h>


int read (int input, int mask)
{
	int x = input & mask;
	if (x == 0)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}

int main()
{
	int input;
	printf ("Entrer la variable recue par le programme en decimal. Voici la table des chiffres binaires: \n\n	000 - 0\n	001 - 1\n	010 - 2\n	011 - 3\n	100 - 4\n	101 - 5\n	110 - 6\n	111 - 7 \n\n ");
	scanf ("%i", &input);
	int v;
	printf ("Executer avec verbose ? 1 / 0 \n");
	scanf ("%i",&v);
	int maskb = 0b100;
	int maskm = 0b010;
	int maskh = 0b001;
	int P1 = 0;
	int P2 = 0;
	int a = 0;
	int t = 0;
	int b = read (input, maskb);
	int m = read (input, maskm);
	int h = read (input, maskh);
	
	if (input > 7)
	{
		if (v == 1)
		{
			printf ("Mauvais input, le programme risque de ne pas fonctionner correctement. \n Allumage du voyant 'Alerte' et fin du programme. \n");
		}
		a = 1;
	}
	else
	{
		if (m>b || h >b || h>m)
		{
			P1 = 1;
			a = 1;
			t = 1;
			if (v == 1)
			{
				printf ("Les detecteurs sont defectueux. \n - Allumage du voyant 'Alerte'. \n - Allumage preventif de la pompe no1. \n - Allumage du voyant 'Travail'. \n");
			}
		}
		else
		{
			if (b == 1)
			{
				P1 = 1;				
				t = 1;				
				if (v == 1)
				{
					printf ("Niveau d'eau bas detecte. \n");
					printf ("Allumage de la pompe no 1. \n");
					printf ("Allumage du voyant 'Travail'. \n");
				}
			
			if (m == 1)
			{
				P2 = 1;
				if (v == 1)
				{
					printf ("Niveau d'eau moyen detecte. \n");
					printf ("Allumage de la pompe no 2. \n");
				}
			}
			if (h == 1)
			{
				a = 1;				
				if (v == 1)
				{
					printf ("Niveau d'eau haut detecte. \n");
					printf ("Allumage du voyant alerte.\n");
				}
			}
		}
	}
	
	return 0;
}
