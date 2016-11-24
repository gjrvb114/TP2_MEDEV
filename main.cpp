#include "includes.h"
#include "Image.h"

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
