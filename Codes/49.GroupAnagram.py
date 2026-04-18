# Author - Hariharasudhan A
from collections import defaultdict
class Solution(object):
    def groupAnagrams(self, strs):
        '''
        defaultdict is a collection that helps us to initialize a dictionary with whatever datatype
        '''
        anagram=defaultdict(list)
        res=[]
        
        for s in strs:
            sorted_strs=tuple(sorted(s)) # keys need to be immutable , so we use tuples
            anagram[sorted_strs].append(s) # alphabet tuples are paired with its corresponding words
        for value in anagram.values(): # only add the paired sets 
            res.append(value)

        return res
