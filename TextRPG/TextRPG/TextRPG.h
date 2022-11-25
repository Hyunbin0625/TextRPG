#pragma once

// �ݵ�� Ŭ���� ��� ����, �����Լ�, ���⼺(��ĳ����, �ٿ�ĳ����) ����Ұ�
class TextRPG
{
public:
	TextRPG();
	~TextRPG();

public:
	void Play(Player* player);
	void PlayerInfo(Player* player);
	void SkillInfo(Player* player);
	void Save(Player* player);
	void PlayerSavedRetrieve(PlayerDesc* desc);

private:
	Player* player = nullptr;
	Dungeon* dungeon = nullptr;
	Forge* forge = nullptr;
	Store* store = nullptr;
	Motel* motel = nullptr;
};

enum class Act
{
	Dungeon = 1,
	Forge,
	Store,
	Motel,
	CharInfo,
	SkillInfo,
	Save,
	End
};