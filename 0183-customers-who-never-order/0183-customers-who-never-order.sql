# Write your MySQL query statement below
SELECT
    NAME AS "Customers"
FROM
    CUSTOMERS C
WHERE
    C.ID NOT IN (
        SELECT
            CUSTOMERID
        FROM
            ORDERS
    );
