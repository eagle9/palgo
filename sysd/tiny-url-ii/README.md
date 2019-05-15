522. Tiny Url II
Difficulty: Medium

http://lintcode.com/en/problem/tiny-url-ii/

As a follow up for Tiny URL, we are going to support custom tiny url, so that user can create their own tiny url.

Notice

Custom url may have more than 6 characters in path.

Example

createCustom("http://www.lintcode.com/", "lccode")
>> http://tiny.url/lccode
createCustom("http://www.lintcode.com/", "lc")
>> error
longToShort("http://www.lintcode.com/problem/")
>> http://tiny.url/1Ab38c   // this is just an example, you can have you own 6 characters.
shortToLong("http://tiny.url/lccode")
>> http://www.lintcode.com/
shortToLong("http://tiny.url/1Ab38c")
>> http://www.lintcode.com/problem/
shortToLong("http://tiny.url/1Ab38d")
>> null

同短网址一样, 我们可以用两个哈希表处理长网址和短网址之间的相互映射关系.
我们需要额外处理的便是用户设定的网址与已有的冲突时, 需要返回 "error".
但是注意这个细节: 如果用户设定的和已有的恰好相同, 那么同样应该返回短网址.
