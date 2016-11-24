#include "Image.h"
#include "includes.h"

Image::Image(std::ifstream* fichier) {
    std::vector<int> vecteur_vide;
    int level;
    //on saute les deux premières lignes
    std::string str_courant;
    std::getline(*fichier, str_courant);
    std::getline(*fichier, str_courant);
    int n, m;
    *fichier >> n >> m >> niveauDeGris;
    for (int i = 0; i < n; i++) {
        tableau.push_back(vecteur_vide);
        for (int j = 0; j < m; j++) {
            *fichier >> level;
            tableau.back().push_back(level);
        }
    }
}

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
    *fichier << "P2\n#\n";
    *fichier << tableau.size() << " " << tableau[0].size() << '\n';
    *fichier << niveauDeGris << '\n';
    int nb_par_ligne = 70/(1+nombreDeChiffre(niveauDeGris));
    int k(0);
    for(int i=0 ; i<tableau.size() ; i++)
    {
        for(int j=0 ; j<tableau[0].size() ; j++)
        {
            *fichier << tableau[i][j];
            if(k==nb_par_ligne-1)
            {
                *fichier << '\n';
                k=0;
            }
            else
            {
                *fichier << " ";
            }
            k++;
        }
    }
}

void Image::seuillage(const int& seuil) {
    int i;
    int j;
    for (i = 0; i < tableau.size(); i++) {
        for (j = 0; j < tableau[0].size(); j++) {
            if (tableau[i][j] <= seuil) {
                tableau[i][j] = 0;
            } else {
                tableau[i][j] = 255;
            }
        }
    }
}

Image Image::difference(const Image& image) const {
    Image Nouvelle = Image();
    int i;
    int j;
    for (i = 0; i < tableau.size(); i++) {
        for (j = 0; j < tableau[0].size(); j++) {
            Nouvelle.tableau[i][j] = abs(tableau[i][j] - image.tableau[i][j]);
        }
    }
}

void Image::redimensionnement(const int& w, const int& h) {
    std::vector<std::vector<int> > tab;
    int i, j;
    std::vector<int> New ;
    int XinSource, YinSource;
    float XinOrigin, YinOrigin;
    for (i = 0; i < h; i++)
        {
            tab.push_back(New);
        for (j = 0; j < w; j++) {
            XinOrigin = float(i) * float(tableau[0].size()) / float(w);
            YinOrigin = float(j) * float(tableau.size()) / float(h);
            if (XinOrigin<floor(XinOrigin) + 0.5) {
                XinSource = std::max(floor(XinOrigin),double(0));
            } else {
                XinSource = std::min(ceil(XinOrigin),double(tableau[0].size()));
            }
            if (YinOrigin<floor(YinOrigin) + 0.5) {
                YinSource = std::max(floor(YinOrigin),double(0));
            } else {
                YinSource = std::min(ceil(YinOrigin),double(tableau.size()));
            }
            tab[i].push_back(tableau[XinSource][YinSource]);
        }
    }
    tableau = tab;
}
