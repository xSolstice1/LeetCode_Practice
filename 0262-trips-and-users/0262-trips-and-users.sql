# Write your MySQL query statement below
SELECT DISTINCT
    REQUEST_AT AS "Day",
    ROUND(SUM(CASE WHEN STATUS LIKE '%cancelled%' THEN 1 ELSE 0 END)
    OVER (PARTITION BY REQUEST_AT)/COUNT(*) OVER (PARTITION BY REQUEST_AT),2)
    AS "Cancellation Rate"
FROM
    TRIPS T
WHERE TRUE
    AND T.CLIENT_ID NOT IN (
        SELECT
            USERS_ID
        FROM
            USERS
        WHERE
            BANNED = 'Yes'
    )
    AND T.DRIVER_ID NOT IN (
        SELECT
            USERS_ID
        FROM
            USERS
        WHERE
            BANNED = 'Yes'
    )
    AND REQUEST_AT BETWEEN '2013-10-01' AND '2013-10-03'
    ;