#include <iostream>

using namespace std;

int StrLen (char *string1) {
    int contador = 0;

    while (*string1) {
        string1++;
        contador++;
    }

    return contador;
}

bool strend(char *s, char *t) {
    int slen = StrLen(s);
    int tlen = StrLen(t);

    for (int i = tlen - 1; i >= 0 ; i--) {
        if (*(t + i) != *(s + slen - 1)) {
            return false;
        }
        slen--;
    }

    return true;
    
}

int main() {
    char *s = new char[51];
    char *t = new char[51];

    cin >> s;
    cin >> t;

    cout << strend(s, t) << endl;

    delete []s;
    delete []t;

    return 0;
}