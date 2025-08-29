# Last updated: 8/29/2025, 9:53:17 PM
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j = 1
        count = len(nums)
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                count -= 1
                continue
            nums[j] = nums[i]
            j += 1
        for i in range(count, len(nums)):
            nums[i] = None
        return count
            
            
            
                
        
                
                
        