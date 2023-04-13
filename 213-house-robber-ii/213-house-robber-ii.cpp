class Solution {
public:
    int helper(vector<int> &a , int i , int f , vector<vector<int>> &dp){
        if(i >= a.size() ) return 0 ;
        if(i == a.size()-1 ) {
            if(f == 1 ) return 0;
            return a[i];
        }
        if(dp[i][f]!=-1) return dp[i][f] ; 
        
        if(i == 0) {
            int x = helper(a , i+2 , 1 ,dp)  + a[i];
            int y = helper(a , i+1 , 0 , dp);
            return dp[i][f] = max(x , y) ;
        }
        else {
            int x = helper(a , i+2 , f , dp) + a[i];
            int y = helper(a , i+1 , f , dp);
            return dp[i][f] =  max(x ,y );
        }
        
        return 0 ;
        
    }
    int rob(vector<int>& nums) {
        
        
        vector<vector<int>> dp(nums.size()+1 , vector<int>(2 ,-1));
        int ans = helper(nums , 0 , 0, dp);
        return ans;
    }
};