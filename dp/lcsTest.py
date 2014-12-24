import unittest
from dp import lcs as subsequence
 
class Test( unittest.TestCase ):
 
  def testLCS( self ):
    fibonacci = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377,
                  610, 987]
    prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
              59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103]
    rand = [0, 1, 21, 45, 144, 610, 987]
    bad = [102, 104, 106, 108, 110, 112, 114]
 
    exp1 = [89, 13, 5, 3, 2]
    exp2 = [987, 610, 144, 21, 1, 0]
 
    # no shared end points
    actual = subsequence.LCS( fibonacci, prime )
    self.assertEquals( exp1, actual )
 
    # share both end points
    actual = subsequence.LCS( fibonacci, rand )
    self.assertEquals( exp2, actual )
 
    # share no points
    actual = subsequence.LCS( fibonacci, bad )
    self.assertEquals( 0, len( actual ) )
 
    # share all points
    actual = subsequence.LCS( fibonacci, fibonacci )
    actual.reverse()
    self.assertEquals( fibonacci, actual )
