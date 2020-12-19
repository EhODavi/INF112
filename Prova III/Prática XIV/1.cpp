#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    unsigned long long int numero;

    if (argc != 2)
    {
        cerr << "Erro, use:./1 numero" << endl;
        exit(1);
    }

    numero = atoi(argv[1]);

    cout << (numero & 1) << endl;

    return 0;
}