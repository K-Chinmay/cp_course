// Link : https://leetcode.com/problems/restore-ip-addresses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int ind, int count, string temp, string& s, vector<string>& result){
        if(ind == s.size() && count == 4){
            temp.pop_back() ;
            result.push_back(temp) ;
            return ;
        }
        if(count > 4) return ;
        if(count < 4 && ind >= s.size()) return ;

        for(int i = ind; i<ind+3; i++){
            if(i >= s.size()) break ;
            string str = s.substr(ind,i-ind+1) ;
            if(str.size() > 1 && str[0] == '0') continue ;
            int num = stoi(str) ;
            if(num > 255) continue ;

            temp += str ; temp += "." ;
            helper(ind+str.size(),count+1,temp,s,result) ;
            for(int j=0; j<=str.size(); j++) temp.pop_back() ;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result ;
        helper(0,0,"",s,result) ;
        return result ;
    }
};