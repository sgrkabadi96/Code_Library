class Solution {
public:
    bool wordPattern(string p, string s) {
        
        map<char,string> map ;
        
        set<string> set;
        int n = p.size();
        int m = s.size();
        int j = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            string currs = "";
            while(j < s.size() && s[j] != ' ' ){
                currs += s[j];
                j++;
            }
            j++;
            if(j >= m && i < n-1) return false;
            if(map.find(p[i]) != map.end()){
                if(currs != map[p[i]]) return false;
                else continue;
            }
            if(set.find(currs) != set.end()) return false;
            map[p[i]] = currs;
            set.insert(currs);
        }
        if(j < m) return false;
        return true;
    }
};