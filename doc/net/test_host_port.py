import socket
host1 = '104.183.240.15'
host_list_str = '%s:22,%s:21,%s:9000' % (host1,host1,host1)
host_list = host_list_str.split(',')
for x in host_list:
    (host,port1) = x.split(':')
    port = int(port1)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    result = sock.connect_ex((host,port))
    print host,port
    if result == 0:
        print "Host %s Port %d is open" % (host,port)
    else:
        print "Host %s Port %d is not open" % (host,port)
