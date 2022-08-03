-- https://www.lintcode.com/problem/1921/?showListFe=true&page=1&problemTypeId=3&ordering=level&pageSize=50

-- Write your SQL Query here --
-- example: SELECT * FROM XX_TABLE WHERE XXX --

SELECT name as player FROM users as U WHERE U.id not in (SELECT users.id FROM users inner join recharges on users.id = recharges.user_id)