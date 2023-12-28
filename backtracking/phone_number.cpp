// Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int ind, string& digits, string temp, map<char,string>& mp, vector<string>& result){
        if(ind == digits.size()){
            result.push_back(temp) ; return ;
        }
        char ch = (char)digits[ind] ; 
        string str = mp[ch] ;
        for(int j=0; j<str.size(); j++){
            temp.push_back(str[j]) ;
            helper(ind+1,digits,temp,mp,result) ;
            temp.pop_back() ;
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char,string> mp = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7',"pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        } ;
        vector<string> result ;
        if(digits.size() == 0) return result ;
        helper(0,digits,"",mp,result) ;
        return result ;
    }
};