class Solution {
public:
     int n , m , size ;
    int dp[101][101][201] ;
    
    bool helper(string s1 , string s2 , int i , int j , string s3 , int k){
        if(k >= size) return true;
        if(i >= n && j >= m) return false;
        bool ans = false;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        if(s1[i] == s3[k] && s2[j] == s3[k]){
            bool x = false;
            x = helper(s1 , s2 , i+1 , j , s3 , k+1);
            if(x == true ) return dp[i][j][k] = 1;
            x = helper(s1 , s2 , i , j+1 , s3 , k+1);
            if(x ) return dp[i][j][k] = 1;
        } 
        else if(s1[i] == s3[k]){
            return dp[i][j][k] = helper(s1 , s2 , i+1 , j , s3 , k+1);
        } 
        
        else if(s2[j] == s3[k]){
           return  dp[i][j][k] =  helper(s1 , s2 , i , j+1 , s3 , k+1) ;
        }
        return dp[i][j][k] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        n = s1.size();
        m = s2.size();
        size = s3.size();
         if((n + m )!= size) return false;
        //cout << n << m << size;
         memset(dp ,-1, sizeof dp);
        return helper(s1 , s2 , 0 , 0 , s3 , 0);
        
    }
};