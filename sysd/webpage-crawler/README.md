lint 234. Webpage Crawler
Difficulty: Hard

http://lintcode.com/en/problem/webpage-crawler/

Implement a webpage Crawler to crawl webpages of http://www.wikipedia.org/. To simplify the question, let's use url instead of the the webpage content.

Your crawler should:

Call HtmlHelper.parseUrls(url) to get all urls from a webpage of given url.
Only crawl the webpage of wikipedia.
Do not crawl the same webpage twice.
Start from the homepage of wikipedia: http://www.wikipedia.org/
Notice

You need do it with multithreading.
You can use up to 3 threads
Example
Given

"http://www.wikipedia.org/": ["http://www.wikipedia.org/help/"]
"http://www.wikipedia.org/help/": []
Return ["http://www.wikipedia.org/", "http://www.wikipedia.org/help/"]

Given:

"http://www.wikipedia.org/": ["http://www.wikipedia.org/help/"]
"http://www.wikipedia.org/help/": ["http://www.wikipedia.org/", "http://www.wikipedia.org/about/"]
"http://www.wikipedia.org/about/": ["http://www.google.com/"]
Return ["http://www.wikipedia.org/", "http://www.wikipedia.org/help/", "http://www.wikipedia.org/about/"]

Topic: sys design, crawler

jz idea: 
实现一个网页爬虫，去模拟爬取http://www.wikipedia.org/页面，让我们简化这个问题，使用存储url替代存储网页的内容。

你的爬虫应该做：

调用 HtmlHelper.parseUrls(url) 从当前给出的这个url对用的网页内容中获取所有的urls
只爬取wikipedia这个界面，这个界面内容由LintCode模拟
相同的页面不重复爬取
初始的url为：http://www.wikipedia.org/
