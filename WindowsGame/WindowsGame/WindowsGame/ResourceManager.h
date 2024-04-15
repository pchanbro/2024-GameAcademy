#pragma once
class ResourceBase;
class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);

	// �� �Ŵ����� �⺻������ Init�� Release�� �־�� �Ѵ�.
public:
	void Init();
	void Release();

private:
	wstring _resourcePath;
	map<string, ResourceBase*> _resources;
};

//map��
// BinaryTree�� �����͸� key�� ���� �ϰ� (wstring)
// �� �ȿ� ���� ������(ResourceBase*) �� ���� �ִ�.

// map�� ���� : �˻��� ������.