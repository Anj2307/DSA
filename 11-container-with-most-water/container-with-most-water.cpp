class Solution {
public:
    int maxArea(vector<int>& height) {

        int l=0;
        int m=0;
        int r= height.size()-1;
        while(l<r){
            int p=min(height[l],height[r]);
            m=max(m,p*(r-l));
            if(height[r]<height[l])
            {
                r--;
            }else l++;
        }
        return m;
    }
};