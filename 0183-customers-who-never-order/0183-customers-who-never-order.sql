# Write your MySQL query statement below
SELECT Customers.name AS Customers FROM Customers LEFT JOIN Orders ON Customers.id = ORDERs.customerId where
Orders.id is NULL