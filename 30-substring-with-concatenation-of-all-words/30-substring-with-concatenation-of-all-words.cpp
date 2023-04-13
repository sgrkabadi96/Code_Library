class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string , int> wMap;
        map<string ,int> map;
        int n = words.size();
        int totalS = n * words[0].size();
        for(auto &x : words) wMap[x]++;
        int i = totalS-1 ;
        int j= 0 ;
        vector<int> ans;
        while(i < s.size() ){
            for(int k = j ; k <= i ; k+= words[0].size()){
                string t = s.substr(k ,words[0].size());
                map[t]++;
            }
            if(map == wMap) ans.push_back(j);
            i++; j++;
            map.clear();
        }
        return ans;
    }
};