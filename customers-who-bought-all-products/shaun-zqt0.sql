/* shaun first try --- wrong answer ---
checked with zqt0, add distinct(product), accepted
runtime 384ms, faster than 53%, mem less than 100%
*/
/*
select customer_id from 
(select customer_id, count(distinct(product_key)) as np
from Customer
group by customer_id) as temp_table
where np = (select count(distinct(product_key)) from Product)
*/

/* zqt0 use groupby having, which is faster
runtime 355ms, faster than 92%, mem less than 100% */
select customer_id from Customer
group by customer_id
having count(distinct(product_key)) = (select count(distinct(product_key)) from Customer)
