class Solution {
public:
    
    int dp[2000][2000];
    bool isPalindrome(string &s , int i , int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++ ; j--;
        }
        return true;
    }
    
    int helper(string &s , int st, int ed){
        if(st == ed|| isPalindrome(s , st , ed )) {
            return 0;
        }
        if(dp[st][ed] != -1) return dp[st][ed];
        int ans = INT_MAX ;
        for(int i = st ; i <= ed ; i++){
            if(isPalindrome(s , st , i)){
                ans = min(ans , 1 + helper(s ,i+1 , ed));
            }
        }
        return dp[st][ed]= ans;
    }
    
    int minCut(string s) {
        memset(dp , -1 , sizeof dp);
        return helper(s, 0 , s.size() - 1);
    }
};