class Solution {
public:
 
    int solve(vector<int> &nums,int ind,int n,vector<int> &dp)
    {
        if(ind==n)
            return 1;
        
        if(dp[ind]!= -1) return dp[ind];
        for(int i=1;i<=nums[ind];i++)
        {
            int p=solve(nums,ind + i,n,dp);
            if(p == 1) return dp[ind + i] = 1;
        }
        return dp[ind] = 0;
    }
    
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n+1,-1);
        bool x=solve(nums,0,n-1,dp);
        return x;
    }
};


