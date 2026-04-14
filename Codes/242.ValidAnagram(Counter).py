#Author - Hariharasudhan
from collections import Counter
''' 
collection is a hashmap 
'''
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)    
