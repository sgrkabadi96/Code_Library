class Solution {
public:
    bool isAnagram(string s, string p) {
        
        
        int m = p.size();
        map<char,int> pmap;
        map<char,int> map;
        int n = s.size();
        vector<int> ans;
        if(n != m) return false;
        for(int i = 0 ;i < m ; i++){
            pmap[p[i]]++;
            map[s[i]]++;
        }
        
        return pmap == map;
        
        
    }
};