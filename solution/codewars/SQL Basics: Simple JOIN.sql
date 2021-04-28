-- https://www.codewars.com/kata/5802e32dd8c944e562000020/train/sql

-- Create your SELECT statement here

SELECT products.id, products.name, products.isbn, products.company_id, products.price, companies.name as company_name FROM products, companies WHERE products.company_id = companies.id;