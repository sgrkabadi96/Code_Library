class Solution {
public:
    bool helper(string &s , set<string> &set , int i , vector<int> &dp ){
        
        if(i >= s.size() ) return true ;
        
        if(dp[i] != -1) return dp[i];
        
        for(int k = 0 ; k < s.size() ; k++){
            string temp = s.substr(i , k+1);
            if(set.find(temp)!=set.end()) {
                
                bool x = helper(s , set , i+k+1,dp);
                if(x) return true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> set ; 
        for(int i = 0 ; i < wordDict.size() ; i++){
            set.insert(wordDict[i]);
        }
        vector<int> dp(s.size() + 1  , -1);
        bool ans = helper(s , set , 0  ,dp);
        return ans ; 
    }
};