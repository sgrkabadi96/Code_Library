class Solution {
public:
    
    int maxf(int *a){
        int ans= 0;
        for(int i = 0 ; i < 26 ; i++){
            ans = max(ans , a[i]);
        }
        return ans;
    }
    
    int characterReplacement(string s, int k) {
        int f[26] ={0}; 
        int n = s.size();
        int i = 0 , j = 0 , ans= 0;
        while(i < n){
            f[s[i]-'A']++;
            while(i-j+1 - maxf(f) > k){
                f[s[j]-'A']--;
                j++;
            }
            ans = max(ans , i-j+1);
            i++;
        }
        return ans;
    }
};