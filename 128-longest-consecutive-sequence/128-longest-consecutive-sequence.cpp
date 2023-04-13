class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        
        set<int> s(v.begin(), v.end());
        
        int ans = 0;
        
        int curr = 0 ;
        int prev ;
        
        for(auto ele : s){
            // cout << ele << " ";
            if(curr == 0 ){
                curr++;
                prev = ele;
                ans= max(ans, curr);
            } 
            else {
                if(ele == prev+1){
                    curr++;
                    ans = max(ans ,curr);
                    prev = ele;
                } else {
                    curr = 1 ;
                    prev = ele;
                    ans = max(ans ,curr);
                }
            }
        }
        return ans; 
    }
};