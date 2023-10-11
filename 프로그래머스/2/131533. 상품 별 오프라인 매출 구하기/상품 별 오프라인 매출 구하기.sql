select p.product_code, sum(p.price * os.sales_amount) as total
from product p join offline_sale os on p.product_id = os.product_id 
group by p.product_id
order by total desc, p.product_code asc;