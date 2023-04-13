class Solution {
    
    public int f(int i , int buy , int[] p , int dp[][]) {
        int n = p.length ;
        if(i >= n ) return 0 ;
        int ans = 0 ;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 1){
            int x = f(i+1 , 0 , p , dp) - p[i];
            int y = f(i+1 , 1 , p , dp); 
            ans = Math.max(x , y) ;
        }
        else if(buy ==0 ){
            int y = f(i+1 , 0 , p , dp) ;
            int x = f(i+2 , 1 , p , dp) + p[i];
            ans = Math.max(x , y );
        }
        return dp[i][buy] =  ans ; 
    }
    public int maxProfit(int[] prices) {
        int dp[][] = new int[prices.length][2];
        
        for(int i = 0 ; i < prices.length ; i++){
            dp[i][0] = -1 ; 
            dp[i][1] = -1 ;
        }
        return f(0 , 1 , prices  , dp ) ;
        
    }
}