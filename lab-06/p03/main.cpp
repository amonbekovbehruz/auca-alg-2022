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

int main()
{
    iostream::sync_with_stdio(false);

    unordered_map<string, Color> colors;
    unordered_map<string, int> distances;
    unordered_map<string, string> preds;

    unordered_map<string, vector<int>> graph;

    int nEdges;
    cin >> nEdges;

    for (int i = 0; i < nEdges; i++)
    {
        string u;
        cin >> u;
        string v;
        cin >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

        colors[u] = Color::White;
        colors[v] = Color::White;
        preds[u] = "null";
        preds[v] = "null";
    }
    string source;
    cin >> source;
    string dest;
    cin >> dest;

    queue<string>
        redVertices;

    colors[source] = Color::Red;
    distances[source] = 0;
    redVertices.push(source);

    while (!redVertices.empty())
    {
        string u = redVertices.front();
        redVertices.pop();

        colors[u] = Color::Black;

        for (auto v : graph[u])
        {
            if (colors[v] == Color::White)
            {
                colors[v] = Color::Red;
                preds[v] = u;
                distances[v] = distances[u] + 1;
                redVertices.push(v);
            }
        }
    }

    for (auto p : distances)
    {
        cout << p.first << ": " << p.second << endl;
    }

    vector<string> path;
    path.push_back(dest);
    while (preds[path.back()] != "null")
    {
        path.push_back(preds[path.back()]);
    }

    for (auto e : path)
    {
        cout << " " << e;
    }
    cout << endl;
}