#adapted from jz java, Your submission beats 98.97% Submissions!
#not quite understand
class Solution:
    '''
     * @param str a string
     * @return all permutations
    '''
    def stringPermutation2(self, str1):
        # Write your code here
        result = []
        s = [c for c in str1]
        s.sort()
        result.append(''.join(s))
        while True:
            s = self.nextPermutation(s)
            if s == None:
                break
            result.append(''.join(s))
        return result

    def nextPermutation(self, nums):
        index = -1
        for i  in range(len(nums) -1, 0, -1):
            if nums[i] > nums[i-1]:
                index = i-1
                break
        if index == -1:
            return None

        for i  in range(len(nums) -1, index, -1):
            if nums[i] > nums[index]:
                temp = nums[i]
                nums[i] = nums[index]
                nums[index] = temp
                break
        self.reverse(nums,index+1,len(nums)-1)
        return nums


    def reverse(self, num, start, end):
        i, j = start, end
        while i < j:
            num[i],num[j] = num[j],num[i]
            i+=1
            j-=1
