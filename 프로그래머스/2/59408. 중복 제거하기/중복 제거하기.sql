-- 동물의 이름은 몇 개인지 조회하는 SQL 문을 작성
--  NULL인 경우는 집계하지 않으며 중복되는 이름은 하나로
SELECT COUNT(DISTINCT NAME) AS COUNT
FROM ANIMAL_INS
WHERE NAME IS NOT NULL