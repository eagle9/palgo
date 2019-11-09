# Write your MySQL query statement below
/*
runtime 388ms, faster than 35%, mem less than 100%
count(*) does not work

*/
select dept_name , count(student_id) as student_number
from department left outer join
    student on department.dept_id = student.dept_id
group by department.dept_name 
order by student_number desc, department.dept_name

#works, dept_name only in department, so no prefix is okay
#dept_id occur both in department and student
select dept_name , count(student_id) as student_number
from department left outer join
    student on department.dept_id = student.dept_id
group by dept_name
order by student_number desc, dept_name
