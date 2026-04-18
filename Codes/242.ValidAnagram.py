class Solution(object):
    def isAnagram(self, s, t):
    
        if len(s) != len(t): # if length varies then there is no chance on having same set of alphabets
            return False
        countS,countT = {},{} 
        for i in range(len(s)): # counting every single alphabet and storing it as value to key pair , alphabet : count
            countS[s[i]] =1+countS.get(s[i],0)
            countT[t[i]] =1+countT.get(t[i],0)
        # get() returns default value if it doesnot exist in hashmap , instead of throwing a error 
        for c in countS: # checking the counts 
            if countS[c] != countT.get(c,0):
                return False
        return True
