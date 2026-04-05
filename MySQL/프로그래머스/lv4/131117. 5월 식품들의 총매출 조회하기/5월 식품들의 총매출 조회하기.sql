-- 2022년 5월인 놈들을 grouping해서 summation해야함..

SELECT PRODUCT_ID, PRODUCT_NAME, sum(PRICE * AMOUNT) as TOTAL_SALES
from FOOD_PRODUCT as P natural join FOOD_ORDER as O
where PRODUCE_DATE like '2022-05-%' -- 2022년 5월까지
group by PRODUCT_ID
order by TOTAL_SALES desc, PRODUCT_ID asc;