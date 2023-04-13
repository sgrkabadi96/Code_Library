class Solution {
public:
    
    void solve(vector<int> &nums , vector<int>& p  , vector<vector<int>> &ans , int idx , int n) {
        if(idx == n ) {
            ans.push_back(p);
            return ;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != - 11) {
                int st = nums[i];
                nums[i] = -11;
                p[idx] = st;
                solve(nums , p ,ans , idx+1 , n  );
                nums[i]= st;
            }
        }
        return ;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> ans ;
        // int n = nums.size();

        vector<int> p(n ,- 1); 
        solve(nums , p , ans , 0  , n  );
        return ans;
    }
};