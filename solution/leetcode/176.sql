-- https://leetcode.com/problems/second-highest-salary/description/

# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary FROM Employee where salary not in (SELECT MAX(salary) from Employee);
