import Encapsulation
class E2(object):
    def __init__(self,E):
        self.E = E
e = Encapsulation(11,13,17)
e2 = E2(e)
#print e.public
#print e._protected

print 'boo' + e2.E.public
print e2.E._protected
print e.__private
