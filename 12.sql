
SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name == "Kevin Bacon" and birth == 1958);


SELECT movie_id FROM stars WHERE person_id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name == "Kevin Bacon" and birth == 1958);
)