# Last updated: 8/29/2025, 9:53:31 PM
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_sorted = sorted(nums)
        i = 0
        j = len(nums) - 1
        while i!=j:
            if nums_sorted[i] + nums_sorted[j] == target:
                num1, num2 = nums_sorted[i], nums_sorted[j]
                break
            elif nums_sorted[i] + nums_sorted[j] > target:
                j = j -1 
                continue
            else:
                i = i + 1
                continue
        idx1 = nums.index(num1)
        if num1 == num2:
            idx2 = idx1 + nums[idx1+1:].index(num2) + 1
        if num1 != num2:
            idx2 = nums.index(num2)
        return [idx1, idx2]

    