class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,int> map ; 
        int i = 0 , j = 0 , n = nums.size() ;
        
        for(i = 0 ; i < n &&  i < k ; i++){
            map[nums[i]]++;
            if(map[nums[i]] == 2) return true;
        }
        
        while(i < n ){
            map[nums[i]]++;
            if(map[nums[i]] >= 2) return true;
            map[nums[j]]--;
            j++;
            i++;
        }
        
        return false;
        
    }
};