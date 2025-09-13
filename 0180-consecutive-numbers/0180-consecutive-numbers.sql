# Write your MySQL query statement below
SELECT DISTINCT
    NUM AS ConsecutiveNums
FROM (
    SELECT
        *,
        LEAD(NUM,1) OVER () AS N1,
        LEAD(NUM,2) OVER () AS N2
    FROM
        LOGS
) A
WHERE TRUE
    AND NUM=N1 AND N1=N2;