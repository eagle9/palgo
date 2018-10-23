#!/usr/bin/python
import sys
from pyspark import SparkContext
from pyspark import SparkConf
from pyspark.storagelevel import StorageLevel
import numpy as np
import zlib

EVENT_NAME = 'INTERNAL_PROC_S1_SIG_CONN_SETUP'
eventFields = {
    'INTERNAL_PROC_ERAB_RELEASE': [18, 25, 26, 27],
    'INTERNAL_PROC_ERAB_SETUP': [12, 13, 19, 20],
    'INTERNAL_PROC_INITIAL_CTXT_SETUP' : [12, 13, 20, 21],
    'INTERNAL_PROC_UE_CTXT_RELEASE': [17, 21, 22, 23],
    'INTERNAL_PROC_HO_PREP_S1_IN': [17, 18, 19],
    'INTERNAL_PROC_HO_PREP_X2_IN' : [18, 19, 20],
    'INTERNAL_PROC_RRC_CONN_SETUP': [12, 13],
    'INTERNAL_PROC_S1_SIG_CONN_SETUP' : [13]}

#os.environ['PYSPARK_PYTHON'] = '/usr/bin/python'
#py2.7 timedelta.total_seconds()

#NUM_PARTITIONS = 2000
path = '/user/mfoo/20160318tmp/seqFile.seq'
conf = SparkConf()
conf.set('spark.yarn.dist.files','file:/home/wfoo/install/spark1.4/python/lib/pyspark.zip,file:/home/wfoo/install/spark1.4/python/lib/py4j-0.8.2.1-src.  zip')
conf.setExecutorEnv('PYTHONPATH','pyspark.zip:py4j-0.8.2.1-src.zip')
#conf.set("dynamicAllocation.enabled", "true")
conf.set("spark.yarn.executor.memoryOverhead", 8192)
conf.set("spark.yarn.driver.memoryOverhead", 8192)
#conf.set("spark.executor.memory", "6g")
#conf.set("spark.driver.memory", "6g")
conf.set("spark.rdd.compress", "true")
conf.set("spark.storage.memoryFraction", 1)
conf.set("spark.core.connection.ack.wait.timeout", 600)
conf.set("spark.akka.frameSize", 50)
#conf.set("spark.local.dir","/data1/hadoop")
#conf.set("spark.driver.maxResultSize","32g")
#conf.setMaster("yarn-client")
sc = SparkContext(appName = "hpa_stats", conf=conf)
evt = sc.broadcast(EVENT_NAME)
fld = sc.broadcast(eventFields[EVENT_NAME])

def filter_event(line):
    filename = line[0].split('/')
    if (filename[2] == evt.value) and (filename[1] == "VTC"):
        return True
    else:
        return False

def extractHPA(line):
    #to be used in flatMap
    tup = []
    rows = zlib.decompress(bytes(line[1]), 16+zlib.MAX_WBITS).split('\n')
    for r in rows:
        event_log = r.split(',')
        try:
            flds = [event_log[i] for i in fld.value]
            tup.append(','.join(flds))
        except:
            pass
    return tup
print("start to process "+EVENT_NAME+'... with ...'),
print (eventFields[EVENT_NAME])

#ctr = sc.sequenceFile(path).filter(filter_event).flatMap(extractHPA)
#output = ctr.map(lambda k: (k,1)).reduceByKey(lambda x, y: x+y).collect()
#output = sorted(output, key=lambda x : x[1], reverse = True)
#ctr = sc.sequenceFile(path).filter(filter_event).flatMap(extractHPA).take(10)
output = sc.sequenceFile(path).filter(filter_event).flatMap(extractHPA).map(lambda k:(k,1)).reduceByKey(lambda x, y:x+y).collect()
print output
with open('tmp/'+EVENT_NAME+'.csv','wb') as f:
    for c in output:
        f.write(c[0]+','+str(c[1])+'\n')
sc.stop()
print("completed")

