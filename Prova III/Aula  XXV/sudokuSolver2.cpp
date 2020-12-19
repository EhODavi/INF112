#include <iostream>

using namespace std;

void imprimeJogo(int jogo[][9]) {
	cout << "-----------------------------\n";
	cout << "Solução: \n";
	for(int i=0;i<9;i++) {
		if (i%3==0) cout << "\n";
		for(int j=0;j<9;j++) {
			if (j%3 ==0) cout << " ";
			cout << jogo[i][j] << " ";			
		}
		cout << "\n";		
	}
	cout << "-----------------------------\n";
}

bool validoColuna(int jogo[][9] , int px) {
	int conta[10] = {0}; // existe[i] conta quantas vezes o número i aparece..
	for(int i=0;i<9;i++) conta[ jogo[i][px] ]++;
	for(int i=1;i<10;i++) if (conta[i]>1) return false;
	return true;
}

bool validoLinha(int jogo[][9] , int py) {
	int conta[10] = {0}; // existe[i] conta quantas vezes o número i aparece..
	for(int i=0;i<9;i++) conta[ jogo[py][i] ]++;
	for(int i=1;i<10;i++) if (conta[i]>1) return false;
	return true;
}

bool validoQuadrado(int jogo[][9] , int py,int px) {
	int conta[10] = {0}; // existe[i] conta quantas vezes o número i aparece..
	for(int i=0;i<3;i++) 
		for(int j=0;j<3;j++)
			conta[ jogo[i+py*3][j+px*3] ]++;
	for(int i=1;i<10;i++) if (conta[i]>1) return false;
	return true;
}

bool valido(int jogo[][9] , int py, int px) {
	return validoLinha(jogo,py) && validoColuna(jogo,px) && validoQuadrado(jogo,py/3,px/3) ;
}

void resolveJogo(int jogo[][9], int posicaoPreencher = 0) {
	if (posicaoPreencher == 81) {
		 //Significa que ja conseguimos preencher o jogo todo... podemos, então, imprimir o "tabuleiro"
		imprimeJogo(jogo);
		return;
	}
	int py = posicaoPreencher/9;
	int px = posicaoPreencher%9;
	
	if (jogo[py][px] != 0) { //essa posicao já veio preenchida...	
		resolveJogo(jogo,  posicaoPreencher +1);
	} else {	
		for(int i=1;i<=9;i++) {
			//Vamos tentar colocar o numero i na posicao "posicaoPreencher"		
			jogo[py][px] = i;
			if (valido(jogo,py,px)) //Se colocar "i" na posicao (py,px) mantiver o tabuleiro "válido", então podemos continuar...
				resolveJogo(jogo,  posicaoPreencher +1);
			jogo[py][px] = 0; //tira o número que acabamos de colocar para testar..
			
		}
	}
}

int main() {
	int jogo[9][9];
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cin >> jogo[i][j];

	cout << "Jogo inicial: " << endl;
	imprimeJogo(jogo);
	resolveJogo(jogo);

	return 0;	
}
