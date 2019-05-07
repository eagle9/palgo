题目：设计餐馆 II

不能订外卖

能预订座位

MAX_DINETIME 为 2， 意为占用一桌吃饭的最大时长为2小时

如果餐桌被预定，则无法入座

餐馆的桌子有不同大小

餐馆会优先选择适合当前Party最小的空桌

相对设计餐馆 I，Table新增functions 需要实现。相关函数之后会调用restaurantDescription, 来验证你的程序是否正确。

在线评测地址: http://www.lintcode.com/problem/restaurant-ii-oo-design/

Restaurant II OO Design
=======================
No food delivery.

You can reserve seats.

MAX_DINETIME = 2， which mean the maximum time for a meal is 2 hours

If the table has been reserved, it could not be assigned to another party.

The table has different size

The restaurant will choose the smallest table which fit the numbers of people(For example, if the party has 3 people, the restaurant would assign a 4-people table instead of a 10-people table)

Different from Restaurant I，you have to implement new functions in "Table". The function restaurantDescription, will be called to test your program.

在线评测地址: http://www.lintcode.com/problem/restaurant-ii-oo-design/
