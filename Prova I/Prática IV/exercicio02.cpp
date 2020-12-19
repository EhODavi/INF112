#include <iostream>

using namespace std;

long long int stirling(int n, int k)
{
    if (n == 0 && k == 0)
    {
        return 1;
    }
    else if (n == 0 || k == 0)
    {
        return 0;
    }

    return k * stirling(n - 1, k) + stirling(n - 1, k - 1);
}

int main()
{
    int n, k;

    cin >> n >> k;

    cout << stirling(n, k) << endl;

    return 0;
}