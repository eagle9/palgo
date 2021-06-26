175. Combine Two Tables
Easy 676 95 Favorite Share

SQL Schema
Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
PersonId is the primary key column for this table.
Table: Address

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
AddressId is the primary key column for this table.
 

Write a SQL query for a report that provides the following information for each person in the Person table, regardless if there is an address for each of those people:

FirstName, LastName, City, State
Accepted 173,014
Submissions 327,908

Contributor LeetCode
0 ~ 6 months6 months ~ 1 year1 year ~ 2 years
Amazon | 6 Google | 6 Apple | 5 Adobe | 3 Yahoo | 2

Similar:
Employee Bonus Easy
