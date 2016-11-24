/*
TP2_MEDEV

COPPIN Jimmy
GOBINET Paul-Loup
MICHEL Louis
MOUGEOT Guillaume

le 24/11/2016
*/

#pragma once

#include "includes.h"

class Image{
private:
    int niveauDeGris;
    std::vector<std::vector<int> > tableau;
    
public:
    Image(){};
	Image(const Image& image): niveauDeGris(image.niveauDeGris), tableau(image.tableau){}
    //lecture d'un fichier pgm pour créer un objet image
    Image(std::ifstream* fichier);
    //création d'un fichier pgm à partir d'un objet image, on remplit fichier
    void ecrireImage(std::ofstream* fichier) const;
    
    Image seuillage(const int& seuil);
    Image difference(const Image& image) const;
    Image redimenssionnement(const int& h, const int& w);
};

