
class Solution { 
public: 
    string removeKdigits(string num, int k) { 
        if (num.length() == k) return "0"; 

        stack<char> ch; 
        for (char i : num) { 
            while (!ch.empty() && k > 0 && ch.top() > i) { 
                ch.pop(); 
                k--; 
            } 
            ch.push(i); 
        } 

        
        while (k > 0 && !ch.empty()) { 
            ch.pop(); 
            k--; 
        } 

        string result = ""; 
        while (!ch.empty()) { 
            result+=ch.top(); 
            ch.pop(); 
        } 
        reverse(result.begin(),result.end());

        int i = 0; 
        
        while (i < result.length() && result[i] == '0') { 
            i++; 
        } 
        result = result.substr(i); 

        return result.empty() ? "0" : result; 
    } 
};
