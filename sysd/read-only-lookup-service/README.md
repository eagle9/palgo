Read only lookup service
========================
https://www.jiuzhang.com/qa/627/

设计一个只读的lookup service. 后台的数据是10 billion个key-value pair, 服务形式是接受用户输入的key，返回对应的value。已知每个key的size是0.1kB，每个value的size是1kB。要求系统qps >= 5000，latency < 200ms.

server性能参数需要自己问，我当时只问了这些，可能有需要的但是没有问到的……
commodity server
8X CPU cores on each server
32G memory
6T disk

使用任意数量的server，设计这个service。


Charlie学员
发表于 2/10/2019, 7:13:35 AM · 2个赞
我总结了SG_SWE_GM以及其他同学的解答，在此基础上我的想法如下，有问题的地方还请老师同学指正，

=> total key size ~ 10 billion * 0.1kB = 1T
=> total value size ~ 10 billion * 1kB = 10T
所以每台服务器用两块硬盘，共12T。数据结构用SSTable就好了。

充分利用内存，本来我想用binary search tree做index，但是仔细想想这个服务是只读的，而且硬盘存储键值对用的是SSTable是有序的，key和value长度又是固定的，所以直接把key以有序的方式存在内存就好了，查询的时候对key进行binary search，然后用key在内存中的offset来计算键值对在硬盘中的offset。1T/32G = 31.25. 所以一共需要32台服务器的内存分担key index。前面加一个master负责管理consistent hasing。lg(32G) = 35, 平均查询一个key就算18次内存访问，大约才1800ns，在ms这个量级上可以忽略。

每一次request，在硬盘上读取1kB value的时间：10ms(disk seek) + 4ms(rotation delay for 7200rpm) + 1kB/1MB * 30ms(reading 1kB sequentially from disk) = 14ms. 目前一台server能处理的的QPS: 1000ms/14ms = 71, 总的QPS: 71 * 32 = 2272。距离要求还有两倍多的差距。所以我们可以给每台server装上6个6T硬盘，组成3套数据硬盘，3套硬盘可以并行处理3个请求，这样也算是稍微利用了一下8X的多核CPU。这时QPS即为2272 * 3=6816.

延迟：

master内存查找consistent hashing map的时间：忽略
master与slave的round trip delay：1 round trip in the same data center is 1ms.
slave内存index查询时间：忽略
slave硬盘读取时间：14ms
so total latency is 15ms。
