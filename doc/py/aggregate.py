#!/data02/swp/ana/bin/python
#developed using jupyter-notebook --no-browser --ip=1.0.131.51
#to aggregate streamsaver report
#main features:
# regex search pattern, find and extract matched substring
# validate received files with hashlib.md5 checksum
# aggregate data files with pandas dataframe append
import os
import re
import pandas as pd
import hashlib
def file_as_bytes(file):
    with file:
        return file.read()

path="/home/voy/dr/demosimplesub/received"
path2 = "/data03/stream_saver"
for fn in sorted(os.listdir(path)):
    res = re.search("^audit_.*_(\d{8}).txt",fn)
    if res:
        date1 = res.group(1)
        year = date1[0:4]
        mon = date1[4:6]

        afile = os.path.join(path,fn)
        print date1,afile
        with open(afile) as f:
            df = pd.DataFrame()
            lines = f.readlines()
            for line in lines:
                a = line.split('|')
                print  a[1],a[3]
                cksum0 = a[3]
                ssfile = os.path.join(path,a[1])
                if (cksum0 != hashlib.md5(file_as_bytes(open(ssfile, 'rb'))).hexdigest()):
                    print "Corrupted file!"
                    continue
                else:
                    print "Checksum valid."
