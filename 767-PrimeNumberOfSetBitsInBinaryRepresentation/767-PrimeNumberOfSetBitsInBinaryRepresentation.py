# Last updated: 5/6/2026, 5:09:21 pm
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        ans=0
        for i in range (left,right+1):
            if i.bit_count() in {2,3,5,7,11,13,17,19}:
                ans=ans+1
        return ans