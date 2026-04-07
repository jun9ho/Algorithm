--  '통풍시트', '열선시트', '가죽시트' 중 하나 이상의 옵션이 포함된 자동차가 자동차 종류 별로 몇 대인지 출력하는 SQL문을 작성
SELECT CAR_TYPE,COUNT(*) AS 'CARS'
FROM CAR_RENTAL_COMPANY_CAR 
WHERE INSTR(OPTIONS,'통풍시트') OR  INSTR(OPTIONS,'열선시트') OR  INSTR(OPTIONS,'가죽시트')
GROUP BY CAR_TYPE
ORDER BY CAR_TYPE