class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        int pro= nums[0] ;
        vector<int> ans(n ,1);
        
        for(int i = 1 ; i < n ; i++){
            ans[i] = pro ; 
            pro = pro * nums[i];
        }
        
        pro = nums[n-1];
        for(int i = n-2 ; i>= 0 ; i--){
            ans[i] = ans[i] * pro ;
            pro = pro * nums[i];
        }
        
        return ans;
    }
};