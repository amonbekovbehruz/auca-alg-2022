#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        sort(v, root);
        TreeNode* node = new TreeNode(0);
        TreeNode* zero_node = node;
        for (int i : v)
        {
            node->right = new TreeNode(i);
            node = node->right;
        }

        return zero_node->right;
    }

    void sort(vector<int> &v, TreeNode* root)
    {
        if (root)
        {
            sort(v, root->left);
            v.push_back(root->val);
            sort(v, root->right);
        }
    }

};
