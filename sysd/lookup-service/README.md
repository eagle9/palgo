NON-ABSTRACT LARGE SCALE SYSTEM DESIGN真题
助教:
标签: BIG DATA 谷歌 
L同学学员
发表于 3/13/2016, 6:23:23 PM · 0个赞
新鲜出炉的面试真题！答得很差，发出来求教大神们的解法！

设计一个只读的lookup service. 后台的数据是10 billion个key-value pair, 服务形式是接受用户输入的key，返回对应的value。已知每个key的size是0.1kB，每个value的size是1kB。要求系统qps >= 5000，latency < 200ms.

server性能参数需要自己问，我当时只问了这些，可能有需要的但是没有问到的……
commodity server
8X CPU cores on each server
32G memory
6T disk

使用任意数量的server，设计这个service。


22个回答
Owen学员
发表于 3/22/2019, 12:07:45 AM · 0个赞

既然一台服务器足以存下所有的key value (一共11TB)，那我能不能把每个key-value分别放在一个文件里，然后文件名就是key name，然后把所有文件都放在一个folder下面？

然后每台服务器跑一个service。这个service 直接cd到这个folder下面找到那个文件名 打开文件直接返回？

我觉得这样做似乎有点问题。不过我分析不出问题在哪里？求大家帮忙指出错误。

1 个评论
Charlie
3/30/2019, 8:39:05 PM
首先文件说明在硬盘里，key value在硬盘太慢了吧，应该放内存

写下你的评论...
​
Charlie学员
发表于 2/10/2019, 7:13:35 AM · 3个赞
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

L同学
5/7/2019, 8:34:51 AM
谢谢总结。我还是有几个问题，如果把所有key-value分在32台机器，那每台机器就只需要320G的value存储，所以在读value的时候，硬盘指针只要在320G的范围内查找，会不会快一点（不需要10ms）。还有就是在硬盘读取这段时间，可不可能在service有些buffer的逻辑，假设硬盘读取是14ms，那就buffer 14ms内的所有request，然后下次去扫描硬盘的时候一下子把这些request的value全部一起读出来？

S同学学员
发表于 10/18/2017, 5:23:37 AM · 1个赞
后面算了每个查找要110ms（先忽略300ms这个纠正），硬盘不能并行，那每个查找必须结束才能开始下一个，为什么这里只算上了最后一次10ms的读取，而不算前面100ms的查找？都是在占用硬盘指针啊。QPS应该是1/110 = 9吧。

我觉得可以把key都放在内存中，由25台server共同分担，前面放一台master用来找到对应的key属于那个server的范围。然后server拿到后在内存中找到对应disk的offset，这样只要一次disk读取就可以。

T同学学员
发表于 10/14/2017, 6:02:27 PM · 5个赞
对陈老师的解答有两个疑问：

So total time for find the key is log(10billion) * 10ms = 100ms.

二叉搜索树应该用log2而不是log10吧，所以log2(10billion) = 30. 总搜索时间是300ms

QPS on 1 server will be 1s/10ms * 2 disk = 200

后面算了每个查找要110ms（先忽略300ms这个纠正），硬盘不能并行，那每个查找必须结束才能开始下一个，为什么这里只算上了最后一次10ms的读取，而不算前面100ms的查找？都是在占用硬盘指针啊。QPS应该是1/110 = 9吧。

一点补充：不知在面试时可不可以做一些实际工程上的假设，比如90%的读取都集中在10%的key上（如微博热搜的short url，日活跃用户的登录，etc），这样可以把常用key 来cache在内存中，只需要1T x 10% / 32G = 3台server就可以把常用key存在内存，剩下的10% QPS就用硬盘查找好了。

A同学学员
发表于 8/2/2017, 2:24:32 PM · 1个赞
So total time for find the key is log(10billion) * 10ms = 100ms.

我不太明白这里为什么需要做log(10billion)次disk seek.

在LevelDB和Cassandra里，可以用compaction来合并这些SSTable。根据https://www.datastax.com/dev/blog/when-to-use-leveled-compaction 里的数据，如果使用level-compaction，那么find-key平均只需要1.1次disk seek. 如果使用size-compaction，那么可以把所有SSTable合并成一个SSTable，也就是find-key只需要1次disk seek.

根据上面这个逻辑，find-key最多是1.1次disk seek.

L同学学员
发表于 6/25/2017, 9:46:31 AM · 0个赞
刚才Google一下 发现硬盘读写好像没法并行 看来能sequential IO确实很重要了

