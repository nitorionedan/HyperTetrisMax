#include "tetrimino.hpp"
#include "Dxlib.h"


Tetrimino::Tetrimino() //ロードしたらdelete
{
	for (int i = 0; i < sizeof(gh_mino) / sizeof(gh_mino[0]); i++)
	{
		gh_mino[i] = 0;
	}

	gh_mino[0] = LoadGraph("mino.png");
	//gh_mino[1]
	//gh_mino[2]
	//   ・
	//   ・
	//   ・
}


Tetrimino::~Tetrimino()
{
	for (int i = 0; i < sizeof(gh_mino) / sizeof(gh_mino[0]); i++)
	{
		if (gh_mino[i] != 0 && gh_mino[i] != -1)
			DeleteGraph(gh_mino[i]);
	}
}


void Tetrimino::Update()
{
}


void Tetrimino::Draw()
{
	DrawGraph(300, 300, gh_mino[0], TRUE);
}