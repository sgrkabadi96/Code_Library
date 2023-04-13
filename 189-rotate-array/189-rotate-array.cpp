class Solution {
public:
    
    void reverse(vector<int> &a , int i  , int j){
        while(i <= j) {
            swap(a[i] , a[j]);
            i++ ;j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int i = 0 ;
        int j = 0 ;
        k = k % nums.size();
        int n = nums.size();
        reverse(nums ,0 , n-1);
        reverse(nums , 0 , k-1);
        reverse(nums ,k , n-1);
    }
};