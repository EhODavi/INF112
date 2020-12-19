#include <iostream>

using namespace std;

int main() {
    int y, *p, x; // declara os inteiros x e y e o ponteiro para int p
    y = 0; // y vale 0
    p = &y; // o ponteiro p recebe o endereço de y
    x = *p; // x vale 0
    x = 4; // x vale 4
    (*p)++; // y vale 1
    x--; // x vale 3
    (*p) += x; // y vale 4
    cout << "y = " << y << endl;
    return(0);
}