#include <iostream>
#include <cmath>

using namespace std;

class Ponto {
    private:
        int x, y;

    public:
        void setX(int coordenadaX) {
            x = coordenadaX;
        }

        void setY(int coordenadaY) {
            y = coordenadaY;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        double distancia(int coordenadaX, int coordenadaY) {
            return sqrt(pow(coordenadaX - x, 2) + pow(coordenadaY - y, 2));
        }

        void imprime() {
            cout << "(" << x << "," << y << ")";
        }

        void leDoTeclado() {
            int coordenadaX, coordenadaY;

            cin >> coordenadaX >> coordenadaY;

            setX(coordenadaX);
            setY(coordenadaY);
        }
};

int main() {
    Ponto *pontos = new Ponto[4];

    pontos[0].setX(0);
    pontos[0].setY(0);

    pontos[1].setX(1);
    pontos[1].setY(2);

    pontos[2].setX(2);
    pontos[2].setY(4);

    pontos[3].setX(3);
    pontos[3].setY(6);

    for (int i = 0; i < 4; i++) {
        cout << "Ponto " << i + 1 << ":" << endl;
        cout << "Coordenadas - ";
        pontos[i].imprime();
        cout << endl;
        cout << "Distancia - " << pontos[i].distancia(0,0) << endl;
        cout << endl;
    }

    Ponto *pontinhos = new Ponto[4];

    for (int i = 0; i < 4; i++) {
        pontinhos[i].leDoTeclado();
    }

    for (int i = 0; i < 4; i++) {
        cout << "Ponto " << i + 1 << ":" << endl;
        cout << "Coordenadas - ";
        pontinhos[i].imprime();
        cout << endl;
        cout << "Distancia - " << pontinhos[i].distancia(0,0) << endl;
        cout << endl;
    }

    delete[] pontos;
    delete[] pontinhos;

    return 0;
}