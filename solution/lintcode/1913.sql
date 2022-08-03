-- https://www.lintcode.com/problem/1913/?showListFe=true&page=1&problemTypeId=3&ordering=level&pageSize=50

-- Write your SQL Query here --
-- example: SELECT * FROM XX_TABLE WHERE XXX --
SELECT student_name, phone, hometown, address FROM students left join enrollments on students.id = enrollments.student_id