'''
Created on Feb 10, 2015

@author: XY1267
'''
import io
def delimited(file, delimiter='\n', bufsize=4096):
    buf = ''
    while True:
        newbuf = file.read(bufsize)
        if not newbuf:
            yield buf
            return
        buf += newbuf
        lines = buf.split(delimiter)
        for line in lines[:-1]:
            yield line
        buf = lines[-1]
if __name__ == '__main__':
    s = io.StringIO(u'abcZZZdefZZZghiZZZjklZZZmnoZZZpqr')
    d = delimited(s, 'ZZZ')
    for line in d:
        print line