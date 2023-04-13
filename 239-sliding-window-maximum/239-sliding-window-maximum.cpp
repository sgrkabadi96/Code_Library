class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        
        multiset<int,greater<int>> s ; 
        int i;
        for(i = 0 ; i < k -1 ; i++){
            s.insert(nums[i]);
        }
        
        int j = 0;
        int n = nums.size();
        vector<int> ans ;
        
        while(i < n){
            s.insert(nums[i]);
            int fele = *s.begin();
            ans.push_back( fele );
            int ele = nums[j];
            auto pos = s.find(ele);
            s.erase(pos);
            j++;
            i++;
        }
        return ans;
    }
};