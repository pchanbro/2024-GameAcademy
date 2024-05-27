#include "pch.h"

void Comment1()
{
	// 1. Collider Layer -> Example 실습
	// 2. 타일맵 // File Read, Write (Save, Load)

	// - 타일맵은 기본적으로 2D Game에 쓰이는 방식
	// - 소켓서버기반 위치연동
	// - Windows API 포트폴리오 이번에 만들 타일맵게임(틀만 일단 짜줌)
	// - Game Engine (Unity, Unreal) Windows API에서 만든거랑 똑같이 해서 Mobile로 만들면 취업커트라인은 충분히 넘긴다.
	// - 근데 이거 만들려면 게임엔진 하루에 10시간은 공부해야할거다
}

void Comment2()
{
	// 타일맵
	
	// 대표적으로는 포켓몬스터

	// 타일맵을 안쓰는 다른개념
	//  - 통 맵 ( ex. 메이플스토리)

	// - Background를 조각으로 잘라서 하나하나 붙일수 있는가? (타일맵) - 포트폴리오에선 이게 유리함
	// - 그냥 디자이너가 한 통으로 다 그려주는 형식인가? (통맵) - 이걸 구할 수 있으면 편하긴 함

	// 타일맵 구현

	// TileMap
	//  - vector<TIle>
	//  - CellSize
	//  - MapSize

	// Tile
	//  - Position(Vector2Int)
	//  - Value
}

void Comment3()
{
	// DECLARE_CHILD 만들어서 사용하기 시작했다고 해서
	// 그 전에 안썼던 파일들에도 DECLARE_CHILD를 전부 적용해줄 필요는 없다.
	// 웬만해서 하지 마라
	
	// 새로운 룰을 적용하는건
	// "지금 코드부터" 하면된다.
	
	// 운영중인 코드
	// 라이브서비스중인 코드
	
	// 새로운 코드가 추가되면
	// 기존코드를 모두 지워야하는가?
	
	// -> 기존 코드를 놔둬야함
	//  --> 모든 변경사항을 체크할 여력이 없음.
	
	// -> 사이드이펙트 (이 코드를 변경시킴으로써, 생길수 있는 버그)
	//  -> 측정할 수 없을 정도로 생길 수 있다(너무 광범위함)
	
	// '지금 코드부터'의 새로운 룰을 적용하는 범위는
	//  -> 새로운 클래스 만들때 (당연하다)
	//  -> 옛날코드에서는 절대로 변경하면 안되나?
	//   -> 옛날코드에서 버그가 발견되면, 수정을 해야한다.
	//   -> 그 때 같이 수정하면 된다.
}

