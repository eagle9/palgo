# Write your MySQL query statement below
/*shaun first try wrong 
select product_id, year as first_year, quantity, price 
from Sales
group by product_id
order by year
limit 1
*/

/* shaun checked with 
https://zqt0.gitbook.io/leetcode/sql/1070.productsalesanalysisiii
and accepted after 1 more code changes
runtime 934ms, faster than 36%, mem less than 100%
*/
select product_id, year as first_year, quantity, price
from Sales
where 
(product_id, year) in 
(select product_id, min(year) from Sales group by product_id)

