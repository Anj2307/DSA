class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;
        int j=0;
        if(name[0]!=typed[0]) return false;
        while(i<name.size() && j<typed.size()){
            if (name[i]==typed[j]){
                i++;
                j++;
            }
            else if(typed[j]!=typed[j-1])
                return false;
            else j++;
            
        }
        if(i!=name.size()) return false;
        for(int k=j;k<typed.size();k++){
            if(typed[k]!=typed[j-1]) return false;
        }
        return true;
        
    }
};
