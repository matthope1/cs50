SELECT name
FROM people JOIN directors
ON id = person_id
WHERE movie_id IN (SELECT id
FROM movies JOIN ratings
ON id = movie_id
WHERE rating >= 9);
