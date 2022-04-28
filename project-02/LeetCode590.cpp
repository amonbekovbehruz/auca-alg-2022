#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        
        listTheValues(result, root);
        
        return result;
    }
    
    void listTheValues(vector<int> &result, Node* root)
    {
        if(root != nullptr){
            for(int i = 0; i < root->children.size(); i++) {
                listTheValues(result, root->children[i]);
            }
        }

        result.push_back(root->val);
    }
};