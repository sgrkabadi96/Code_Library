class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        
        
        vector<vector<string>> ans ;
        
        map<string,vector<int>> map ;
        
        for(int i = 0 ; i < a.size() ; i++){
            string x = a[i]; 
            sort(x.begin() , x.end());
            map[x].push_back(i);
        }
        
        for(auto &x : map){
            vector<string> v ;
            for(int &i : x.second){
                v.push_back(a[i]);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};