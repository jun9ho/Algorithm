-- 우유(Milk)와 요거트(Yogurt)를 동시에 구입한 장바구니가 있는지
-- 

SELECT CART_ID
FROM CART_PRODUCTS
WHERE INSTR(NAME,'YOGURT') AND CART_ID IN(SELECT CART_ID
                                          FROM CART_PRODUCTS
                                          WHERE INSTR(NAME,'MILK')
                                          GROUP BY CART_ID
                                          )
GROUP BY CART_ID
ORDER BY CART_ID

-- 286
-- 448
-- 578
-- 977
-- 1048
