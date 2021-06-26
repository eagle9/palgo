/*
https://nifannn.github.io/2017/10/27/SQL-Notes-Leetcode-178-Rank-Scores/
cutting: rank is the number of distinct scores that >= this score

runtime 257ms, faster than 75%, mem less than 100%
*/
SELECT s.Score, COUNT(t.Score) AS Rank FROM
(SELECT DISTINCT Score FROM Scores) AS t, Scores AS s
WHERE t.Score >= s.Score
GROUP BY s.Id, s.Score
ORDER BY s.Score DESC;

/*
Analysis
For a score, its rank is the number of scores in the Scores table without duplicates that is larger than or equal to the score. Take above table as example, there are six scores, 3.50, 3.65, 4.00, 3.85, 4.00 and 3.65. The distinct scores are 3.50, 3.65, 3.85 and 4.00. For a score of 4.00, only 4.00 ≥ 4.00, so the rank is 1. Similarly, for a score of 3.65, 4.00 ≥ 3.65, 3.85 ≥ 3.65, 3.65 ≥ 3.65, therefore, the rank is 3.

First, we need to get all distinct scores:

1
SELECT DISTINCT Score FROM Scores;
Assuming that we call the table of distinct scores t, next we can fully join t and Scores and filter scores in t that is larger than or equal to each score in Scores:

1
2
3
SELECT s.Score, t.Score FROM
(SELECT DISTINCT Score FROM Scores) AS t, Scores AS s
WHERE s.Score <= t.Score;
For each score in Scores, count how many scores in t are larger than or equal to it:

1
2
3
4
SELECT s.Score, COUNT(t.Score) AS Rank FROM
(SELECT DISTINCT Score FROM Scores) AS t, Scores AS s
WHERE s.Score <= t.Score
GROUP BY s.Id, s.Score;
Finally, sort by score in descending order:

1
2
3
4
5
SELECT s.Score, COUNT(t.Score) AS Rank FROM
(SELECT DISTINCT Score FROM Scores) AS t, Scores AS s
WHERE s.Score <= t.Score
GROUP BY s.Id, s.Score
ORDER BY s.Score DESC;
Solution
1
2
3
4
5
SELECT s.Score, COUNT(t.Score) AS Rank FROM
(SELECT DISTINCT Score FROM Scores) AS t, Scores AS s
WHERE s.Score <= t.Score
GROUP BY s.Id, s.Score
ORDER BY s.Score DESC;
*/
