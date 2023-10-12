select fp.product_id, fp.product_name, sum(fo.amount * fp.price) as total
from food_product fp join food_order fo on fp.product_id = fo.product_id
where YEAR(produce_date) = 2022 and MONTH(produce_date) = 5
group by fp.product_id
order by total desc, fp.product_id asc;