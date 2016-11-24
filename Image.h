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
    vector<vector<int> > tableau;
    
public:
    Image(std::ifstream* fichier);
    
    void seuillage(const int& seuil);
    Image difference(const Image& image);
    void aggrandissement(const int& facteur);
    void retrecissement(const int& facteur);
};

