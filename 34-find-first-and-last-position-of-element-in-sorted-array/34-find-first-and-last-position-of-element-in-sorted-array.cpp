class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans ;
        
        
        int s = 0 ;
        int e = nums.size() - 1;
        int x = -1;
        while(s<= e ){
            int m = s + (e - s ) / 2 ;
            if(nums[m] >= target){
                if(nums[m] == target) x = m;
                e = m-1;
            } else {
                s = m + 1;
            }
        }
        if(x == -1) return {-1 , -1 } ;
        ans.push_back(x);
        
        s = 0 ;
        e = nums.size() -1;
        while(s <= e){
            int m = s + (e - s)/ 2;
            if(nums[m] <= target){
                if(nums[m] == target) {
                    x = m;
                }
                s = m + 1 ;
            } else {
                e = m-1;
            }
        }
        ans.push_back(x);
        
        return ans;
    }
};