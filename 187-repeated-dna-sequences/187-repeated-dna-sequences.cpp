class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        map<string,int> map;
        
        
        for(int i = 0 ; i < s.size() && i + 10 <= s.size() ; i++){
            string t = s.substr(i,10);
            map[t]++;
        }
        vector<string> ans;
        for(auto &x : map){
            if(x.second > 1) ans.push_back(x.first);
        }
        return ans;
    }
};