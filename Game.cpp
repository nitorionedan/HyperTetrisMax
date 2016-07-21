#include "DxLib.h"

#include "Game.hpp"
#include "Keyboard.hpp"


Game::Game(ISceneChanger * changer)
	: BaseScene(changer)
	//, mino(new Tetrimino) // mino = new Tetorimino;
{
	tetrimino = new Tetrimino;
	field = new Field;
}


Game::~Game()
{
	//delete mino;
	delete field;
	delete tetrimino;
}


void Game::Update()
{
	//mino->Update();

	field->Update(tetrimino);

	if (Keyboard_Get(KEY_INPUT_Z) == 1) mSceneChanger->ChangeScene(eScene_Menu);
}


void Game::Draw()
{
	//mino->Draw();
	field->Draw();

	// TEST
	DrawFormatString(0, 20, GetColor(0, 255, 0), "GAME_SCENE_NOW");

}
