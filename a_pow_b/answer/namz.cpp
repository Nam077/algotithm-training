#include <bits/stdc++.h>
#include <fstream>
using namespace std;
long modPow(long a, long b, long c)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = (result * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return result;
}

int main()
{
    long mod = 10000;
    long a, b;
    cin >> a >> b;
    cout << modPow(a, b, mod);
    return 0;
}