#include "Menu.hpp"
#include "DxLib.h"

#include "Keyboard.hpp"


Menu::Menu(ISceneChanger * changer)
	: BaseScene(changer)
{
}


Menu::~Menu() // �I������
{
}


void Menu::Update() //�v�Z����
{
	if (Keyboard_Get(KEY_INPUT_Z) == 1) mSceneChanger->ChangeScene(eScene_Game); //Gamesin�ɂ����܂�

}


void Menu::Draw() //��ʂɉf����
{
	DrawFormatString(0, 20, GetColor(0, 255, 0), "MENU_SCENE_NOW");
}

//EOF