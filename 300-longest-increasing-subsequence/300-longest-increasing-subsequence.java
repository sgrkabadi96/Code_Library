class Solution {
    int f(int nums[]  , int i ,  int p_i , int dp[][] ){
        int n = nums.length;
        if(i >= n  ) return 0 ;
        
        if(dp[i][p_i+1] != -1) return dp[i][p_i+1];
        
        int ans = f(nums, i+1 , p_i , dp);
        if(p_i == -1 || nums[i] > nums[p_i]){
            ans =Math.max(ans ,f(nums , i+1 , i , dp) + 1) ;
        }
        
        dp[i][p_i +1 ] = ans ;
        return ans;
        
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length; 
        int dp[][] = new int[n+1][n+1];
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <= n ;  j++){
                dp[i][j] = -1 ;
            }
        }
        
        
        for(int i = n - 1; i >= 0 ; i--) {
            for(int p_i = i-1  ; p_i >= -1 ; p_i--) {
                
                int ans = dp[i+1][p_i+1]  ;
                if(p_i == -1 || nums[i] > nums[p_i]){
                    ans =Math.max(ans , 1 + dp[i+1][i+1]) ;
                }
                dp[i][p_i +1 ] = ans ;
            }
        }
        return dp[0][0];
    }
}