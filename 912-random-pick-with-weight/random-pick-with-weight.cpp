class Solution {
public:
    vector<int> prefix;
    int total;

    Solution(vector<int>& w) {
        total = 0;
        for(int x : w){
            total += x;
            prefix.push_back(total);
        }
    }
    
    int pickIndex() {
        int target = rand() % total + 1;
        
        int left = 0, right = prefix.size() - 1;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            
            if(prefix[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};