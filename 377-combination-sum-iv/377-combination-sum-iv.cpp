class Solution {
public:
    int dp[201][1001];
    
    int helper(vector<int> & a , int i , int target) {
        int n = a.size();
        if(i >= n ) {
            if(target == 0) return 1;
            return 0;
        }
        if(target < 0) return 0;
        
        if(dp[i][target] != -1 ) return dp[i][target];
        int ans = 0;
        if(target - a[i] >= 0){
            ans += helper(a , 0 , target-a[i]);
        } 
        ans+= helper(a , i +1 , target);
        return dp[i][target]  = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        memset(dp , -1 , sizeof dp);
        return helper(nums , 0 , target);
    }
};