class Solution {
public:
    
    bool f(int k , vector<int> &a , int tar){
        
        int sum = 0;
        int  n = a.size();
        int  j = 0;
        
        int i = 0;
        for(i = 0 ; i < k-1 ; i++){
            sum+= a[i];
        }
       
        while(i < n) {
            sum+= a[i];
            if(sum >= tar) return true;
            sum -= a[j];
            j++;
            i++;
        }
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int low = 1 ;
        int high = nums.size() ;
        int ans = INT_MAX ;
        
        while(low <= high){
            int mid = low + (high - low ) / 2;
            bool temp = f(mid , nums , target);
            if(temp){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+ 1;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};