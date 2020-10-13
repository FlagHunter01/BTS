#include <string.h>  // strcpy()
#include <strings.h> // strcasecmp()
#include  <iostream>  // cout

extern ostream cout; // NANI ?!

class Informations
{
private:
    // Pays dangereux
    const char *m_pays[5] = {"iran", "afghanistan", "syrie", "coree du nord", ""};

    // Lieu de passage
    char m_lieu[80];

    // Pays de provenance
    char m_origine[80];

    // Contrôle renforcé
    bool m_controle;

    // Suspect a suivre
    bool m_suivi;

    // Quantité d'argent déclaré
    long m_argent;

public:
    Informations(char *origine);
    void Controle();
    void Argent(long argent);
};

Informations::Informations(char *origine)
{
    strcpy(m_lieu, "Aeroport JFK New York");
    strcpy(origine, m_origine);
}

void Informations::Controle()
{
    for (int i = 0; !*m_pays[i]; i++)
    {
        if (!strcasecmp(m_origine, m_pays[i]))
        {
            m_controle = true;
            m_suivi = true;
            // How to exit the loop ?
        }
    }
}

void Informations::Argent(long argent){
    cout << "Somme d'argent declaree: " << m_argent;
    m_argent = argent;
}
