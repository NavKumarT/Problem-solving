# Last updated: 8/29/2025, 9:53:19 PM
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = 0 
        count = len(nums)
        for i in range(len(nums)):
            if nums[i] == val:
                count -= 1
                continue 
            nums[j] = nums[i]
            j += 1
        return count 