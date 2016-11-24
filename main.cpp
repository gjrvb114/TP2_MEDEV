#include "includes.h"
#include "Image.h"

int main() {
    std::ifstream fichier("lena.pgm");
    if(!fichier)
    {
        std::cerr<<"fichier introuvable";
    }
    else
    {
        Image image(&fichier);
        std::ofstream test("test.pgm");
        image.ecrireImage(&test);
    }
    return 0;
}
