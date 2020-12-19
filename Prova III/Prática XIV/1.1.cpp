#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    unsigned int numero;

    if (argc != 2)
    {
        cerr << "Erro, use:./1 numero" << endl;
        exit(1);
    }

    numero = atoi(argv[1]);

    if ((numero & 1) == 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}