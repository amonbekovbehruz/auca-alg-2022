#include <iostream>

using namespace std;

void readAndPrintInReveserOrder()
{
    int x;
    if (cin >> x)
    {
        readAndPrintInReveserOrder();
        cout << " " << x;
    }
}

int main()
{
    // functional languages(haskell, lisp, scheme, ml ..)

    readAndPrintInReveserOrder();
    cout << endl;
}

