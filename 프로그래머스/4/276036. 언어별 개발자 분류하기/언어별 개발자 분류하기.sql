-- GRADE별 개발자의 정보를 조회
-- A : Front End 스킬과 Python 스킬을 함께 가지고 있는 개발자
-- B : C# 스킬을 가진 개발자
-- C : 그 외의 Front End 개발자
-- GRADE가 존재하는 개발자의 GRADE, ID, EMAIL을 조회하는 SQL 문을 작성
WITH TOTAL AS(
    SELECT *
    FROM DEVELOPERS D
    JOIN SKILLCODES S
    ON ((D.SKILL_CODE & S.CODE)>0)
    ORDER BY D.ID
)
, R AS(SELECT ID,EMAIL,
CASE
    WHEN (ID,'PYTHON') IN(
        SELECT ID,NAME FROM TOTAL
    ) AND (ID,'FRONT END') IN(
        SELECT ID,CATEGORY FROM TOTAL
    )
    THEN 'A'
    WHEN (ID,'C#') IN(
        SELECT ID,NAME FROM TOTAL
    )
    THEN 'B'
    WHEN (ID,'FRONT END') IN(
        SELECT ID,CATEGORY FROM TOTAL
    )
    THEN 'C'
    END AS GRADE
FROM DEVELOPERS D
)

SELECT GRADE,ID,EMAIL
FROM R
WHERE GRADE IS NOT NULL
ORDER BY GRADE,ID