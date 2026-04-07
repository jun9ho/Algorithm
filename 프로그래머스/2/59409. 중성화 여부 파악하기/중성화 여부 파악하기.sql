-- 동물의 아이디와 이름, 중성화 여부를 아이디 순으로 조회하는 SQL문을 작성
-- 중성화가 되어있다면 'O', 아니라면 'X'라고 표시
SELECT ANIMAL_ID,NAME,
    CASE
        WHEN INSTR(SEX_UPON_INTAKE,'Neutered') OR INSTR(SEX_UPON_INTAKE,'SPAYED') THEN 'O'
        ELSE 'X'
    END AS '중성화'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID