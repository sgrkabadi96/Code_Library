class Solution {
    public int helper(int i , int j , int[][] grid , int n , int m  , int dp[][]){
        if(i == n-1 && j== m-1 ) return 1 ; 
        if(i >= n || j >= m ) return 0 ; 
        if(grid[i][j] == 1 ) return 0 ;
        if(dp[i][j] != -1 ) return 0 ; 
        
        int right = helper(i + 1 , j , grid , n , m , dp);
        int down = helper(i , j+1 , grid , n , m , dp);
        
        dp[i][j] = right + down ; 
        return dp[i][j];
    }
    
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length ; 
        int m = obstacleGrid[0].length ; 
        // int [][] dp = new int[n][m]; 
        // for(int i = 0 ;i < n ; i++){
        //     for(int j = 0 ;j  < m ; j++ ) {
        //         dp[i][j] = -1 ;
        //     }
        // }
        // return helper(0 , 0, obstacleGrid , n , m  , dp);
        
        
        int down[] = new int[m];
        
        int right = 0 ; 
        
        for(int i = n-1 ; i >=0 ; i--){
            right = 0 ;
            for(int  j = m-1 ; j >= 0 ; j--) {
                if(i == n-1 && j == m-1 && obstacleGrid[i][j] == 0 ) {
                    down[j] = 1;
                    right = 1 ;
                } else {
                    if(obstacleGrid[i][j] == 1){
                        right = 0 ;
                        down[j] = 0 ;
                    } 
                    else {
                        int curr = down[j]  + right;
                        right = curr ;
                        down[j] = curr ;
                    }
                }
            }
            // System.out.println(Arrays.toString(down));
        }
        return  right ;
    }
}