#Author - Hariharasudhan
from collections import Counter
''' 
counter is a hashmap , counts and matches key : value pair accordingly 
'''
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)    
