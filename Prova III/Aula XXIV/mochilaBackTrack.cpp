#include <iostream>
#include <cstdlib>
using namespace std;


const int n = 27;
bool melhorSolucao[n] ;
int pesos[n] = {3,2,2,6,4,5,20,3,1,2,4,2,1,4,1,1,1,2,1,2,2,4,2,4,3,4,2};
int custos[n] = {300,190,180,300,190,180,300,190,180,300,190,180,300,190,180,300,190,180,12,36,152,65,25,125,250,300,245};
int capacidade = 10;
int melhorLucro = -1;

void solve(bool combs[], int begin, int n,int lucroParcial, int pesoParcial) {
	if (pesoParcial > capacidade) {
		return;
	}
	if (begin >= n) {		
		int lucro = lucroParcial;
		if (lucro > melhorLucro) {
			melhorLucro = lucro;
			for(int i=0;i<n;i++) melhorSolucao[i] = combs[i];
		}
	} else {
		combs[begin] = 0;
		solve(combs, begin+1, n,lucroParcial,pesoParcial);
		combs[begin] = 1;
		solve(combs, begin+1, n,lucroParcial+custos[begin],pesoParcial+pesos[begin]);
	}
}

int main(int argc, char **argv) {
	bool combs[n];
	solve(combs,0,n,0,0);
	cout << "Melhor lucro: " << melhorLucro << endl;
	return 0;
}
