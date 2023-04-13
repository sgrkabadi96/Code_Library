class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size() ;
        
        vector<int> bits(n , 0);
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(char &c : words[i]) {
                bits[i] = bits[i] | 1 << (c - 'a');
            }
            
            for(int j = 0 ; j < i ; j++){
                if((bits[i] & bits[j]) == 0){
                    if((words[i].size() * words[j].size()) > ans){
                        ans = words[i].size() * words[j].size();
                    }
                }
            }
        }
        return ans ; 
    }
};