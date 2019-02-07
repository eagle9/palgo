#spark-submit --master yarn-client --num-executors 512 --driver-memory 6g --executor-memory 6g  seq.py
#spark-submit --master yarn-client --num-executors 99 seq.py
spark-submit --master yarn --deploy-mode client --queue Critical --num-executors 25 --executor-cores 5 --driver-memory 6g --executor-memory 8g seq.py
#spark-submit --master yarn --deploy-mode cluster --num-executors 100 --driver-memory 16g --executor-memory 16g  seq.py
#spark-submit --master yarn-client --num-executors 37 wordcount.py twinkle.txt
#spark-submit --master yarn-client wc.py foo.txt
#spark-submit --master yarn-client wc.py #does not work
export PYSPARK_DRIVER_PYTHON=
export PYSPARK_DRIVER_PYTHON_OPTS=
spark-submit --master yarn-client wordcount.py boo.txt

