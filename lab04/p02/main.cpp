#include <iostream>

using namespace std;

int factorial(int n)
{
    return n == 0 ? 1 : factorial(n - 1);
}

int main()
{
    int x;

    cin >> x;

    cout << factorial(x) << endl;
}