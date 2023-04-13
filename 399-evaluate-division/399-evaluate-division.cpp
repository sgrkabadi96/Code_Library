class Solution {
public:
    double dfs(unordered_map<string , unordered_map<string, double>> &m , string s , string e  , set<string> set ) {
        if(m[s].count(e)){
            return m[s][e];
        }
        set.insert(s);
        for(auto i : m[s]){
            if(set.find(i.first) == set.end()){
                double temp = dfs(m , i.first , e , set);
                if(temp) return temp * i.second;
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& values, vector<vector<string>>& q) {
        
        unordered_map<string,unordered_map<string,double> > m;
        
        for(int i = 0 ; i < e.size() ; i++){
            m[e[i][0]].insert( {e[i][1] , values[i]} );
            m[e[i][1]].insert( {e[i][0] ,1 / values[i]} );
        }
        
        vector<double> ans ;
        
        for(auto i : q){
            set<string> set ;
            double temp = dfs(m , i[0] , i[1] , set);
            if(temp!=0) {
                ans.push_back(temp);
            } else ans.push_back(-1);
        }
        
        return ans;
    }
};