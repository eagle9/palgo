501. Mini Twitter
Difficulty: Medium

http://lintcode.com/en/problem/mini-twitter/

Implement a simple twitter. Support the following method:

postTweet(user_id, tweet_text). Post a tweet.
getTimeline(user_id). Get the given user's most recently 10 tweets posted by himself, order by timestamp from most recent to least recent.
getNewsFeed(user_id). Get the given user's most recently 10 tweets in his news feed (posted by his friends and himself). Order by timestamp from most recent to least recent.
follow(from_user_id, to_user_id). from_user_id followed to_user_id.
unfollow(from_user_id, to_user_id). from_user_id unfollowed to to_user_id.
Example

postTweet(1, "LintCode is Good!!!")
>> 1
getNewsFeed(1)
>> [1]
getTimeline(1)
>> [1]
follow(2, 1)
getNewsFeed(2)
>> [1]
unfollow(2, 1)
getNewsFeed(2)
>> []


idea by jz:
更新于 3/12/2019, 5:35:45 AM
因为题目里涉及到对推文按照时间排序, 同时 Tweet 类本身不含时间信息, 所以我们需要额外地记录每条推文发出的时间.

可以定义一个类的静态变量作为计数器来实现.

然后分析我们需要的数据结构:

class Node {Tweet, int}; 对原有的Tweet类的扩展, 使其可以记录时间 (当然, 也可以用类的继承来实现)
map<int, vector<Node>> 用户id到这个用户发送了的推文的映射
map<int, set<int>> 用户id到这个用户关注的人的id的映射
然后对应每种方法的实现:

postTweet() 直接添加到map<int, vector<Node>>中即可
getTimeline() 根据map<int, vector<Node>>获得该用户的最新推文, 返回即可
getNewsFeed() 同时用到上面定义的两个映射, 比较暴力的做法是获取这些用户的所有推文, 排序, 拿出前十个; 或者可以利用堆进行 "多路归并"
follow() 在 map<int, set<int>> 中添加即可
unfollow() 在 map<int, set<int>> 中删除即可
(本题解使用C++相关数据结构描述, 不过映射和集合在其他语言中也有对应的实现)

