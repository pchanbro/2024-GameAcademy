#include "pch.h"
#include "UI.h"

void UI::Init()
{

}
void UI::Render(HDC hdc)
{
	if (_isShow == false) return;
}
void UI::Update()
{

}
void UI::Release()
{

}
void UI::Show()
{
	_isShow = true;
}
void UI::Hide()
{
	_isShow = false;
}
void UI::SetRect(CenterRect rect)
{
	_pos.x = rect.pos.x;
	_pos.y = rect.pos.y;
	_size.x = static_cast<int>(rect.width);
	_size.y = static_cast<int>(rect.height);
}
CenterRect UI::GetRect()
{
	CenterRect rect;
	rect.pos.x = _pos.x;
	rect.pos.y = _pos.y;
	//rect.pos = _pos;
	rect.width = static_cast<float>(_size.x);
	rect.height = static_cast<float>(_size.y);

	return rect;
}
bool UI::IsInMouse()
{
	return Collision::PtInRect(Input->GetMousePos(), this->GetRect().ToRect());
}