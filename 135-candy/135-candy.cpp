class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> a(n);
        
        for(int i = 0 ; i < n ; i++){
            if(i == 0) {
                a[i] = 1 ;
                continue ;
            } 
            if(ratings[i] > ratings[i-1]) {
                a[i] = a[i-1] +  1 ; 
            } else {
                a[i] = 1 ;
            }
        }
        
        int prev = 1 ;
        for(int i = n-1 ; i >= 0 ; i--){
            if(i == n-1){
                continue;
            }
            if(ratings[i] > ratings[i+1]){
                a[i] = max(a[i] , prev+1);
                prev++;
            } else {
                prev = 1 ;
                a[i] = max(a[i] , prev);
            }
        }
        
        int ans= 0 ;
        for(int i = 0 ; i < n ; i++){
            ans+=a[i];
        }
        return ans;
    }
};