Link : https://leetcode.com/problems/combination-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, int target, vector<int> subarray,vector<int> candidates, vector<vector<int>>& res,int n){
        if(i == n){
            if(target == 0){
                res.push_back(subarray) ;
            }
            return ;
        }
        if(candidates[i] <= target){
            subarray.push_back(candidates[i]);
            helper(i,target-candidates[i],subarray,candidates,res,n);
            subarray.pop_back();
            
        }
        helper(i+1,target,subarray,candidates,res,n) ;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res ;
        vector<int> subarray ;
        int n = candidates.size() ;
        helper(0,target,subarray,candidates,res,n) ;
        return res ;
    }
};