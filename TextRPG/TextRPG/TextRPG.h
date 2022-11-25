#pragma once

// 반드시 클래스 상속 구조, 가상함수, 다향성(업캐스팅, 다운캐스팅) 사용할것
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