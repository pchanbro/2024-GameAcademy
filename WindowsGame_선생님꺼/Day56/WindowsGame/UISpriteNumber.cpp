#include "pch.h"
#include "UISpriteNumber.h"
#include "Sprite.h"
void UISpriteNumber::SetNumber(int number)
{
	_number = number;
}
void UISpriteNumber::SetSprites(wstring resourceName)
{
	//resourceName : S_SpriteNumber
	//_sprites[0] : S_SpriteNumber_0
	//_sprites[1] : S_SpriteNumber_1

	for (int i = 0; i < 10; i++)
	{
		wchar_t spriteName[256];
		wsprintf(spriteName, L"%s_%d", resourceName.c_str(), i);

		_sprites[i] = GET_SINGLE(ResourceManager)->GetSprite(spriteName);

		//assert(_sprites[i] != nullptr);
		printf("Error: UISpriteNumber::SetSprites(wstring resourceName) Not Found Resource");
	}
}
void UISpriteNumber::SetSprite(Sprite* sprite, int number)
{
	assert(0 <= number && number <= 9);
	_sprites[number] = sprite;
}

void UISpriteNumber::Init()
{
	Super::Init();
}
void UISpriteNumber::Render(HDC hdc)
{
	if (_isShow == false) return;
	Super::Render(hdc);


	//TextOut 대신 TransparentBlt사용하여, Number를 출력
	//TextOut(hdc, this->_pos.x, this->_pos.y, L"숫자", 3);
	//::TransparentBlt
	// Sprite 한장씩 Render를 해줘야합니다.

	// 1. 자릿수가 얼마나되는지
	// 2. 그려야할 첫번째 좌표는 어디인지?

	// _pos.x , pos.y << 우리가 설정한 영역의 중심좌표
	// _pos.x - 이미지 가로길이 / 2 한 값으로 그리시작
	// _pos.x - 전체길이 / 2
	// _pos.x - (이미지한장사이즈 * 몇자리숫자) / 2

	// 중심좌표 기준으로 그리려면
	// 1. end Position을 먼저 구한다
	// 2. SpriteNumber의 길이만큼 빼면서 그 위치에서 그리기 시작한다.

	// 1. end Position을 먼저 구한다
	// (currentNumber => 한자릿수씩 체크하는 변수)
	//   - _sprites[currentNumber]->GetSize().x 를 모두 더하면 totalWidth가 나옴.
	//   - _pos.x + totalWidth / 2 값이 end Position

	int endPosition = 0;
	int totalWidth = 0;
	int temp = _number;
	do
	{
		int currentNumber = temp % 10;
		temp /= 10;

		totalWidth = _sprites[currentNumber]->GetSize().x;
	} while (temp > 0);
	endPosition = _pos.x + totalWidth / 2;

	// 2. SpriteNumber의 길이만큼 빼면서 그 위치에서 그리기 시작한다.
	//   - 일의 자리 위치는 : endPosition - sprites[일의자리]->GetSize().x
	//   - 십의 자리 위치는 : endPosition - sprites[일의자리]->GetSize().x - sprites[십의자리]->GetSize().x
	//   - ...

	temp = _number;
	int currentPosition = endPosition;
	do
	{
		int currentNumber = temp % 10;
		temp /= 10;
		currentPosition -= _sprites[currentNumber]->GetSize().x;

		::TransparentBlt(hdc,
			currentPosition,
			this->_pos.y - _sprites[currentNumber]->GetSize().y / 2,
			_sprites[currentNumber]->GetSize().x,
			_sprites[currentNumber]->GetSize().y,
			_sprites[currentNumber]->GetDC(),
			_sprites[currentNumber]->GetPos().x,
			_sprites[currentNumber]->GetPos().y,
			_sprites[currentNumber]->GetSize().x,
			_sprites[currentNumber]->GetSize().y,
			_sprites[currentNumber]->GetTransparent());

	} while (temp > 0);


}
void UISpriteNumber::Update()
{
	Super::Update();
}
void UISpriteNumber::Release()
{
	Super::Release();
}