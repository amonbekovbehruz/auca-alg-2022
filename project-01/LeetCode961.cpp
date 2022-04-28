#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> elememts;
        int maxElement = 0;

        for(auto &e: nums) {
            if(elememts.count(e)) {
                return e;
            } else {
                elememts.emplace(e);
            }
        }
        
        return maxElement;
    }
};