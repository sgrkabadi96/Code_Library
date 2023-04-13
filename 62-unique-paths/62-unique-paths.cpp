class Solution {
public:
    int helper(int m , int n , vector<vector<int>>&dp){
        if(m == 1 && n == 1) return 1;
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] !=-1) return dp[m][n];
        int ans = 0 ;
        ans += helper(m -1 , n  ,dp);
        ans += helper(m , n - 1 , dp);
        dp[m][n] = ans ;
        return ans;
    }
    
    int uniquePaths(int m, int n) {
        vector< vector<int>> dp (m+1 , vector<int>(n+1 , -1));
        int ans = helper(m , n , dp);
        return ans;
    }
};