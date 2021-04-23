-- https://www.codewars.com/kata/58164ddf890632ce00000220/train/sql

-- Create your SELECT statement here
SELECT age, count(id) as total_people from people group by age HAVING count(id) >= 10;