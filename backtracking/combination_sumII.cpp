// Link : https://leetcode.com/problems/combination-sum-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int ind, int target, vector<int> subarray, vector<int> candidates, vector<vector<int>>& sv, int n){
        if(target == 0){
            sv.push_back(subarray);
            return ;
        }
        for(int i=ind; i<n; i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue ;
            if(candidates[i] > target) break ;
            else{
                subarray.push_back(candidates[i]);
                helper(i+1,target-candidates[i],subarray,candidates,sv,n);
                subarray.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sv ;
        int n = candidates.size() ;
        vector<int> subarray ;
        sort(candidates.begin(),candidates.end());
        helper(0,target,subarray,candidates,sv,n) ;
        return sv ;
    }
};