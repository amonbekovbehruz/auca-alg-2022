#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, int> dict;
    int x;
    while (cin >> x)
    {
        if(dict.find(x) != dict.end()) { dict.insert(make_pair(x, x++)); }
    }

    for (auto e : dict) {
        cout << e.first << " " << e.second << endl;
    }
}