-- Beecrownd 2605
SELECT products.name AS product_name, providers.name AS provider_name
FROM products INNER JOIN providers 
ON products.id_providers = providers.id 
WHERE providers.name = "Ajax SA";

-- Beecrownd 2607
SELECT city FROM providers ORDER BY city ASC;

-- Beecrownd 2909
SELECT name
FROM products
GROUP BY id_categories
ORDER BY SUM(id_categories) ASC;

-- Beecrownd 2611
SELECT movies.id, movies.name FROM movies
INNER JOIN genres ON movies.id_genre = genres.id 
WHERE genres.description = "Action";

-- Beecrownd 2614
SELECT customers.name, rentals.rentals_date FROM customers
INNER JOIN rentals ON rentals.id_customers = customers.id 
WHERE MONTH(rentals.rental_date) = "09" AND YEAR(rentals.rental_date) = "2016";

--Beecrownd 2006
SELECT products.id, products.name FROM products
INNER JOIN categories ON products.id_category = categories.id
WHERE categories.name LIKE '%super%';
