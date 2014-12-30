import unittest
from sorting import heapsort
 
class Test( unittest.TestCase ):
 
	def testHeapsort( self ):
		A = [8, 5, 3, 1, 9, 6, 0, 7, 4, 2, 5]
		heapsort.heapsort( A )
        
		for i in range( 1, len( A ) ):
			if A[i - 1] > A[i]:
				self.fail( "heapsort method fails." )