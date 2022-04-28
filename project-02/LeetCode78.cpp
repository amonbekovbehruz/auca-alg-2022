#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        generate(result, nums, 0, vector<int>());
        
        return result;
    }
    
    void generate(vector<vector<int>>& res, const vector<int> numbers, size_t index, vector<int> curr)
    {
        if(numbers.size() == index)
        {
            res.push_back(curr);
        }
        else
        {
           generate(res, numbers, index + 1, curr); 
           curr.push_back(numbers[index]);
           generate(res, numbers, index + 1, curr);   
        }
    }
};