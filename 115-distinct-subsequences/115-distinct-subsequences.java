class Solution {
    
    public int f(String s , String t , int n , int m ){
        if(m == 0) return 1;
        if(n == 0 ) return 0 ; 
        
        
        int ans = 0 ;
        if(s.charAt(n-1) == t.charAt(m-1) ) {
            ans = f(s , t , n-1 , m -1 ) + f(s ,t , n -1  , m ) ;
        }
        else {
            ans = f(s ,t , n -1  , m);
        }
        return ans ; 
        
    }
    public int numDistinct(String s, String t) {
        int n = s.length();
        int m = t.length();
        
        int dp[][] = new int[n+1][m+1];
        
        for(int i = 0 ; i <= m ; i++){
            dp[0][i] = 0 ;
        }
        
        for(int i =  0 ; i <= n ; i++){
            dp[i][0] = 1 ;
        }
        
        for(int i = 1 ; i <= n ;i++){
            for(int j = 1 ; j <= m ; j++){
                int ans = 0 ;
                if(s.charAt(i-1) == t.charAt(j-1) ) {
                    ans = dp[i-1][j-1] + dp[i-1][j] ; 
                }
                else {
                    ans = dp[i-1][j];
                }
                dp[i][j] = ans ; 
            }
        }
        
        return dp[n][m];
    }
}