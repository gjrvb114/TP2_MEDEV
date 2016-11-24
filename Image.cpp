#include "Image.h"
#include "includes.h"

Image::Image(std::ifstream* fichier) {
    std::vector<int> vecteur_vide;
    int level;
    //on saute les deux premières lignes
    std::string str_courant;
    getline(*fichier, str_courant);
    getline(*fichier, str_courant);
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
    int XinSource, YinSource;
    float XinOrigin, YinOrigin;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            int niveau;
            XinOrigin = float(i) * float(tableau[0].size()) / float(w);
            YinOrigin = float(j) * float(tableau.size()) / float(h);
            if (XinOrigin<floor(XinOrigin) + 0.5) {
                XinSource = floor(XinOrigin);
            } else {
                XinSource = ceil(XinOrigin);
            }
            if (YinOrigin<floor(YinOrigin) + 0.5) {
                YinSource = floor(YinOrigin);
            } else {
                YinSource = ceil(YinOrigin);
            }

            tab[i].push_back(tableau[XinSource][YinSource]);
        }

    }
    tableau = tab;


}