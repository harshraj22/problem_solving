-- https://leetcode.com/problems/customers-who-never-order/description/

# Write your MySQL query statement below
select name as Customers from customers where id not in (select customers.id from customers join orders where customers.id = orders.customerId);
