-- https://www.codewars.com/kata/58113c03009b4fcc66000d29/train/sql

-- Create your SELECT statement here
SELECT id, name FROM departments where departments.id in (SELECT department_id FROM sales WHERE price > 98.00);
