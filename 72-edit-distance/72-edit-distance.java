class Solution {
    int f(String word1 , String word2 , int n , int m){
        if(n == 0) {
            return m;
        } 
        if(m == 0 ){
            return n ; 
        }
        
        int ans ; 
        
        if(word1.charAt(n-1) == word2.charAt(m-1)){
            return  f(word1 , word2 , n -1 , m-1);
        }
        else {
            int x = Integer.MAX_VALUE ;
            
            x = Math.min(x , 1 + f(word1 , word2 , n  , m-1 )); // Insert ;
            x = Math.min(x ,1 +  f(word1 , word2 , n-1  , m )) ;// Delete ; 
            x = Math.min(x , 1 + f(word1 , word2 , n-1 , m-1 ));
            ans = x ; 
        }
        return ans;
    }
    public int minDistance(String word1, String word2) {
        // convert word1 to word2 
        int n = word1.length();
        int m = word2.length();

        int dp[][] = new int[n+1][m+1];
        
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <=m ; j++){
                if(i == 0 ){
                    dp[i][j] = j;
                } else if(j == 0 ){
                    dp[i][j] = i ; 
                } else {
                    
                    if(word1.charAt(i-1) == word2.charAt(j-1)){
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        int x = Integer.MAX_VALUE ;
                        x = Math.min(x , 1 + dp[i][j-1] ) ;
                        x = Math.min(x ,1 +  dp[i -1 ][j] ) ;
                        x = Math.min(x , 1 + dp[i -1 ][j -1] )  ;
                        dp[i][j] = x;
                    }
                }
            }
        }
        
        return dp[n][m];
    }
}