-- https://www.codewars.com/kata/58113a64e10b53ec36000293/train/sql

-- Create your SELECT statement here
-- https://www.geeksforgeeks.org/sql-exists/
SELECT * FROM departments WHERE EXISTS ( SELECT * FROM sales WHERE departments.id = sales.department_id AND sales.price > 98.00 );