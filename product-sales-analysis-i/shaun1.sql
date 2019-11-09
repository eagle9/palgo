/*
runtime 1696ms, faster than 57%, mem less than 100%

cutting: use left join, join, where a.id = b.id, all works

*/
select p.product_name, s.year , s.price
#from Sales as s join Product as p #left join or not, both work
from Product as p join Sales as s#left join
on p.product_id = s.product_id
#from Sales as s, Product as p 
#where s.product_id = p.product_id
