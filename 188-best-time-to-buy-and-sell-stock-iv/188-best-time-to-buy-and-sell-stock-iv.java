class Solution {
    public int f(int []prices , int i , int buy , int totalTrades , int dp[][][]  , int k){
        int n= prices.length;
        if(i >= n ) return 0;
        if(totalTrades == k ) return 0;
        if(dp[i][buy][totalTrades] != -1){
            return dp[i][buy][totalTrades];
        }
        int ans = Integer.MIN_VALUE ;
        if(buy == 1) {
            int x = f(prices , i+1 , 0 , totalTrades , dp, k ) - prices[i];
            int y = f(prices , i+1 , 1 , totalTrades , dp , k) ;
            ans = Math.max(x , y );
        }
        else if(buy == 0) {
            int x = f(prices , i+1 , 1 , totalTrades+1 ,dp, k ) + prices[i];
            int y = f(prices , i+1 , 0 , totalTrades , dp,  k) ;
            ans = Math.max(x ,y);
        }
        return dp[i][buy][totalTrades] = ans;
    }
    public int maxProfit(int k ,int[] prices) {
        
        int n = prices.length; 
        
        int dp[][][] = new int[n+1][2][k+1];
        for(int i = 0 ; i <= n ; i++){
            for(int j  = 0 ; j < 2 ; j ++){
                for(int kk =0 ; kk < k ; kk++){
                    dp[i][j][kk] = -1;
                }
            }
        }
        return f(prices , 0 , 1 , 0 , dp, k) ;
        
        
    }
    
}