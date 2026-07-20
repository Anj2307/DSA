class Solution {
public:
    int minMoves(int target, int m) {
        
       int n=0;
       if(m==0) return target-1;

        while(target!=1){
            if(m==0) {
                n+=target-1;
                break;
            }
            if(target%2==0 && m>0){
                target/=2;
                m--;
            }
            else if(target%2==1){
                target-=1;
            }
            else target-=1;

            n++;
        }
        return n;

    }
};