class Solution {
public:
    map<pair<int,int> , bool> map ;
    
    bool helper(int i , int n , vector<int> &a , int prev){
        if(i >= n-1 ) return true;
        int currstone = a[i];
        if(map.find({i , prev })!= map.end()) return map[{i , prev}] ; 
        for(int curr = prev-1 ; curr <= prev+1 ; curr++){
            if(curr <= 0) continue ;
            for(int k = i+1 ; k < n ; k++){
                if(currstone + curr == a[k]){
                    bool ans = helper(k , n , a , curr);
                    if(ans) return true;
                }
            }
        }
        map[{i , prev}]  = false;
        return false;
    }
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        return helper(0 , n , stones , 0);
    }
};