#include "Menu.hpp"
#include "DxLib.h"

#include "Keyboard.hpp"


Menu::Menu(ISceneChanger * changer)
	: BaseScene(changer)
{
}


Menu::~Menu() // 終了処理
{
}


void Menu::Update() //計算処理
{
	if (Keyboard_Get(KEY_INPUT_Z) == 1) mSceneChanger->ChangeScene(eScene_Game); //Gamesinにいきます

}


void Menu::Draw() //画面に映るやつ
{
	DrawFormatString(0, 20, GetColor(0, 255, 0), "MENU_SCENE_NOW");
}

//EOF