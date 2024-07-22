USE SBS_Study_20240701;

-- TABLE 생성 명령어
DROP TABLE IF EXISTS BSY_TblChampion;
CREATE TABLE BSY_TblChampion
(
	_key		INT				PRIMARY KEY		AUTO_INCREMENT
	,_name		VARCHAR(30)
);

INSERT INTO BSY_TblChampion (_name)
	VALUES	('가렌'),
		  	('티모');

DROP TABLE IF EXISTS BSY_TblItem;
CREATE TABLE BSY_TblItem
(
	_key		INT				PRIMARY KEY		AUTO_INCREMENT
	,_name		VARCHAR(30)
);

INSERT INTO BSY_TblItem (_name)
	VALUES	('신발'),
		  	('단검'),
		  	('롱소드');

DROP TABLE IF EXISTS BSY_TblSkill;
CREATE TABLE BSY_TblSkill
(
	_key		INT				PRIMARY KEY		AUTO_INCREMENT
	,_name		VARCHAR(30)
);

INSERT INTO BSY_TblSkill (_name)
	VALUES	('실명'),
		  	('이속증가'),
		  	('침묵');

DROP TABLE IF EXISTS BSY_TblUser;
CREATE TABLE BSY_TblUser
(
	_key				INT		PRIMARY KEY		AUTO_INCREMENT
	,_championKey		INT
	,_level				INT
	,FOREIGN KEY  (_championKey) REFERENCES BSY_TblChampion(_key) 
		ON DELETE CASCADE
		ON UPDATE CASCADE
); 

INSERT INTO BSY_TblUser (_championKey, _level)
	VALUES	(1,2),
		  	(2,1);

DROP TABLE IF EXISTS BSY_TblUserItem;
CREATE TABLE BSY_TblUserItem
(
	_key				INT		PRIMARY KEY		AUTO_INCREMENT
	,_userKey			INT
	,_itemKey			INT
	,FOREIGN KEY  (_userKey) REFERENCES BSY_TblUser(_key)
		ON DELETE CASCADE 
		ON UPDATE CASCADE
	,FOREIGN KEY  (_itemKey) REFERENCES BSY_TblItem(_key)
		ON DELETE CASCADE 
		ON UPDATE CASCADE
);

INSERT INTO BSY_TblUserItem (_userKey, _itemKey)
	VALUES	(1,1),
		  	(1,2),
		  	(2,2),
		  	(2,3);

DROP TABLE IF EXISTS BSY_TblUserSkill;
CREATE TABLE BSY_TblUserSkill
(
	_key				INT		PRIMARY KEY		AUTO_INCREMENT
	,_userKey			INT
	,_skillKey			INT
	,FOREIGN KEY  (_userKey) REFERENCES BSY_TblUser(_key)
		ON DELETE CASCADE 
		ON UPDATE CASCADE
	,FOREIGN KEY  (_skillKey) REFERENCES BSY_TblSkill(_key)
		ON DELETE CASCADE 
		ON UPDATE CASCADE
);

INSERT INTO BSY_TblUserSkill (_userKey, _skillKey)
	VALUES	(1,1),
		  	(1,2),
		  	(2,3);