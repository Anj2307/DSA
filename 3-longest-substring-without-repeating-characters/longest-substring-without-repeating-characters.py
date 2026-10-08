class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        si=set()
        l=0
        mx=0
        for i in range(len(s)):
            if(s[i] not in si):
                si.add(s[i])
                mx=max(mx,i-l+1)
            else:
                mx=max(mx,i-l)
                while(s[l]!=s[i]):
                    si.remove(s[l])
                    l+=1
                l+=1
                si.add(s[i])
        return mx





        