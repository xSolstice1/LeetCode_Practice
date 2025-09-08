-- Write your PostgreSQL query statement below
SELECT
    MAX(SALARY) AS SecondHighestSalary
FROM
    (SELECT
        SALARY,
        DENSE_RANK() OVER (ORDER BY SALARY DESC) AS RNK
    FROM
        EMPLOYEE
    )
WHERE
    RNK = 2;