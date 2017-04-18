# Time:  O(n)
# Space: O(n)

# Description:
#
# Count the number of prime numbers less than a non-negative number, n
#
# Hint: The number n could be in the order of 100,000 to 5,000,000.


class Solution:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n <= 2:
            return 0
        
        is_prime = [True] * n
        num = n / 2
        for i in xrange(3, n, 2):
            if i * i >= n:
                break

            if not is_prime[i]:
                continue

            for j in xrange(i*i, n, 2*i):
                if not is_prime[j]:
                    continue

                num -= 1
                is_prime[j] = False

        return num

    def countPrimes2(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 3:
            return 0
        primes = [True] * n
        primes[0] = primes[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                primes[i * i: n: i] = [False] * len(primes[i * i: n: i])
        return sum(primes)

'''
This is a classic algorithm question.  Here I'd like to introduce one of the famous algorithm called "Sieve of Eratosthenes." The general idea is to use a "sieve", to filter the numbers form 2 to n, each time, we get the next prime number in the array, and remove the multiples of this prime number. Iterating this process until the square of next prime number is greater than the last number n.  The numbers now left in the array are all primes.

In this problem, just be careful that the last number is not included.

According to the literature, the time complexity of this algorithm is nloglogn. Details of the analysis can be found in the wikipedia page here.
'''
class Solution2:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        num=[1 for x in range(n)] 
        i = 2
        while i * i < n:
            j = 2
            while j*i < n:
                num[j*i] = 0 #i*j not prime, sifted
                j += 1
            i += 1
            while num[i] == 0 and i * i < n:
                i += 1
                 
        return sum(num[2::])
