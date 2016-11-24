/*
TP2_MEDEV

COPPIN Jimmy
GOBINET Paul-Loup
MICHEL Louis
MOUGEOT Guillaume

le 24/11/2016
*/

#include "includes.h"
#include "Image.h"

int main() {
    std::ifstream lena_f("lena.pgm");
    if(!lena_f)
    {
        std::cerr<<"fichier introuvable";
    }
    else
    {
        Image lena_i(&lena_f);
		
		Image seuil_i(lena_i.seuillage(150));
		std::ofstream seuil_f("seuil 150.pgm");
		seuil_i.ecrireImage(&seuil_f);
		
		std::ofstream diff_f("difference.pgm");
        Image diff_i(seuil_i.difference(lena_i));
		diff_i.ecrireImage(&diff_f);
		
		std::ofstream redim("redim.pgm");
        (lena_i.redimenssionnement(120,120)).ecrireImage(&redim);
    }
    return 0;
}
