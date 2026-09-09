class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_new = sorted(s)
        t_new = sorted(t)
        
        if(len(s_new) != len(t_new)):
            return False

    
        n = len(s_new)

        for i in range(0, n):
            if(s_new[i] != t_new[i]):
                return False
        
        return True