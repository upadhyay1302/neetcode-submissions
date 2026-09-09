class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * (2 * n)
        i = 0
        for num in nums:
            ans[i] = ans[i + n] = num
            # ans[i + n] = num
            i += 1
        return ans