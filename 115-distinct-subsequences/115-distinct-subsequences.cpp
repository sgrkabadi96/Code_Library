class Solution {
public:
    int n , m ;
    
    int dp[1001][1001];
    
    int helper(string &s , string &t , int i , int j){
        if( j == m ) return  1;
        if( i == n) return 0;
        
        int ans ;
        if(dp[i][j] != -1 ) return dp[i][j];
        if(s[i] == t[j]){
            int x = helper(s, t , i+1 , j+1);
            int y = helper(s , t , i +  1 , j);
            ans = x+ y;
        } else {
            int x = helper(s , t , i + 1 , j);
            ans =x ;
        }
        
        return dp[i][j] = ans;
    }
    
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        memset(dp , -1 , sizeof dp);
        return helper(s , t , 0 , 0);
    }
};