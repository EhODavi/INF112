#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>
using namespace std;

void marca(const int y,const int x,int **m,bool **visitados, const int nrows, const int ncolumns) {
	if (y>=nrows || y<0 || x>=ncolumns || x<0) return;
	if (visitados[y][x] || m[y][x] == 1) return;
	visitados[y][x] = true;
	marca(y-1,x-1,m,visitados,nrows,ncolumns);
	marca(y-1,x,m,visitados,nrows,ncolumns);
	marca(y-1,x+1,m,visitados,nrows,ncolumns);

	marca(y,x-1,m,visitados,nrows,ncolumns);
	marca(y,x+1,m,visitados,nrows,ncolumns);

	marca(y+1,x-1,m,visitados,nrows,ncolumns);
	marca(y+1,x,m,visitados,nrows,ncolumns);
	marca(y+1,x+1,m,visitados,nrows,ncolumns);
}

int main() {
	int nrows, ncolumns;
	string st;
	getline(cin,st); //ignora as duas primeiras linhas..
	getline(cin,st);
	cin >> ncolumns >> nrows;
	
	int **m = new int*[nrows];
	for(int i=0;i<nrows;i++)
		m[i] = new int[ncolumns];

	for(int i=0;i<nrows;i++)
		for(int j=0;j<ncolumns;j++) {
			char c;
			cin >> c;	
			m[i][j] = c-'0';
		}

	bool **visitados = new bool*[nrows];
	for(int i=0;i<nrows;i++) {
		visitados[i] = new bool[ncolumns];
		for(int j=0;j<ncolumns;j++)
			visitados[i][j] = false;
	}

	marca(0,0,m,visitados,nrows,ncolumns);


	cout << "P1" << endl;
	cout << ncolumns <<  " " << nrows << endl;
	for(int i=0;i<nrows;i++) {
		for(int j=0;j<ncolumns;j++)
			cout << visitados[i][j];
		cout << "\n";
	}
	cout << flush;
	
	for(int i=0;i<nrows;i++)
		delete []visitados[i];
	delete []visitados;		
	
	for(int i=0;i<nrows;i++)
		delete []m[i];
	delete []m;	
	return 0;
}
