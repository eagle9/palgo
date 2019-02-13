'''
Created on Feb 6, 2015

@author: XY1267
'''

res = []
def permuteGen(elements):
    if len(elements) <=1:
        yield elements
    else:
        for perm in permuteGen(elements[1:]):
            for i in range(len(elements)):
                # nb elements[0:1] works in both string and list contexts
                yield perm[:i] + elements[0:1] + perm[i:]

def permuteUnique(elements):
    if len(elements) <=1:
        res  = []
        res.append(elements)
        #compare to implementation with generator, return a list of list
        return res
    else:
        res = []
        dict1 = {}
        for perm in permuteUnique(elements[1:]):
            
            for i in range(len(elements)):
                # nb elements[0:1] works in both string and list contexts
                #yield perm[:i] + elements[0:1] + perm[i:]
                #print perm
                x = perm[:i] + elements[0:1] + perm[i:]
                #list is mutable, non hashable type
                if s(x) not in dict1:
                    res.append(x )
                    dict1[s(x)] = True
        return res
                    
def yperm(list1):  
    if len(list1) < 2:
        yield list1
    else:
        #smaller list permutation done
        for p in yperm(list1[1:]):
            #insert list[0:1] into p
            for i in range( len(list1)):
                yield p[:i] + list1[0:1] + p[i:]
                
if __name__ == '__main__':
    s = ['1','1','2']
    
    print "permuteUnique unique"
    res = permuteUnique(s)
    #print len(res)
    for i in res: print i
    #print res
    print "end"
    
    for i in permuteGen(s):
        print i
    print "my version"
    for i in yperm(s):
        print i
    
    for i in yperm('asop'):
        print i
    s = '112'
    res = []
    for i in yperm(s):
        res.append(i)
    print res
    print set(res)
      