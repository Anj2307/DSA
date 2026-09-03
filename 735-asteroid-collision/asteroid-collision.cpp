class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto i : asteroids) {
            bool destroyed = false;
            while (!st.empty() && st.top() > 0 && i < 0) {
                if (abs(st.top()) < abs(i)) {
                    st.pop();
                    continue;
                } else if (abs(st.top()) == abs(i)) {
                    st.pop();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                st.push(i);
            }
        }
        
        vector<int> vec;
        while (!st.empty()) {
            vec.push_back(st.top());
            st.pop();
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
