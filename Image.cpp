

#include "Image.h"
#include "math.h"

void Image::Image(std::ifstream* fichier)
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
    Image Nouvelle = Image()
    
    
    
}