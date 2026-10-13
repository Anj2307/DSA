class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort()
        st=intervals[0][0]
        print(st)
        en=intervals[0][1]
        
        l=list()
        for i in range(1,len(intervals)):
            if(intervals[i][0]<=en):
                if(intervals[i][1]>en):
                    en=intervals[i][1]
            else:
                print("here")
                l.append([st,en])
                st=intervals[i][0]
                en=intervals[i][1]
        l.append([st,en])
        return l
            


        