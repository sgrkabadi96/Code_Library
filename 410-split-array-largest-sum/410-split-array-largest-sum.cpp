class Solution {
public:
    
    int  f(vector<int> &nums , int m , int maxsum) {
        int currm = 0 ;
        int sum = 0 ;
        for(int &i : nums ){
            if(i > maxsum ) return false;
            if(sum + i  > maxsum) {
                currm++ ;
                sum = i ;
            }  
            else {
                sum+=i;
            }
        }
        currm++;
        return currm;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int low = 0 ; 
        int high = 0 ;
        
        int n = nums.size();
        for(int &i : nums) {
            high += i;
            low = max(low , i);
        }
        
        int ans = 0 ;
        while(low <= high) {
            int mid = low + (high - low ) / 2 ; 
            int currm = f(nums , m , mid);
            if(currm <= m ){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};