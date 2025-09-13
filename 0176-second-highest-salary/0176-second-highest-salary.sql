# Write your MySQL query statement below
SELECT COALESCE((SELECT DISTINCT salary
FROM Employee
ORDER BY salary DESC
LIMIT 1 OFFSET 1),NULL) AS SecondHighestSalary