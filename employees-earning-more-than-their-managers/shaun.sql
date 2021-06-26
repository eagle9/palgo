# shaun own idea with slight update after checking answer, idea is correct, outout header is required to be 'Employee'
#runtime 302ms, faster than 82%, mem less than 100%
select e.Name as 'Employee' from Employee as e, Employee as m
where e.ManagerId = m.Id and e.Salary > m.Salary
