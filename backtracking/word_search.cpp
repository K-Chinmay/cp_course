// Link : https://leetcode.com/problems/word-search/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> drow = {0,-1,0,1} ;
    vector<int> dcol = {-1,0,1,0} ;

    bool bounded(int i, int j, int n, int m){
        return (i >= 0 && j >= 0 && i < n && j < m) ;
    }

    bool helper(int i, int j, int ind, vector<vector<int>>& visited, vector<vector<char>>& board, string& word){
        if(word[ind] != board[i][j]) return false ;
        if(ind == word.size()-1) return true ;
        visited[i][j] = 1 ;
        for(int l=0; l <= 3; l++){
            int x = i + drow[l] , y = j + dcol[l] ;
            if(bounded(x,y,board.size(),board[0].size()) && !visited[x][y]){
                if(helper(x,y,ind+1,visited,board,word)) return true ;
            }
        }
        visited[i][j] = 0 ;
        return false ;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size() ;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<vector<int>> visited(n,vector<int>(m,0)) ;
                if(helper(i,j,0,visited,board,word)) return true ;
            }
        }
        return false ;
    }
};