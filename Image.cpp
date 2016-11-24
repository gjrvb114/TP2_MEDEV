#include "Image.h"
#include <string>
#include "math.h"

Image::Image(std::ifstream* fichier)
{
    std::vector<int> vecteur_vide;
    int level;
    //on saute les deux premières lignes
    std::string str_courant;
    getline(*fichier, str_courant);
    getline(*fichier, str_courant);
    int n, m;
    *fichier >> n >> m >> niveauDeGris;
    for(int i=0; i<n ; i++)
    {
        tableau.push_back(vecteur_vide);
        for(int j=0 ; j<m ; j++)
        {
            *fichier >> level;
            tableau.back().push_back(level);
        }       
    }
}

void Image::seuillage(const int& seuil)
{
    int i; 
    int j;
    for (i=0;i<tableau.size();i++)
    {
        for (j=0 ;j<tableau[0].size() ; j++)
        {
            if (tableau[i][j] <= seuil)
            {
                tableau[i][j] = 0;
            }
            else 
            {
                tableau[i][j] = 255;
            }
        }
        
    }
    
}

Image Image::difference(const Image& image)
{
    Image Nouvelle = Image()
}

