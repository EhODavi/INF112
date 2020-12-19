#include <iostream>

using namespace std;

long long int fatorial(int n)
{
    if (n == 0)
        return 1;
    return n * fatorial(n - 1);
}

int main(int argc, char **argv)
{
    int n;

    if (argc != 2)
    {
        cerr << "Erro, use:./exercicio01 n" << endl;
        exit(1);
    }

    n = atoi(argv[1]);

    cout << fatorial(n) << endl;

    return 0;
}