class Solution {
public:
    bool isPalindrom(string &x){
        int i = 0 ;
        int j = x.size() - 1 ;
        while(i <= j ){
            if(x[i] != x[j] ) 
                 return false;
            i++ ; 
            j--;
        }
        return true ;
    }

    
    void f(string &s, int i , vector<vector<string>> &ans, vector<string> &x  ){
        if(i >= s.size()) {
            ans.push_back(x);
            return ; 
        }
        
        // if(map.find(i) != map.end()){
        //     return map[i];
        // }
        
        for(int k = i ; k < s.size() ; k++){
            string curr = s.substr(i , k-i+1);
            if(isPalindrom(curr)){
                cout << curr << endl;
                x.push_back(curr);
                f(s , k+1 , ans , x) ; 
                x.pop_back();
            }
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ; 
        
        vector<string> x ;
        map<int , vector<string> > map ;
        f(s, 0 ,ans, x );

        return ans; 
    }
};