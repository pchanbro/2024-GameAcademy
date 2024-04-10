#include "pch.h"
#include "Collider.h"

void Collider::Init()
{
	Super::Init();
}
void Collider::Render(HDC hdc)
{
	Super::Render(hdc);

}
void Collider::Update()
{
	Super::Update();

}
void Collider::Release()
{
	Super::Release();

}
bool Collider::CheckCollision(Collider* other)
{
	return false;
}