void Comment4()
{
	// 타일맵정보는 어딘가에 저장해둔다.
	// 그렇기 때문에 리소스.
	
	// 어떤형태로 어떻게 저장할것이냐??
	// 음악파일, 이미지파일
	// + 텍스트파일

	// 텍스트파일 종류(프로그래머는 반드시 알아야 한다) 중요도 순위
	//  - .txt
	//		- 굳이 설명 안해줌
	
	//  - .ini
	//		- 장점 : 사용편함, 읽기편함, 옛날에는 많이쓰는 데이터파일, 요즘메타엔 잘 안쓰임
	//		- 단점 : 데이터 포맷이 한정되어있음
	//  [소분류]
	//    Variable = 값
	// 
	//  [General]
	//	live_link_linkHQInterval = 4000
	//	live_link_linkDegradedResolution = 1024
	//	live_link_linkHQTreshold = 2048
	//	live_link_linkQuickInterval = 300
	//	live_link_initDelayOnProjectCreation = 5000
	//  이런식으로 써있음
	
	//  - .csv (엑셀을 셀마다 쉼표(,)로 분리된 형태)
	//		- 장점 : 엑셀이라는 점(기획자가 엑셀을 많이 씀), 엑셀인데 용량이 작음
	//		- 단점 : (엑셀에서 쉼표(,)를 쓰면 의도치 않게 열이 분리된것처럼 보인다.)	
	//				(혹은, 불러오기가 힘든형태가 된다.)
	//		- Comment : 요즘은 csv를 읽기보단 그냥 xlsx파일을 읽음.
	//			(혹은 엑셀을 변형한 내부 커스텀데이터파일)
	
	//  - .xml
	//<?xml version="1.0"?>
	//<CAT>
	//  <NAME>Izzy</NAME>
	//  <BREED>Siamese</BREED>
	//  <AGE>6</AGE>
	//  <ALTERED>yes</ALTERED>
	//  <DECLAWED>no</DECLAWED>
	//  <LICENSE>Izz138bod</LICENSE>
	//  <OWNER>Colin Wilcox</OWNER>
	//</CAT>
	// 
	// 장점 : 트리형태를 가지고있다. 여러가지 데이터 포맷을 포함할수있다.
	//			(Class를 다 Data로 저장시킬 수 있는 데이터포맷)
	// 단점 : 기획자가 쓰기 어려워함
	//		  쓸데없이 문법이 까다로움
	//		  데이터에 비해 용량이 조금 큼. (그래도 작은편)
	
	// - ★★★★★.json ★★★★★
	// - 이건 모르면 안된다. (모르면 폐급취급 받는다)
		// - 
	//{
	//	"menu": {
	//		"id": "file",
	//		"value" : "File",
	//		"popup" : {
	//			"menuitem": [
	//				{"value": "New", "onclick" : "CreateNewDoc()"},
	//				{ "value": "Open", "onclick" : "OpenDoc()" },
	//				{ "value": "Close", "onclick" : "CloseDoc()" }
	//			]
	//		}
	//	}
	//}

	//<Menu>
	//	<Id>file</Id>
	//	<Value>File</Value>
	//	<Popup>
	//		<MenuItem>
	//			<Value>New</Value>
	//			<onclick>CreateNewDoc()</onclick>
	//		</MenuItem>
	//		<MenuItem>
	//			<Value>Open</Value>
	//			<onclick>OpenDoc()</onclick>
	//		</MenuItem>
	//		<MenuItem>
	//			<Value>Close</Value>
	//			<onclick>CloseDoc()</onclick>
	//		</MenuItem>
	//	</Popup>
	//</Menu>
	
	// 딱보면, menu라는 객체안에 
	// id라는 변수는 file 이라는 값이고
	// value는 File이라는 값
	// 장점 : 모든 클래스데이터를 다 포함시킬수 있다. XML보다 용량도 훨씬작다.
	// 단점 : 주석을 못쓴다.

	

	// txt 파일 Read Write
	// 파일입출력의 기본
	
	
	//  - 당장은 여기까지 더 있긴함

}

void Comment5()
{
	// 리소스 부족으로 오늘 진도 진행 불가
	// 다음 진도가 
	// TileMap 생성해서 보여주는건데
	// 이미지 파일을 지금 못구한 상태
}

void Comment6()
{
	// json 입출력
	// wifstream
	// wofstream
	// 사용

	// 다른사람이 잘 만들어둔걸 사용한다.
	// Library를 사용

	// 엔진, 프레임워크, 라이브러리 차이
	// 엔진, 프레임워크 : 무언가를 만들기위해 만들어진 툴(코드뭉치)
	//		- 내 코드를 여기에 맞춰야한다.
	// 
	// 라이브러리 : 무언가를 다루기위해 만들어진 코드뭉치
	//		- 내 코드에서 라이브러리를 가져다 쓰는 형태다.

	// json에서 유명한 library가 있다.

	// Tencent - 가장 큰 게임회사
	//    클래시오브클랜, 롤, 기타등등
	// 에서 만든
	// rapid json

	// 앞으로 라이브러리를 많이 사용할건데 
	// 라이브러리 쓰는방법에 대해 알아보자

	// github에서 라이브러리를 확인해서
	// 일단 기존에 파일에 적용하기 전에 무조건 새 프로젝트를 만들어서 사용해보자
	// [소개]를 한 번 읽어보고 괜찮은지 파악해라
	// 그리고 별이 10000개 이상인걸 사용해라
	// 영어로 돼있으면 한글로 번역시키고 [설치]라고 적힌 부분을 이용하자
	// 그럼 이제 라이브러리를 다운 받아서 [설치]칸에 적혀있는 방법으로 이용해보자
}