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

class Reta {
    private:
        Ponto p1, p2;

    public:
        void setP1(Ponto pontoP1) {
            p1 = pontoP1;
        }

        void setP2(Ponto pontoP2) {
            p2 = pontoP2;
        }

        Ponto getP1() {
            return p1;
        }

        Ponto getP2() {
            return p2;
        }

        double tamanho() {
            return p1.distancia(p2.getX(), p2.getY());
        }

        void imprime() {
            cout << "[";
            p1.imprime();
            cout << ",";
            p2.imprime();
            cout << "]";
        }

        void leDoTeclado() {
            Ponto ponto1, ponto2;

            ponto1.leDoTeclado();
            ponto2.leDoTeclado();

            setP1(ponto1);
            setP2(ponto2);
        }
};

int main() {
    Reta *retas = new Reta[3];

    for (int i = 0; i < 3; i++) {
        retas[i].leDoTeclado();
    }

    for (int i = 0; i < 3; i++) {
        cout << "Reta " << i + 1 << ":" << endl;
        cout << "Coordenadas - ";
        retas[i].imprime();
        cout << endl;
        cout << "Comprimento - " << retas[i].tamanho() << endl;
        cout << endl;
    }

    delete[] retas;

    return 0;
}