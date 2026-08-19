class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        sort(reservedSeats.begin(),reservedSeats.end());
        int curr=reservedSeats[0][0];
        vector<bool>b(3,true);
        int ans=n*2;
        unordered_set<int>x;
         unordered_set<int>y;
          unordered_set<int>z;
        x={2,3,4,5};
        y={4,5,6,7};
        z={6,7,8,9};

        unordered_set<int>p;
        int q=1;
        for(auto &i: reservedSeats){
            p.insert(i[0]);
            if(i[0]!=curr){
                ans-=2;
                curr=i[0];
                if(b[0])
                    ans++;
                if(b[2]) ans++;
                if(!b[0] && !b[2] && b[1])
                    ans++;
                b[0]=true;
                b[1]=true;
                b[2]=true;
                cout<<ans;
            }
            if(x.count(i[1]))
                b[0]=false;
            if(y.count(i[1]))
                b[1]=false;
            if(z.count(i[1]))
                b[2]=false;
            
        }
        ans-=2;
        if(b[0])
            ans++;
        if(b[2]) ans++;
        if(!b[0] && !b[2] && b[1])
            ans++;

        
        
        return ans;

    }
};