class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans ;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++ ){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i +1 ; j < n ; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                long long curr =(long long) target - nums[i] - nums[j];
                int l = j +1  , r = n -1 ;
                while(l < r){
                    if(nums[l] + nums[r] == curr) {
                        if (l > j + 1 && r < n - 1) {
							if (nums[l] != nums[l - 1] || nums[r] != nums[r + 1]) {
								ans.push_back({nums[i], nums[j], nums[l], nums[r]});
							}
						} else {
							ans.push_back({nums[i], nums[j], nums[l], nums[r]});
						}
                        l++ ; r--;
                    
                    }
                    else if(nums[l] + nums[r] > curr){
                        r--;
                    } else l++;
                }
            }
        }
        
        return ans;
        
    }
};