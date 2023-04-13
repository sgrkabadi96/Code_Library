class Solution {
public:
    int ans = 0  ;
    
    int helper(vector<vector<char>> &matrix , int i , int j  ,vector<vector<int>> &dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(i >= n || j >= m) return 0 ;
        if(dp[i][j] != -1) return dp[i][j];
        
        int x = helper(matrix , i+1 , j ,dp );
        int y = helper(matrix , i ,  j+1 , dp);
        int z = helper(matrix , i+1 , j+1 ,dp);
        
        int curr = 0; 
        if(matrix[i][j] == '1'){
            curr = min(z , min(x ,y )) + 1;
            ans = max(ans ,curr);
            return dp[i][j] = curr;
        }
        return dp[i][j] = 0;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0 ; 
        int j = 0 ;
        vector<vector<int>> dp(matrix.size() , vector<int>(matrix[0].size() , -1));
        helper(matrix , 0 , 0 ,dp );
        return ans * ans ;
    }
};