L同学学员
发表于 6/25/2017, 9:45:50 AM · 0个赞
一台机器8cores，读一次10ms，1s可以读 8 * 1s / 10 ms = 800 吧？读硬盘可以多核并行吧？而且IO是block的，用thread的话，QPS应该会远高于800吧？

c同学学员
发表于 3/25/2017, 6:03:37 PM · 0个赞
这个题应该怎么理解qps呢？就像b同学说的那样，一台机器可处理的qps是9，还是说只要考虑读value的10ms？

B同学学员
发表于 3/20/2017, 8:13:11 PM · 0个赞
latency is 100.5ms, so 一秒钟只能处理 1000/100.5~=9 个quests吧？所以总共需要5000/9=556台机器。
或者把key和key在harddisk上的offset存在内存里, 这样key search 的时间就可以忽略了，25台机器就够了。所有的key有1T，25太机器放不下，所以还要用大于25台机器。如果我说得不对，请各位同学老师指正。

Q同学学员
发表于 1/17/2017, 7:37:15 PM · 0个赞
it's disk seek time. 还是记一下吧 反正也没几个数。。 问面试官他应该也会告诉你，但是会显得你没准备好

马同学学员
发表于 1/17/2017, 7:35:24 PM · 0个赞
那就是读disk的一个常量延时？？面试的时候，这个表要记吗？想不起来，可以和面试官确认吗？

Q同学学员
发表于 1/17/2017, 7:31:22 PM · 0个赞
一个常数 https://gist.github.com/jboner/2841832

马同学学员
发表于 1/17/2017, 7:26:02 PM · 0个赞
请问陈老师，So total time for find the key is log(10billion) * 10ms = 100ms. 这个里面的10ms从哪里来的？


陈同学学员
发表于 11/25/2016, 8:34:55 AM · 4个赞
Credit to SG_SWE_GM 的解答
given 10 billion key-value pair
=> total key size ~ 10 billion * 0.1kB = 1T
=> total value size ~ 10 billion * 1kB = 10T

Since it's read only, so SSTable is suitable in this case rather than NoSQL.
with 6T disk , a server with two disks will be enough.

For every request, 1 value, which is 1kB needs to be returned.
According to https://fusiontables.google.com/DataSource?snapid=S523155yioc

total time for reading one value will be 10ms(disk seek) + 1kB/1MB * 30ms(reading 1kB sequentially from disk) = 10ms.
QPS on 1 server will be 1s/10ms * 2 disk = 200
required QPS support is 5000. So we need 5000/200 = 25 servers.

And for latency, there are several things need to be considered: finding the key, read the value, return the value.

Using binary search, we need log(n) times to find the key. For each time, the disk latency is 1 seek plus 1 read, reading key is really small, so can be ignored. So total time for find the key is log(10billion) * 10ms = 100ms.

Reading a key will take another disk seek , 10ms.
1 round trip in the same data center is 0.5ms.
Assume network bandwidth is 1Gbps, sending 1kB will take very short time, so it's ignored.
so total latency is 100 + 10 + 0.5 = 110.5ms.

Wan
10/1/2018, 8:35:28 PM
key 在hashtable里不是应该O(1)time 就可以找到吗？ 为什么还要binary search

glasscity
10/27/2018, 8:57:24 AM
log(10billion) * 10ms = 100ms. 为什么是以10为底的对数？

Charlie
2/10/2019, 5:24:20 AM
QPS的算法我觉得有点问题，第一是binary search的100ms也该算到qps里，这个暂且不说，两个硬盘上存的是不一样的数据，不能保证他们一直并行处理，有的时候可能很多请求都是一块硬盘上的数据，所以只能是1s/10ms = 100.

Q同学学员
发表于 11/6/2016, 10:31:52 PM · 0个赞
这个latency怎么去理解？是要自己问面试官是什么的latency 还是默认 network+disk latency？

马同学学员
发表于 4/6/2016, 1:36:52 AM · 1个赞
@L同学，@G同学算是存储的一部分吧，Google在数据存储上有很多好东西，SSTable，LevelDB（No sql），GFS（虽然现在GFS已经不用，用更强大的CFS）等等，建议学员们可以去了解一下，当然我们的《系统设计》课程也有讲这些东西，这些对于大家面试系统设计问题是非常有帮助的。而且面试官的很多系统设计问题可能来自他们实际用到的或者曾经使用过的东西。


马同学学员
发表于 4/4/2016, 2:18:33 AM · 0个赞
Google 有一个基础的数据结构 SSTable(Sorted String Table), 是一个简单的抽象，用来高效地存储大量的键-值对数据，同时做了优化来实现顺序读/写操作的高吞吐量。SSTable 就是用来支持大量的读操作。这个设计题就是让你设计SSTableService。：）

