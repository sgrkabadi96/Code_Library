class Solution {
public:
    
    int helper(string &s , int i , vector<int>& dp){
        if(i >= s.size()) return 1;
        if(s[i] == '0') return 0 ;
    
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        
        
        ans+= helper(s , i+1, dp);
        string x = s.substr(i , 2);
        if(x.size() >= 2){
            if(stoi(x) <= 26 && x[0] != '0'){
                ans+=helper(s , i+2 , dp);
            }
        }
        return dp[i] = ans ;
    }

    int numDecodings(string s) {
        
        int  n = s.size();
        vector<int> dp(n+1 , 0);
        // return helper(s, 0 , dp);
        dp[n] = 1 ; 
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '0') {
                continue ;
            }

            dp[i] = dp[i+1]  ;
            
            if(i < n-1 ){
                string x = s.substr(i , 2) ; 
                int xx = stoi(x);
                if(xx <= 26){
                    dp[i] += dp[i+2];
                }
            }
            
        }
        
        
        return dp[0];
    }
};