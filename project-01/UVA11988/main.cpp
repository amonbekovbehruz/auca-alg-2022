#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (string line; getline(cin, line);)
    {
        list<char> res;
        auto cursor = res.end();
        for (auto c : line)
        {
            if(c == '[')
            {
                cursor = res.begin();
            } else if (c == ']')
            {
                cursor = res.end();
            }
            else {
                res.insert(cursor, c);
            }  

        }
         cout << string(res.begin(), res.end()) << endl;
    } 
}