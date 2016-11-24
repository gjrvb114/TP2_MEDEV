

#include "Image.h"
#include "math.h"
#include <vector>
Image::Image(){
    
}
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

~Image()
{
    
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
    Image Nouvelle = Image();
    int i;
    int j; 
    for (i=0; i<tableau.size();i++)
    {
        for(j=0;j<tableau[0].size();j++)
        {
            Nouvelle.tableau[i][j] = abs(tableau[i][j]- image.tableau[i][j]);
            
        }
    }
    
}

void Image::redimensionnement(const int& w const int& h)
{
    vector<vector<int>> tab ; 
    int i;
    int j;
    for (i=0; i<h; i++)
    {
        for (j=0;j<w;j++)
        {
            int niveau ;
            float XinOrigin = float(i)*float(tableau[0].size())/float(w);
            float YinOrigin = float(j)*float(tableau.size())/float(h);
            if(XinOrigin<float(int(XinOrigin))+0.5)
            {
                int XinSource = int(XinOrigin);            
            }
            else
            {
                int XinSource = int(XinOrigin)+1;
            }
            if(YinOrigin<float(int(YinOrigin))+0.5)
            {
                int YinSource = int(YinOrigin);            
            }
            else
            {
                int YinSource = int(YinOrigin)+1;
            }
            
            tab[i].push_back(tableau[XinSource][YinSource]);
        }
        
    }
    tableau = tab;
    
    
}