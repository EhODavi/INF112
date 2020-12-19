#include <iostream>

using namespace std;

int main() {
  int i, *vetor = new int[10];
  for (i = 0; i < 10; i++)
    cin >> vetor[i];
  for (i = 9; i >= 0; i--)
    cout << vetor[i] << endl;
  return 0;
}