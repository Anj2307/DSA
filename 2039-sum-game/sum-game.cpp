#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution { 
public: 
    bool sumGame(string num) { 
        int n = num.length(); 
        
        // 1. Correct substring slicing
        string left = num.substr(0, n / 2); 
        string right = num.substr(n / 2); 
        
        // 2. Count '?' on both sides
        int countl = count(left.begin(), left.end(), '?'); 
        int countr = count(right.begin(), right.end(), '?'); 
        
        // 3. Properly calculate sums of standard digits
        int suml = 0; 
        int sumr = 0; 
        for(auto i : left) { 
            if(i != '?') { 
                suml += (i - '0'); // Convert char to int safely
            } 
        } 
        for(auto i : right) { 
            if(i != '?') { 
                sumr += (i - '0'); 
            } 
        } 
        
        // 4. Return true if Bob cannot force the sums to be equal
        // This mathematically evaluates to checking if Bob's ideal replacement 
        // can compensate for the difference between the two halves.
        if((countl+countr)%2) return true;
        return (suml - sumr) != (countr - countl) * 9 / 2;
    } 
};
