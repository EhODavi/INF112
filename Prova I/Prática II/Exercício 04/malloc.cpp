#include <iostream>

using namespace std;

int main () {
    char **p;
    int a;

    cin >> a;

    a++;

    p = new char*[a]; 
    
    for (int i = 0; i < a ; i++) {
        p[i] = new char[a];
    }

    for (int i = 0; i < a ; i++) {
        cin.getline(p[i], a);
    }

    for (int i = 0; i < a ; i++) {
        cout << p[i] << endl;
    }
    
    for (int i = 0; i < a ; i++) {
        delete [] p[i];
    }

    delete [] p;

    return 0;
}