-- group by product_code / 판매가 : sum(sales_amount * price)
SELECT PRODUCT_CODE, sum(SALES_AMOUNT) * PRICE as SALES
from PRODUCT as P join OFFLINE_SALE as O using (PRODUCT_ID)
group by (PRODUCT_CODE)
order by SALES desc, PRODUCT_CODE