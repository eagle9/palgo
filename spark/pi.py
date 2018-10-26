'''
https://blog.sicara.com/get-started-pyspark-jupyter-guide-tutorial-ae2fe84f594f
you still need to set up jupyter notebook

add the following to /etc/bashrc
export PYSPARK_DRIVER_PYTHON=jupyter
export PYSPARK_DRIVER_PYTHON_OPTS='notebook'
only works with anaconda2
export CONDA_HOME=/opt/anaconda2/
export $CONDA_HOME/bin:$PATH
nohup pyspark &
adlclient:8080
'''

import pyspark
import random

num_samples = 100000
def inside(p):     
    x, y = random.random(), random.random()
    return x*x + y*y < 1

count = sc.parallelize(range(0, num_samples)).filter(inside).count()
pi = 4.0* count/num_samples
print pi
sc.stop()
