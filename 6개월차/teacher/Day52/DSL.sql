SELECT * FROM BSY_TblChampion
SELECT * FROM BSY_TblItem 
SELECT * FROM BSY_TblSkill
SELECT * FROM BSY_TblUser
SELECT * FROM BSY_TblUserItem
SELECT * FROM BSY_TblUserSkill



SELECT *
	FROM BSY_TblUser
	-- WHERE `_level`  BETWEEN 0 AND 5
	WHERE _level IN (1, 2, 3)
	ORDER BY `_championKey`  DESC 
	
SELECT * FROM BSY_TblUser AS User
	LEFT OUTER JOIN BSY_TblChampion AS Champion
	ON User.`_championKey` = Champion._key



SELECT User.`_key`,  User.`_level` , Champion.`_name` 
	FROM BSY_TblUser AS User
	JOIN BSY_TblChampion AS Champion
	ON User.`_championKey`  = Champion.`_key` 
--	WHERE 
--	ORDER BY 
	
	
_championKey가 1인 데이터를 조회하는데

championName, UserLevel, UserSkillName

championName, UserLevel, UserItemName


SELECT Champion._name AS _championName , User._level AS _userLevel, Skill._name
	FROM BSY_TblUser AS User
	JOIN BSY_TblChampion AS Champion
	ON User._championKey = Champion._key
		JOIN BSY_TblUserSkill AS UserSkill
		ON UserSkill._userKey = User._key
			JOIN BSY_TblSkill AS Skill
			ON UserSkill._skillKey = Skill._key
	WHERE User._championKey = 1
	ORDER BY User._key
	
	

SELECT Champion._name AS _championName , User._level AS _userLevel, Item._name
	FROM BSY_TblUser AS User
	JOIN BSY_TblChampion AS Champion
	ON User._championKey = Champion._key
		JOIN BSY_TblUserItem AS UserItem
		ON UserItem._userKey = User._key
			JOIN BSY_TblItem AS Item
			ON UserItem._itemKey = Item._key
	WHERE User._championKey = 1


	
UPDATE BSY_TblItem
	SET _name = '마법의 장화'
	WHERE _key = 1
	

INSERT BSY_TblItem (_name)
	VALUES ('더미데이터')
	
	
DELETE FROM BSY_TblItem
	WHERE _key = 4
	
	