class Encapsulation(object):
    def __init__(self,a,b,c):
        self.public = a
        self._protected = b #only available to be accessed within the class that defines them.
        self.__private = c #only available to be accessed within the class that defines them.
