-- 코드를 입력하세요
-- 동물의 생물 종, 이름, 성별 및 중성화 여부 SELECT
-- 아이디순 ORDER BY
--  이름이 없는 동물의 이름은 "No name"으로 표시
SELECT ANIMAL_TYPE,IFNULL(NAME,'No name'),SEX_UPON_INTAKE
FROM ANIMAL_INS
ORDER BY ANIMAL_ID