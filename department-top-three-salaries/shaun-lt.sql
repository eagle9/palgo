# Write your MySQL query statement below
# lt idea, cutting angle, nested query, joint department, 
# top 3 means distinct salary < 3
#runtime 708ms, faster than 60%
SELECT
    d.Name AS 'Department', e1.Name AS 'Employee', e1.Salary
FROM
    Employee e1
        JOIN
    Department d ON e1.DepartmentId = d.Id
WHERE
    3 > (SELECT   #top 3 means ---> higher distinct salary < 3 
            COUNT(DISTINCT e2.Salary)
        FROM
            Employee e2
        WHERE
            e2.Salary > e1.Salary
                AND e1.DepartmentId = e2.DepartmentId
        )
;
