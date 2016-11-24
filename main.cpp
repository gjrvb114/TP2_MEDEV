/* 
 * File:   main.cpp
 * Author: eleve
 *
 * Created on 24 novembre 2016, 08:03
 */

#include <iostream>
#include "Image.h"

using namespace std;

int main() {
    ifstream fichier("lena.pgm");
    if(!fichier)
    {
        std::cerr<<"fichier introuvable";
    }
    else
    {
        Image image(&fichier);
    }
    return 0;
}
