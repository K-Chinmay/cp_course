// Link : https://leetcode.com/problems/palindrome-partitioning/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(int start, int end, string &s){
        while(start <= end){
            if(s[start] != s[end]) return false ;
            start++ ; end-- ;
        }
        return true ;
    }

    void helper(int start, string &s, vector<string> temp, vector<vector<string>>& result){
        if(start == s.size()){
            result.push_back(temp) ;
            return ;
        }
        for(int end = start; end < s.size(); end++){
            if(valid(start,end,s)){
                temp.push_back(s.substr(start,end-start+1)) ;
                helper(end+1,s,temp,result) ;
                temp.pop_back() ;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result ;
        helper(0,s,{},result) ;
        return result ;
    }
};