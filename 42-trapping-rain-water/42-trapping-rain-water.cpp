class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> leftmax(n );
        vector<int> rightmax(n );
        int maxleft = h[0];
        for(int i = 1 ; i < n ; i++){
            leftmax[i] = maxleft;
            maxleft = max(maxleft , h[i]);
        }
        int maxright = h[n-1];
        for(int i = n-2; i >=0 ; i--){
            rightmax[i] = maxright;
            maxright = max(maxright , h[i]);
        }
        
        int ans = 0;
        
        for(int i= 0 ; i < n ; i++){
            int x = min(rightmax[i] , leftmax[i]);
            if(x <= h[i]) continue;
            ans += x - h[i];
        }
        return ans;
    }
};