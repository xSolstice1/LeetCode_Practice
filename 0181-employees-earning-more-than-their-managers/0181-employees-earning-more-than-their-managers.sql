# Write your MySQL query statement below
SELECT
    A.NAME AS "Employee"
FROM
    EMPLOYEE A
JOIN
    EMPLOYEE B
ON  TRUE
    AND A.MANAGERID = B.ID
WHERE
    A.SALARY > B.SALARY;