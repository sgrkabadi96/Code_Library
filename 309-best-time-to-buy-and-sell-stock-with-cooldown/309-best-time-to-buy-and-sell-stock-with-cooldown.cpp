class Solution {
public:
    int helper(vector<int> &a , int i , int buy , vector<vector<int>> &dp) {
        if(i >= a.size()) return 0 ;
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int ans = 0 ; 
        
        if (buy == 1) {
            int x = (-1 * a[i] )+ helper(a , i + 1 , 0 , dp);
            int y = 0 + helper(a , i + 1 , 1 ,dp);
            ans = max(x , y);
        }
        
        else if (buy == 0) {
            int x = a[i] + helper(a , i+2 , 1 ,dp);
            int y = 0 + helper(a , i+1 , 0 ,dp);
            ans = max(x , y);
        }

        return dp[i][buy] = ans ; 
    }
    int maxProfit(vector<int>& a) {
        
        int n = a.size() ; 
        vector<vector<int>> dp(n+1 , vector<int>(2 , -1));
        return helper(a, 0 , 1 , dp) ;
    }
};