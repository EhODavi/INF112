#include <iostream>

using namespace std;

char* chartostring(char c) {
    char* ptr = (char*) malloc(2 * sizeof c);
    
    *ptr = c;
    *(ptr + 1) = '\0';

    return ptr;
}

int main() {
    char c, *ptr; 

    cin >> c;

    ptr = chartostring(c);

    cout << *ptr << endl;

    free(ptr);

    return 0;
}