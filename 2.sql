SELECT name, COUNT(tempo) FROM songs GROUP BY tempo ORDER BY COUNT(tempo) DESC;