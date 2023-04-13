class Solution {
public:
    
    int f(vector<vector<int>> & a, int n , int mid){
        int eleLessMid = 0 ;
        for(int i = 0 ; i < n ; i++){
            int s = 0 , e = n-1 ;
            while(s <= e){
                int m  = s + (e -s )/ 2 ;
                if(a[i][m] <= mid) s = m + 1;
                else e = m - 1;
            }
            eleLessMid += s;
        }
        return eleLessMid;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int s = matrix[0][0] , e = matrix[n-1][n-1];
        
        while(s <= e){
            int mid = s + (e -s )/ 2 ;
            int eleLessthanmid = f(matrix , n, mid) ;
            if(eleLessthanmid  < k) s = mid + 1 ;
            else e = mid - 1;
        }
        return s ; 
        
    }
};