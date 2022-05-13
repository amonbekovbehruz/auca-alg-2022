#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

enum class Color
{
    White,
    Red,
    Black
};

using AdList = unordered_map<string, vector<string>>;
using ColorState = unordered_map<string, Color>;

void dfs(const string &u, AdList &adLists, ColorState &colors, list<string> &res)
{
    colors[u] = Color::Red;

    // const auto &adList = adLists.find(u)->second;

    for (const auto &v : adLists[u])
    {
        if (colors[v] == Color::Red)
        {
            throw runtime_error("loop");
        }

        if (colors[v] == Color::White)
        {
            dfs(v, adLists, colors, res);
        }
    }

    colors[u] = Color::Black;
    res.push_front(u);
}

int main()
try
{
    iostream::sync_with_stdio(false);

    ColorState colors;
    AdList adLists;

    for (string item; cin >> item && item != "---";)
    {
        colors[item] = Color::White;
        adLists[item] = vector<string>();
    }

    for (string u, v; cin >> u >> v;)
    {
        adLists[u].push_back(v);
    }

    list<string> res;
    for (const auto &p : colors)
    {
        if (p.second == Color::White)
        {
            dfs(p.first, adLists, colors, res);
        }
    }

    for (const auto &e : res)
    {
        cout << " " << e;
    }
    cout << endl;
}
catch (const runtime_error &e)
{
    cerr << e.what() << endl;
}