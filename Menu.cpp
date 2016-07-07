#include "Menu.hpp"
#include "DxLib.h"

#include "Keyboard.hpp"


Menu::Menu(ISceneChanger * changer)
	: BaseScene(changer)
{
}


Menu::~Menu() // I—¹ˆ—
{
}


void Menu::Update() //ŒvŽZˆ—
{
	if (Keyboard_Get(KEY_INPUT_Z) == 1) mSceneChanger->ChangeScene(eScene_Game); //Gamesin‚É‚¢‚«‚Ü‚·

}


void Menu::Draw() //‰æ–Ê‚É‰f‚é‚â‚Â
{
	DrawFormatString(0, 20, GetColor(0, 255, 0), "MENU_SCENE_NOW");
}

//EOF