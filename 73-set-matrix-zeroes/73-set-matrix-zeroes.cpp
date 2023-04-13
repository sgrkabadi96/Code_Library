class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        
        set<pair<int,int>> set;
        int n = a.size();
        int m = a[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(a[i][j] == 0) set.insert({i , j});
            }
        }
        
        for(auto &p : set){
            int r = p.first;
            int c = p.second ;
            for(int i = 0 ; i < m ; i++){
                a[r][i] = 0;
            }
            for(int i = 0 ; i < n ;i++){
                a[i][c] = 0;
            }
        }
    }
};