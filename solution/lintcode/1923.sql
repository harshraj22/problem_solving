-- https://www.lintcode.com/problem/1923/?showListFe=true&page=1&problemTypeId=3&ordering=level&pageSize=50

-- Write your SQL Query here --
-- example: SELECT * FROM XX_TABLE WHERE XXX --

SELECT id FROM new_cases as outer_db WHERE increased_count > 
    (SELECT increased_count FROM new_cases WHERE new_cases.date = DATE_SUB(outer_db.date, Interval 1 DAY))