#!/usr/bin/python
import sys
import time
from pyspark import SparkContext
from pyspark import SparkConf
from pyspark.storagelevel import StorageLevel
from cookielib import vals_sorted_by_key
import datetime
import os
import numpy as np
import zlib
def mapper(line):
    k  = line[0].split('/')[1:3]
    #print "key=",k
    return ((k[0], k[1]),1)
TA_RATIO = 78.125/16
debug = True
debug = False

os.environ['PYSPARK_PYTHON'] = '/usr/bin/python'
#py2.7 timedelta.total_seconds()

#if __name__ =="__main__":
debug=True
debug=False
date = '20150702'
NUM_PARTITIONS = 2000
path = '/user/foo/seqFile.seq'
conf = SparkConf()
conf.set('spark.yarn.dist.files','file:/home/foo/install/spark1.4/python/lib/pyspark.zip,file:/home/foo/install/spark1.4/python/lib/py4j-0.8.2.1-src.  zip')
conf.setExecutorEnv('PYTHONPATH','pyspark.zip:py4j-0.8.2.1-src.zip')
#conf.set("dynamicAllocation.enabled", "true")
#conf.set("spark.yarn.executor.memoryOverhead", 600)
conf.set("spark.executor.memory", "8g")
conf.set("spark.driver.memory", "8g")
conf.set("spark.rdd.compress", "true")
conf.set("spark.storage.memoryFraction", 1)
conf.set("spark.core.connection.ack.wait.timeout", 600)
conf.set("spark.akka.frameSize", 64)
#conf.set("spark.local.dir","/data1/hadoop")
#conf.set("spark.driver.maxResultSize","32g")
conf.setMaster("yarn-client")
sc = SparkContext(appName = "seq_file_test", conf=conf)
print "hello"
#ctr = sc.sequenceFile(path).take(2) #map(mapper)
#for (k,v) in ctr:
#    print  k
#ctr = sc.sequenceFile(path,keyClass="org.apache.hadoop.io.Text",valueClass="org.apache.hadoop.io.BytesWritable").coalesce(10).map(mapper).                  reduceByKey(lambda x,y:x+y)
ctr = sc.sequenceFile(path).map(mapper).reduceByKey(lambda x, y: x+y)
print ctr.collect()
#ctr = sc.sequenceFile(path).map(lambda x:zlib.decompress(bytes(x[1]), 16+zlib.MAX_WBITS)).take(1)
print ctr
sc.stop()

