class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0 ) return 0 ;
        stack<int> st ; 
        
        for(int i = 0 ; i < s.size() ; i++){
             if(st.size() > 0 &&  s[st.top()]== '(' && s[i] == ')'  ) {
                st.pop(); 
            } else {
                st.push(i);
            }
        }
        
        int ans = 0 ; 
        
        vector<int> a ; 
        while(st.size() != 0 ){
            a.push_back(st.top());
            st.pop();
        }
        if(a.size() == 0 ){
            return s.size() ; 
        }
        reverse(a.begin() , a.end());
        
        ans = max(ans , a[0] ) ; 
        
        for(int i = 0 ; i < a.size() -1;i++){
            int s = a[i]  +1 ; 
            int e = a[i+1] - 1 ;
            ans = max(ans , abs(e - s + 1));
        }
        int e = a.back() ;
        int diff =  s.size() - e -1;
        ans = max(ans , diff );
        
        
        return ans ; 
    }
};