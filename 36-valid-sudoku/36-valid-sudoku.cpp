class Solution {
public:
    
    bool check(vector<vector<char>> &b , int r , int c) {
        
        int er = r + 3 ;
        int ec = c + 3 ;
        set<char> s;
        for(int i = r ;i < er ; i++){
            for(int j = c ; j < ec ; j++){
                if(b[i][j] == '.') continue;
                if(s.find(b[i][j]) != s.end()) return false;
                s.insert(b[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
       
        
        
        for(int i = 0 ; i < 9 ; i++){
            set<char> s;
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.') continue;
                if(s.find(board[i][j]) != s.end()) return false;
                s.insert(board[i][j]);
            }
        }
        
        
        for(int i = 0 ; i < 9 ; i++){
            set<char> s;
            for(int j = 0 ; j < 9 ; j++){
                if(board[j][i] == '.') continue;
                if(s.find(board[j][i]) != s.end()) return false;
                s.insert(board[j][i]);
            }
        }
        
        
        for(int i = 0 ; i< 9 ; i+=3){
            for(int j = 0 ; j < 9 ; j+=3){
                bool ans = check(board , i , j );
                if(ans == false) return ans;
            }
        }
        // if(ans == false) return false;
//         
        
        return true;
        
    }
};