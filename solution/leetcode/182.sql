-- https://leetcode.com/problems/duplicate-emails/description/

# Write your MySQL query statement below
select email from person group by email having count(id) > 1;
