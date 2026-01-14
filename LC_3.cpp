
//LC_3 --- longest substr widout rep chars 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        unordered_set<char> st;
        for(int j = 0;j<n;j++){
            if(st.count(s[j])){
                while(st.count(s[j])){
                    st.erase(s[i]);
                    i++;
                }
            }
            st.insert(s[j]);
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};