SELECT
    homeTeamName,
    COUNT(1) AS homeTeamNameCount,
FROM `bigquery-public-data.baseball.games_wide`
GROUP BY 1
ORDER BY 1


