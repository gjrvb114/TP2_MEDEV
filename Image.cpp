

#include "Image.h"
#include "math.h"
#include <vector>
Image::Image(){
    
}
Image::Image(std::ifstream* fichier)
{
    
    
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