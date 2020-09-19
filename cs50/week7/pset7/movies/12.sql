SELECT DISTINCT title
FROM movies JOIN stars
ON id = movie_id
WHERE id IN (SELECT movie_id
FROM stars
WHERE person_id = (SELECT id
FROM people
WHERE name = "Johnny Depp"))
AND id IN (SELECT movie_id
FROm stars
WHERE person_id = (Select id
FROm people
WHERE name = "Helena Bonham Carter"));