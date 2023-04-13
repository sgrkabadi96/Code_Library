class Solution {
public:
    string minWindow(string s, string t) {
        
        
        map<int,int> tmap ; 
        
        for(int i = 0 ; i < t.size() ; i++){
            tmap[t[i]]++;
        }
        
        map<int,int> map ; 
        int n = s.size();
        int m = t.size();
        int i = 0 ;
        int j = 0;
        int matchCount = 0 ;
        
        string ans= "" ;
        int anssize = INT_MAX ;
        
        while(i < n && j < n){
            
            // accuire 
            if(map[s[i]] < tmap[s[i]]) matchCount++;
            map[s[i]]++;
            
            
            // start releasing 
            if(matchCount == m) {
                int currsize = i - j + 1;
                if(currsize < anssize) {
                    anssize = currsize ;
                    ans = s.substr(j , anssize);
                    
                }
                while(j < i ){
                    char c = s[j];
                    if(map[c] > tmap[c]) {
                        int cs = i - j ;
                        if(cs < anssize) {
                            anssize = cs ;
                            ans = s.substr(j+1,cs);
                        }
                        map[c]--;
                    } else {
                        matchCount--;
                        map[c]--;
                        j++;
                        break;
                    }
                    j++;
                }   
            }
            // end of releasing loop
            
            i++;   
        }
     
        return ans;
        
    }
};