-- Write your PostgreSQL query statement below
SELECT
    SCORE,
    DENSE_RANK() OVER (ORDER BY SCORE DESC) AS RANK
FROM
    SCORES
ORDER BY
    RANK ASC;