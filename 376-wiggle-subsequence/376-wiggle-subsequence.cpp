class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size() ;
        string s ="";
        for(int i = 1 ; i < n ; i++){
            if(nums[i] - nums[i-1] < 0) {
                s += "0";
            } else if(nums[i] - nums[i-1] > 0){
                s += "1";
            }
        }
        
        int zero = 0 ;
        int one = 0;
        
        int ans = 0 ;
        
        for(char &c: s){
           if(c == '0'){
               zero = max(zero , one+1);
               ans = max(zero ,ans);
           } else {
               one = max(one , zero+1);
               ans = max(one , ans);
           }
        }
        
        return ans + 1;
    }
};