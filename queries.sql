SELECT building.name FROM building, city, country 
WHERE country.Name='Poland' AND country.CountryID = city.CountryID AND city.CityID = building.CityID

SELECT country.name, country.CountryID FROM building, city, country 
WHERE city.Population > 400 AND country.CountryID = city.CountryID AND city.CityID = building.CityID 

SELECT * FROM country WHERE 0 = (SELECT COUNT(1) FROM City JOIN building ON building.CityID = city.CityID 
WHERE city.CountryID = country.CountryID)
