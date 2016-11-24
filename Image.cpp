/*
TP2_MEDEV

COPPIN Jimmy
GOBINET Paul-Loup
MICHEL Louis
MOUGEOT Guillaume

le 24/11/2016
*/

#include "Image.h"
#include "includes.h"

Image::Image(std::ifstream* fichier) {
    std::vector<int> vecteur_vide;
	//contiendra le niveau de gris d'un pixel
    int level;
    //on saute les deux premières lignes
    std::string str_courant;
    std::getline(*fichier, str_courant);
    std::getline(*fichier, str_courant);
	//On stocke les dimensions de l'image et le niveau de gris maximal
    int n, m;
    *fichier >> n >> m >> niveauDeGris;
	
	//On parcourt le fichier en remplissant tableau
    for (int i = 0; i < n; i++) {
        tableau.push_back(vecteur_vide);
        for (int j = 0; j < m; j++) {
            *fichier >> level;
            tableau.back().push_back(level);
        }
    }
}

//renvoie le nombre de chiffre d'un entier
int nombreDeChiffre(int ndg)
{
    int out(1);
    while(ndg>10)
    {
        ndg/=10;
        out++;
    }
    return out;
}

void Image::ecrireImage(std::ofstream* fichier) const
{
	//on remplit l'entête du fichier
    *fichier << "P2\n#\n";
    *fichier << tableau.size() << " " << tableau[0].size() << '\n';
    *fichier << niveauDeGris << '\n';
	//contient le nombre de niveau de gris par ligne pour ne pas dépasser 70 caractères
    int nb_par_ligne = 70/(1+nombreDeChiffre(niveauDeGris));
	//compteur du nombre de niveau de gris écris sur la ligne courante
    int k(0);
	//on parcourt tableau pour écrire dans fichier
    for(int i=0 ; i<tableau.size() ; i++)
    {
        for(int j=0 ; j<tableau[0].size() ; j++)
        {
            *fichier << tableau[i][j];
			//Si on est au bout de la ligne, on la saute
            if(k==nb_par_ligne-1)
            {
                *fichier << '\n';
                k=0;
            }
			//Sinon on met un espace
            else
            {
                *fichier << " ";
            }
            k++;
        }
    }
}

Image Image::seuillage(const int& seuil) {
	Image image(*this);
    for (int i = 0; i < tableau.size(); i++) {
        for (int j = 0; j < tableau[0].size(); j++) {
            if (tableau[i][j] <= seuil) {
                image.tableau[i][j] = 0;
            } else {
                image.tableau[i][j] = niveauDeGris;
            }
        }
    }
	return image;
}

Image Image::difference(const Image& image) const {
	Image diff(*this);
	if(tableau.size()!=image.tableau.size() || tableau[0].size()!=image.tableau[0].size())
    {
		std::cerr<< "dimensions incompatibles";
	}
	else
	{
		for (int i = 0; i < tableau.size(); i++) {
			for (int j = 0; j < tableau[0].size(); j++) {
				diff.tableau[i][j] = std::max(tableau[i][j] - image.tableau[i][j], 0);
			}
		}
	}
	return diff;
}

int entierPlusProche(const float& reel)
{
	int out;
	if (reel-floor(reel) < 0.5) {
		out = (int)floor(reel);
	} else {
		out = (int)ceil(reel);
	}
	return out;
}

Image Image::redimenssionnement(const int& h, const int& w) {
	Image image;
	image.niveauDeGris=niveauDeGris;

    std::vector<int> vectorVide ;
	
	//contient les indices du pixel correspondant dans l'image source
    int XinSource, YinSource;
	//contient la position flottante du pixel dans l'image source
    float XinOrigin, YinOrigin;
	//dimensions d'origine
	int wSource = tableau[0].size();
	int hSource = tableau.size();
	
    for (int i = 0; i < h; i++)
    {
        image.tableau.push_back(vectorVide);
        for (int j = 0; j < w; j++)
		{
            XinOrigin = (float)i * ((float)hSource-1.0f) / ((float)h-1.0f);
            YinOrigin = (float)j * ((float)wSource-1.0f) / ((float)w-1.0f);
            XinSource = entierPlusProche(XinOrigin);
            YinSource = entierPlusProche(YinOrigin);
            image.tableau.back().push_back(tableau[XinSource][YinSource]);
        }
    }
	return image;
}
