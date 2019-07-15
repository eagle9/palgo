# Write your MySQL query statement below
#beats 98%
#SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId;

#beats 22%
#SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person LEFT JOIN Address USING(PersonId);

#beats 73%
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person NATURAL LEFT JOIN Address;
