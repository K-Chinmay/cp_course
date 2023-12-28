// Link : https://leetcode.com/problems/generate-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int open, int close, string temp, vector<string>& result, int n){
        if(temp.size() == 2*n){
            result.push_back(temp) ; 
            return ;
        }
        if(open < n) helper(open+1,close,temp + "(",result,n) ;
        if(close < n && close < open) helper(open,close+1,temp + ")",result,n) ;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result ;
        helper(1,0,"(",result,n) ;
        return result ;
    }
};