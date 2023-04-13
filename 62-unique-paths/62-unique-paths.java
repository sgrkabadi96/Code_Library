class Solution {
    public int uniquePaths(int n, int m) {
        int down[] = new int[m];
        
        int right = 0 ;
        
        for(int i = n-1 ; i>= 0 ; i--){
           right =  0;
            for(int j = m-1 ; j >= 0 ; j-- ){
                
                if(i == n-1 && j == m-1 ) {
                    right = 1 ; 
                    down[j] = 1;
                } else {
                    int curr = right + down[j];
                    down[j] = curr ;
                    right = curr;
                }
            }
           
        }
        return right ; 
    }
}