'''
$nohup hbase thrift &
'''
import happybase
connection = happybase.Connection('localhost')
#table = connection.table('test-table')
connection.create_table(
    'mytable',
    {'cf1': dict(max_versions=10),
     'cf2': dict(max_versions=1, block_cache_enabled=False),
     'cf3': dict(),  # use defaults
    }
)
print (connection.tables())
table=connection.table('mytable')
table.put(b'row-key', {b'cf1:qual1': b'value1', b'cf1:qual2': b'value2'})
row = table.row(b'row-key')
print(row[b'cf1:qual1'])   # prints the value of cf1:col1


