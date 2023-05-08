-- https://leetcode.com/problems/combine-two-tables/description/

# Write your MySQL query statement below
SELECT firstName, lastName, city, state from Person LEFT Join Address on Person.personId = Address.personId;
