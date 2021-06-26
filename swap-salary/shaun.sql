# Write your MySQL query statement below
#https://www.cnblogs.com/wxisme/p/7516699.html
#beats 65%
update salary set sex= case sex when 'f' then 'm' else 'f' end
