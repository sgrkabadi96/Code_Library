class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        vector<int> d(n , 0);
        
        for(int i = 0 ; i < n ; i++){
            d[i] = gas[i] - cost[i];
        }
        
        int sum = 0;
        bool pos = true ;
        
        int lastNegative = -1 ;
        
        for(int i = 0 ; i < n ; i++){
            sum += d[i];
            if(sum <0){
                sum = 0;
                lastNegative = i ; 
            }
        }

        for(int i = 0 ;i <=lastNegative ; i++){
            sum+=d[i];
            if(sum < 0 ) return -1;
        }
        
        if(lastNegative== -1) return 0;
        return lastNegative + 1;
        
        
    }
};