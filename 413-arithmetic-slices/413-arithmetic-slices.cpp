class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        
        int ans = 0 ;
        
        if(a.size() < 2 ) return 0 ; 
        int c = 0 ;
        for(int i = 2 ; i < a.size() ; i++){
            if(a[i-2]-a[i-1] == a[i-1]-a[i]) {
                c++;
            } else {
                c = 0;
            }
            ans+=c;
        }
        return ans ; 
    }
};