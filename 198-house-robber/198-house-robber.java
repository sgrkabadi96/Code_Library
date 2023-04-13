class Solution {
    public int rob(int[] a) {
        int n = a.length ; 
        
        int prev = a[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int curr = 0;
            
            int take = a[i];
            if (i > 1)
                take += prev2;
            
            int notTake = prev;
            
            curr = Math.max(take , notTake) ;
            prev2 = prev ;
            prev = curr;
        }
        return prev; 
    }
}