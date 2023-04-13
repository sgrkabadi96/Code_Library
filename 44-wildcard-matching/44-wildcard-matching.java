class Solution {
    
    public boolean f(String s ,String p , int i , int j,  int [][] dp){
        int n = s.length();
        int m = p.length();
        if(i >= n && j >= m ) return true ;
        else if(j >= m) return false;
        else if(i >= n) {
            for(int jj = j ; jj < p.length() ; jj++){
                if(p.charAt(jj) != '*') return false;
            }
            return true;
        }
            
            
            
        if(dp[i][j] != -1) {
            if(dp[i][j] == 0 )return false;
            if(dp[i][j] == 1 ) return true;
        }
        
        if(s.charAt(i) == p.charAt(j)){
            return f(s , p , i+1 , j+1 , dp);
        }
        
        else if(p.charAt(j) == '?'){
            return f(s , p , i+1 , j+1, dp);
        }
        
        else if(p.charAt(j) == '*'){
            
            boolean x=  false;
            for(int k = 0 ; k <= s.length() ; k++){
                x = f(s , p , i + k  , j+1 ,dp);
                if(x == true ) return true;
            } 
        }
        dp[i][j] = 0;
        return false;
        
    }
    public boolean isMatch(String s, String p) {
        int n = s.length() ;
        int  m = p.length();
        
        int dp[][] = new int[n+1][m+1];
        
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0; j <= m ; j++){
                dp[i][j ] =-1;
            }
        }
        
        return f(s , p , 0 , 0 , dp);
        
        
    }
}