#include <iostream>
#include <cstdlib>
using namespace std;

//Retorna o lucro gerado pela soluacao presente no arranjo usar (usar[i]= true se 
//o produto i estiver na solução e é false caso contrario).
//Retorna -1 se a solucao nao for viavel
int lucroSolucao(int custos[], int pesos[], bool usar[], int n, int capacidade) {
	int lucro =0;
	int pesoTotal = 0;
	for(int i=0;i<n;i++) {
		if (usar[i]) {
			lucro += custos[i];
			pesoTotal += pesos[i];
		}
	}
	return (pesoTotal > capacidade) ? -1: lucro;
}

const int n = 27;
bool melhorSolucao[n] ;
int pesos[n] = {3,2,2,6,4,5,20,3,1,2,4,2,1,4,1,1,1,2,1,2,2,4,2,4,3,4,2};
int custos[n] = {300,190,180,300,190,180,300,190,180,300,190,180,300,190,180,300,190,180,12,36,152,65,25,125,250,300,245};
int capacidade = 10;
int melhorLucro = -1;

void solve(bool combs[], int begin, int n) {
	if (begin >= n) {
		int lucro = lucroSolucao(custos,pesos, combs, n, capacidade);
		if (lucro > melhorLucro) {
			melhorLucro = lucro;
			for(int i=0;i<n;i++) melhorSolucao[i] = combs[i];
		}
	} else {
		combs[begin] = 0;
		solve(combs, begin+1, n);
		combs[begin] = 1;
		solve(combs, begin+1, n);
	}
}

int main(int argc, char **argv) {
	bool combs[n];
	solve(combs,0,n);
	cout << "Melhor lucro: " << melhorLucro << endl;
	return 0;
}
