#include <iostream>

using namespace std;

struct Jogador {
    int pontos;
    int x, y;
};

void leDadosJogador(Jogador *jogador) {
    cin >> jogador->pontos >> jogador->x >> jogador->y;
}

int main() {
    Jogador jogadores[5];

    for(int i = 0; i < 5; i++) {
       leDadosJogador(&jogadores[i]); 
    }

    for(int i = 0; i < 5; i++) {
       cout << jogadores[i].pontos << " " << jogadores[i].x << " " << jogadores[i].y << endl;
    }
   
    return 0;
}