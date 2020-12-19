#include <iostream>

using namespace std;

struct Imagem {
    int **pixels; 
    int nrows; 
    int ncolumns;
};

void leImagem(Imagem &im) {
    char tipo[3];
    
    cin >> tipo;

    cin >> im.ncolumns >> im.nrows;
    
    im.pixels = new int*[im.nrows];

    for(int i = 0; i < im.nrows; i++){
        im.pixels[i] = new int[im.ncolumns];
    }
    
    for(int i = 0; i < im.nrows; i++) {
        for(int j = 0; j < im.ncolumns; j++) {
            cin >> im.pixels[i][j];
        }  
    }

}

void inverteCorImagem(Imagem &im) {
    for(int i = 0; i < im.nrows; i++) {
        for(int j = 0; j < im.ncolumns; j++) {
            if(im.pixels[i][j] == 0) {
                im.pixels[i][j] = 1;
            } else {
                im.pixels[i][j] = 0;
            }
        }  
    }
}

void imprimeImagem(Imagem im) {
    cout << "P1" << endl;

    cout << im.ncolumns << " " << im.nrows << endl;

    for(int i = 0; i < im.nrows; i++) {
        for(int j = 0; j < im.ncolumns; j++) {
            cout << im.pixels[i][j] << " ";
        }
        cout << endl;
    }

}

void deletaImagem(Imagem &im) {
    for(int i = 0; i < im.nrows; i++){
        delete im.pixels[i];
    }
    
    delete []im.pixels;
}

int main() {
    Imagem im;
    
    leImagem(im);
    inverteCorImagem(im);
    imprimeImagem(im);
    deletaImagem(im);

    return 0;
}