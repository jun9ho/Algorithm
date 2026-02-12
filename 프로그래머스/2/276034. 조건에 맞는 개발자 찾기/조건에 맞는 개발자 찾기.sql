-- 코드를 작성해주세요
-- D165	Jerami	Edwards	jerami_edwards@grepp.co	400
-- D161	Carsen	Garza	carsen_garza@grepp.co	2048
-- D164	Kelly	Grant	kelly_grant@grepp.co	1024
-- D163	Luka	Cory	luka_cory@grepp.co	16384
-- D162	Cade	Cunningham	cade_cunningham@grepp.co	8452

-- python이나 C# 스킬

-- NAME	CATEGORY	CODE
-- C++	Back End	4
--  JavaScript	Front End	16
-- Java	Back End	128
-- Python	Back End	256
-- C#	Back End	1024
-- React	Front End	2048
-- Vue	Front End	8192
-- Node.js	Back End	16384

SELECT DISTINCT D.ID,D.EMAIL,D.FIRST_NAME,D.LAST_NAME
FROM SKILLCODES S
LEFT JOIN DEVELOPERS D
ON (S.CODE & D.SKILL_CODE) > 0
WHERE S.NAME = 'C#' OR S.NAME = 'PYTHON'
ORDER BY D.ID ASC;