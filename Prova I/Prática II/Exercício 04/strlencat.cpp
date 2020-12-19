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

char* StrCat (char *string1, char *string2) {
    char *string3 = new char[StrLen(string1) + StrLen(string2) + 1];
    int contador = 0;
    
    while (*string1) {
        *(string3 + contador) = *string1; // !!!
        
        string1++;
        
        contador++;
    }

    while (*string2) {
        *(string3 + contador) = *string2;
        
        string2++;
        
       contador++;
    }

    *(string3 + contador) = '\0';

    return string3;
}

int main() {
    char *string1 = new char[51];
    char *string2 = new char[51];
    char *string3;
    
    cin.getline(string1, 51);
    cin.getline(string2, 51);
    
    cout << StrLen(string1) << " " << StrLen(string2) << endl;

    string3 = StrCat(string1, string2);

    cout << string3 << endl;

    delete []string1; 
    delete []string2;
    delete []string3;

    return 0;
}