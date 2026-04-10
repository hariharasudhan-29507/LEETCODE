from collections import defaultdict
class Solution(object):
    def groupAnagrams(self, strs):
        
        anagram=defaultdict(list)
        res=[]
        
        for s in strs:
            sorted_strs=tuple(sorted(s))
            anagram[sorted_strs].append(s)
        for value in anagram.values():
            res.append(value)

        return res
