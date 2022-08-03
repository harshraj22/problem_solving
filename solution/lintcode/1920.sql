-- https://www.lintcode.com/problem/1920/?showListFe=true&page=1&problemTypeId=3&ordering=level&pageSize=50

-- Write your SQL Query here --
-- example: SELECT * FROM XX_TABLE WHERE XXX --
SELECT name FROM students group by name having count(id) > 1