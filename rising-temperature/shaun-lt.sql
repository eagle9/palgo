#runtime 641ms, faster than 23%, mem less than 100%
# Write your MySQL query statement below
SELECT
    a.Id AS 'Id'
FROM
    weather a
        JOIN
    weather b ON DATEDIFF(a.RecordDate, b.RecordDate) = 1
        AND a.Temperature > b.Temperature
;
