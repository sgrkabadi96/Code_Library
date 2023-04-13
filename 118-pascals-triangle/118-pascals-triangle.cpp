class Solution {
public:
    
    vector<vector<int>> generate(int n) {
        if(n == 1){
            vector<vector<int>> b;
            b.push_back({1});
            return b;
        }
       
        vector<vector<int>> sans = generate(n-1);
        vector<int> lastrow = sans.back();
        vector<int> x ;
        x.push_back(1);
        for(int i = 0 ; i < lastrow.size()-1 ; i++){
            x.push_back(lastrow[i]+lastrow[i+1]);
        }
        x.push_back(1);
        sans.push_back(x);
        return sans;
        
    }
};