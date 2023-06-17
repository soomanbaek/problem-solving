-- 코드를 입력하세요
SELECT ingredient_type AS INGREDIENT_TYPE, SUM(total_order) AS TOTAL_ORDER
FROM first_half 
LEFT OUTER JOIN icecream_info
ON first_half.flavor = icecream_info.flavor
GROUP BY(ingredient_type)