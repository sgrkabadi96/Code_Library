class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        int i = 0 ; 
        int j = 0 ;
        
        int ans = 0 ;
        map<char,int> map;
        int n = s.size() ; 
        
        while(i < n ){
            char &c = s[i];
            map[c]++;
            
            if(map[c] > 1) {
                ans = max(ans , i - j );
                while(j < i && map[c] > 1){
                    map[s[j]]--;
                    j++;
                }
            }
            i++;
        }
        
        ans = max(n - j , ans);
        return ans;
    }
};