-- https://www.codewars.com/kata/5943a58f95d5f72cb900006a/train/sql

/*  SQL  */
SELECT SUBSTR(project, 0, commits+1) as project, RIGHT(address, contributors) AS address FROM repositories;
