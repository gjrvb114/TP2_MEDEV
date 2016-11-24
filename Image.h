#pragma once

#include "includes.h"

class Image{
private:
    int niveauDeGris;
    std::vector<std::vector<int> > tableau;
    
public:
    Image(){};
    //lecture d'un fichier pgm pour créer un objet image
    Image(std::ifstream* fichier);
    //création d'un fichier pgm à partir d'un objet image
    void ecrireImage(std::ofstream* fichier) const;
    
    void seuillage(const int& seuil);
    Image difference(const Image& image) const;
    void Image::redimensionnement(const int& w, const int& h);
};

