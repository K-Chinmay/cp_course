// Link : https://leetcode.com/problems/different-ways-to-add-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> helper(int start, int end, string& exp){
        int len = end - start + 1 ;
        if(len <= 2) return {stoi(exp.substr(start,len))} ;
        vector<int> possibleVal ;
        for(int i=start; i<end; i++){
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*'){
                vector<int> left = helper(start,i-1,exp) ;
                vector<int> right = helper(i+1,end,exp) ;
                for(auto x : left){
                    for(auto y : right){
                        if(exp[i] == '+') possibleVal.push_back(x+y) ;
                        if(exp[i] == '-') possibleVal.push_back(x-y) ;
                        if(exp[i] == '*') possibleVal.push_back(x*y) ;
                    }
                }            
            }
            
        }

        return possibleVal ;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> result ;
        result = helper(0,expression.size()-1,expression) ;
        return result ;
    }
};