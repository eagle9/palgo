class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """

        current_str = [char for char in s]

        i = 0
        j = len(s) - 1

        while i < j:
            temp = current_str[i]
            current_str[i] = current_str[j]
            current_str[j] = temp
            j -= 1
            i += 1

        return "".join(current_str)
    def reverseString2(self,s):
		#String in python is immutable
		if s!= None:
			a = list(s) #faster than a = [c for c in s]
			a.reverse() #reverse function of list is in place
			return ''.join(a)
