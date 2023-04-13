class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int ans = -1 ;
        int diff = INT_MAX ;
        
        for(int k = 0 ; k < n - 2 ; k++){
            int i = k + 1 ;
            int j = n - 1;
            
            while(i < j ){
                int sum = nums[k] + nums[i] + nums[j];
                if(abs(sum - target) < diff ) {
                    diff = abs(sum - target) ;
                    ans = sum ;
                }
                
                if(sum < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return ans;
        
    }
};