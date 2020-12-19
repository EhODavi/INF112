#include <iostream>

using namespace std;

long long int fibonacci(int n, long long int &x)
{
    if (n == 0 || n == 1)
    {
        x++;
        return n;
    }

    x++;
    return fibonacci(n - 1, x) + fibonacci(n - 2, x);
}

int main(int argc, char **argv)
{
    int n;
    long long int x = 0;

    if (argc != 2)
    {
        cerr << "Erro, use:./exercicio03 n" << endl;
        exit(1);
    }

    n = atoi(argv[1]);

    cout << fibonacci(n, x) << " " << x << endl;

    return 0;
}