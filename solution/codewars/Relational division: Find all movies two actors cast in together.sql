-- https://www.codewars.com/kata/5817b124e7f4576fd00020a2/train/sql

-- Replace with your SQL Query


WITH selected AS (SELECT * FROM film_actor WHERE actor_id IN (105, 122)) SELECT film.title FROM film, selected
where film.film_id = selected.film_id GROUP BY film.film_id HAVING	COUNT(actor_id) = 2 ORDER BY film.title;