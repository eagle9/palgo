'''
Created on Jan 5, 2015

@author: XY1267
'''
import unittest
def toStr(n,base):
    convertString = "0123456789ABCDEF"
    stack = []
    while n > 0:
        if n < base:
            stack.append(convertString[n])
        else:
            stack.append(convertString[n % base])
        n = n // base
    res = ""
    while stack:
        res = res + s(stack.pop())
    return res

def toStr2(n,base):
    convertString = "0123456789ABCDEF"
    if n < base:
        return convertString[n]
    else:
        return toStr2(n//base,base) + convertString[n%base]
        
    
class test(unittest.TestCase):
    def test1(self):
        res = toStr(1453,16)
        print(res)
        self.assertEqual(res,"5AD")
    def test2(self):
        res = toStr2(1453,16)
        print(res)
        self.assertEqual(res,"5AD")
if __name__ == '__main__':
    unittest.main()
   