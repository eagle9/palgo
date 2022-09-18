import sys
if sys.version_info[0] < 3: 
    from StringIO import StringIO
else:
    from io import StringIO
import re

def get_nf_df(temp):
    
    header_list = []
    data_list = []
    for line in temp.split('\n'):
        if len(header_list) == 3 and (not line.startswith(' ')):
            data_list.append(re.split('\s+', line))
        if line.startswith('Minimum') or line.startswith('Latency') or line.startswith('Microseconds'):
            header_list.append(re.split('\s+', line))


    col_list = ['' for i in range(5)]

    for row in header_list:
        for i in range(len(row)):
            col_list[i] += ' ' + row[i]

    col_list, data_list
    df = pd.DataFrame(data = data_list, columns=col_list)
    df.dropna(inplace=True)
    return df

temp = """
$ netperf -H compute-72cores-512gbram -l 10 -t TCP_RR -w 10ms -b 1 -v 2 -- -O min_latency,mean_latency,max_latency,stddev_latency,transaction_rate
Packet rate control is not compiled in.
Packet burst size is not compiled in.
Minimum      Mean         Maximum      Stddev       Transaction
Latency      Latency      Latency      Latency      Rate
Microseconds Microseconds Microseconds Microseconds Tran/s

49           61.76        412          9.72         16174.095"""

df1 = get_nf_df(temp)
df1['env'] = 'gcp compute'

df2 = get_nf_df("""
$ netperf -H bm1 -l 10 -t TCP_RR -w 10ms -b 1 -v 2 -- -O min_latency,mean_latency,max_latency,stddev_latency,transaction_rate
Packet rate control is not compiled in.
Packet burst size is not compiled in.
MIGRATED TCP REQUEST/RESPONSE TEST from 0.0.0.0 (0.0.0.0) port 0 AF_INET to port 0 AF_INET : first burst 0
Minimum      Mean         Maximum      Stddev       Transaction
Latency      Latency      Latency      Latency      Rate
Microseconds Microseconds Microseconds Microseconds Tran/s

14           17.77        353          6.69         55990.451
""")
df2['env'] = 'bm'

df = pd.concat([df1, df2]).set_index('env')
df
