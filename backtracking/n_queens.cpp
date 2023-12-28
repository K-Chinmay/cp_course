// Link : https://leetcode.com/problems/n-queens/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(int i, int j, vector<string>& board){
        int row = i, col = j ;
        while(row >= 0 && col >= 0){
            if(row > 0 && board[row-1][col] == 'Q') return false ;
            row-- ;
        }
        row = i, col = j ; 
        while(row >= 0 && col >= 0){
            if(row > 0 && col > 0 && board[row-1][col-1] == 'Q') return false ;
            row-- ; col-- ;
        }
        row = i, col = j ; 
        while(row >= 0 && col < board.size()){
            if(row > 0 && board[row-1][col+1] == 'Q') return false ;
            row-- ; col++ ;
        }
        return true ;
    }

    void helper(int i, vector<string>& board, vector<vector<string>>& result){
        if(i == board.size()){
            result.push_back(board) ;
            return ;
        }
        for(int j=0; j<board.size(); j++){
            if(!valid(i,j,board)) continue ;
            board[i][j] = 'Q' ;
            helper(i+1,board,result) ;
            board[i][j] = '.' ;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result ;
        vector<string> board(n) ;
        string s(n,'.') ;
        for(int i=0; i<n; i++){
            board[i] = s ;
        }
        helper(0,board,result) ;
        return result ;
    }
};