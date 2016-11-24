/* 
 * File:   Image.h
 * Author: eleve
 *
 * Created on 24 novembre 2016, 09:40
 */

#pragma once

#include <vector>
#include <fstream>

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
    void aggrandissement(const int& facteur);
    void retrecissement(const int& facteur);
};

