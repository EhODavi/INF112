#include <iostream>
#include <cstdlib>
using namespace std;



void imprimeCombinacoes(bool combs[], int begin, int n) {
	if (begin >= n) {
		for(int i=0;i<n;i++) {
			cout << combs[i];
		}		
		cout << endl;
	} else {
		combs[begin] = 0;
		imprimeCombinacoes(combs, begin+1, n);
		combs[begin] = 1;
		imprimeCombinacoes(combs, begin+1, n);
	}
}

int main(int argc, char **argv) {
	int n = atoi(argv[1]);
	bool combs[n];
	imprimeCombinacoes(combs,0,n);

}
