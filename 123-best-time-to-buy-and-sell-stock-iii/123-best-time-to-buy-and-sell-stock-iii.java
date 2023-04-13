class Solution {
    public int f(int []prices , int i , int buy , int totalTrades , int dp[][][] ){
        int n= prices.length;
        if(i >= n ) return 0;
        if(totalTrades == 2 ) return 0;
        if(dp[i][buy][totalTrades] != -1){
            return dp[i][buy][totalTrades];
        }
        int ans = Integer.MIN_VALUE ;
        if(buy == 1) {
            int x = f(prices , i+1 , 0 , totalTrades , dp) - prices[i];
            int y = f(prices , i+1 , 1 , totalTrades , dp) ;
            ans = Math.max(x , y );
        }
        else if(buy == 0) {
            int x = f(prices , i+1 , 1 , totalTrades+1 ,dp) + prices[i];
            int y = f(prices , i+1 , 0 , totalTrades , dp) ;
            ans = Math.max(x ,y);
        }
        return dp[i][buy][totalTrades] = ans;
    }
    public int maxProfit(int[] prices) {
        
        int n = prices.length; 
        
        int dp[][][] = new int[n+1][2][3];
        for(int i = 0 ; i <= n ; i++){
            for(int j  = 0 ; j < 2 ; j ++){
                for(int k =0 ; k < 3 ; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return f(prices , 0 , 1 , 0 , dp) ;
        
        
    }
}