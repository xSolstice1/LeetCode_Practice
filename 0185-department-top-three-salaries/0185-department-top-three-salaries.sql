# Write your MySQL query statement below
WITH CTE AS (
    SELECT
        D.NAME AS "Department",
        E.NAME AS "Employee",
        E.SALARY AS "Salary",
        DENSE_RANK() OVER (PARTITION BY D.NAME ORDER BY E.SALARY DESC) AS RN
    FROM
        EMPLOYEE E
    LEFT JOIN
        DEPARTMENT D
    ON TRUE
        AND E.DEPARTMENTID = D.ID
)

SELECT
    DEPARTMENT,
    EMPLOYEE,
    SALARY
FROM
    CTE
WHERE
    RN <= 3;