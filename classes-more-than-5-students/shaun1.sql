# Write your MySQL query statement below
#runtime 200ms, faster than 59%, mem less than 100%
/*select class from 
(select class, count(distinct(student)) as count from courses
group by class 
having count >= 5) as temp_table
*/

#use where to replace having
select class from 
(select class, count(distinct(student)) as count 
from courses
group by class ) as temp_table
where count >= 5
/*
select class from 
(select class, count(*) from courses group by class)

*/
