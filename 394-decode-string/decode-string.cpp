class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        
        for (auto i : s) {
            if (i == ']') {
                string res = "";
                
                while (!st.empty() && st.top() != "[") {
                    res = st.top() + res;
                    st.pop();
                }
                
                if (!st.empty()) st.pop(); 
                
                string num = "";
               
                while (!st.empty() && st.top() >= "0" && st.top() <= "9") {
                    num = st.top() + num;
                    st.pop();
                }
                
                int nu = stoi(num);
                string repeated = "";
                for (int j = 0; j < nu; j++) {
                    repeated += res;
                }
                st.push(repeated);
                
            } else {
                
                st.push(string(1, i)); 
            }
        }
        
        string p = "";
        while (!st.empty()) {
            p = st.top() + p;
            st.pop();
        }
        return p;
    }
};
