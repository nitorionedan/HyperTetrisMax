#include "tetrimino.hpp"
#include "Field.hpp"
#include "Dxlib.h"
#include <algorithm>


int Tetrimino::mino_color[4][4];//現在移動中のブロックの色


Tetrimino::Tetrimino() //ロードしたらdelete
{
	gh_mino[0] = LoadGraph("mino0.png"); //テトリミノの画像
	gh_mino[1] = LoadGraph("mino1.png");
	gh_mino[2] = LoadGraph("mino2.png");
	gh_mino[3] = LoadGraph("mino3.png");
	gh_mino[4] = LoadGraph("mino4.png");
	gh_mino[5] = LoadGraph("mino5.png");
	gh_mino[6] = LoadGraph("mino6.png");

	gh_mino_piece[0] = LoadGraph("mino_piece0.png"); //テトリミノのピースの画像
	gh_mino_piece[1] = LoadGraph("mino_piece1.png");
	gh_mino_piece[2] = LoadGraph("mino_piece2.png");
	gh_mino_piece[3] = LoadGraph("mino_piece3.png");
	gh_mino_piece[4] = LoadGraph("mino_piece4.png");
	gh_mino_piece[5] = LoadGraph("mino_piece5.png");
	gh_mino_piece[6] = LoadGraph("mino_piece6.png");

	state = eTetrimino_None;


}
	

Tetrimino::~Tetrimino()
{
	for (int i = 0; i < sizeof(gh_mino) / sizeof(gh_mino[0]); i++)
	{
		if (gh_mino[i] != 0 && gh_mino[i] != -1)
			DeleteGraph(gh_mino[i]);

		if (gh_mino_piece[i] != 0 && gh_mino_piece[i] != -1)
			DeleteGraph(gh_mino_piece[i]);
	}
}


void Tetrimino::Update() //処理を書く
{
	switch (state)
	{
	case eTetrimino_Falling:
		Turn_right();
		Turn_left();
		//落下
		break;
	case eTetrimino_Next1:
		//ネクスト
	}

	Mino_Teigi();
	Create_Mino();
	Hold();
}

void Tetrimino::Draw() //描画を書く
{

}

void Tetrimino::Mino_Teigi() //テトリミノ用の4×4の配列を作る
{
	for (int x = 0; x >piece_height; x++)
		for (int y = 0; y > piece_width; y++)
		{
			mino[x][y] = 0; //4×4の空白の配列を作る
			mino_color[x][y] = 0; //色を決める
		}
}

Tetrimino& Tetrimino::Create_Mino() //実際のテトリミノを作成する
{
	int Random = rand() % 7 + 1;
	Tetrimino::Mino_Teigi();
	
	// 一時的なテトリミノ
	Tetrimino mino;

	switch (Random) {
	case 1:
		mino.mino[1][0] = 1;
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[1][3] = 1;

		mino.mino_color[1][0] = 1; //色を定義
		mino.mino_color[1][1] = 1;
		mino.mino_color[1][2] = 1;
		mino.mino_color[1][3] = 1;
		
		return	mino;	// 情報を設定したミノを返す

	case 2:
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[2][1] = 1;
		mino.mino[2][2] = 1;

		mino.mino_color[1][1] = 2;
		mino.mino_color[1][2] = 2;
		mino.mino_color[2][1] = 2;
		mino.mino_color[2][2] = 2;

		return mino;

	case 3:
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[2][2] = 1;
		mino.mino[2][3] = 1;

		mino.mino_color[1][1] = 3;
		mino.mino_color[1][2] = 3;
		mino.mino_color[2][2] = 3;
		mino.mino_color[2][3] = 3;

		return mino;

	case 4:
		mino.mino[2][1] = 1;
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[0][2] = 1;

		mino.mino_color[2][1] = 4;
		mino.mino_color[1][1] = 4;
		mino.mino_color[1][2] = 4;
		mino.mino_color[0][2] = 4;

		return mino;

	case 5:
		mino.mino[1][1] = 1;
		mino.mino[2][1] = 1;
		mino.mino[2][2] = 1;
		mino.mino[2][3] = 1;

		mino.mino_color[1][1] = 5;
		mino.mino_color[2][1] = 5;
		mino.mino_color[2][2] = 5;
		mino.mino_color[2][3] = 5;

		return mino;

	case 6:
		mino.mino[2][1] = 1;
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[1][3] = 1;

		mino.mino_color[2][1] = 6;
		mino.mino_color[1][1] = 6;
		mino.mino_color[1][2] = 6;
		mino.mino_color[1][3] = 6;

		return mino;

	case 7:
		mino.mino[2][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[2][2] = 1;
		mino.mino[3][2] = 1;

		mino.mino_color[2][1] = 7;
		mino.mino_color[1][2] = 7;
		mino.mino_color[2][2] = 7;
		mino.mino_color[3][2] = 7;

		return mino;

	default:	printfDx("そんなものはない\n");	break;
	}

	return mino;
}

void Tetrimino::Copy_Mino() //作ったテトリミノをコピーし落下用のテトリミノを作成
{
	Tetrimino mino;

	for (int x = 0; x < piece_width; x++)
	{
		for (int y = 0; y < piece_height; y++)
		{
			this->mino[x][y] = mino.mino[x][y]; //生成したテトリミノをコピー
			this->mino_color[x][y] = mino.mino_color[x][y];
		}
	}
	
}

void Tetrimino::Move_Mino_Down() //落下するテトリミノ
{

}

void Tetrimino::Draw_Falling_Mino() //落下していくテトリミノを描画
{
	Tetrimino::Copy_Mino();

	for (int y = 0; y < Field::FieldHeight; y++)
	{
		for (int x = 0; x < Field::FieldWidth; x++)
		{
			int ptx = (mino_position_x);
		}
	}

}


void Tetrimino::Turn_right() //テトリミノ右回転
{
	int KeepMino[4][4]; //一旦保留するための配列を用意
	int KeepColor[4][4]; //一旦保留するための配列を用意

	for (int x = piece_width - 1; x >= 0; x--)
	{
		for (int y = 0; y < piece_height; y++)
		{
			KeepMino[x][y] = mino[y][abs(x-3)]; //一回保留し
			mino[y][abs(x - 3)] = KeepMino[y][abs(x - 3)]; //上書きする

			KeepColor[x][y] = mino_color[y][abs(x - 3)];
			mino_color[y][abs(x - 3)] = KeepColor[y][abs(x - 3)];
		}
	}
}

void Tetrimino::Turn_left() //テトリミノ左回転
{
	int KeepMino[4][4]; //一旦判定を保留するための配列を用意
	int KeepColor[4][4]; //一旦色を保留するための配列を用意

	for (int x = 0; x < piece_width; x++)
	{
		for (int y = piece_height - 1; y >= 0; y--)
		{
			KeepMino[x][y] = mino[x][abs(y - 3)]; //一回保留し
			mino[x][abs(y - 3)] = KeepMino[x][abs(y - 3)]; //上書きする

			KeepColor[x][y] = mino_color[x][abs(y - 3)];
			mino_color[x][abs(y - 3)] = KeepColor[x][abs(y - 3)];
		}
	}
}

void Tetrimino::Hold() //テトリミノをホールドする
{
	int KeepMino[4][4];
	int KeepColor[4][4];
	//第1ホールド
	for (int y = 0; y < piece_height; y++) //4×4のブロックを1つずづ格納していく
	{
		for (int x = 0; x < piece_width; x++)
		{
			std::swap(mino[x][y], HoldMino1[x][y]);

//			KeepMino[x][y] = mino[x][y]; //現在移動中のテトリミノを一旦格納
//			mino[x][y] = HoldMino1[x][y]; //ホールドしていたテトリミノを現在移動中のテトリミノへ
//			HoldMino1[x][y] = KeepMino[x][y]; //一旦格納していたテトリミノを第1ホールドへ

			std::swap(mino_color[x][y], HoldMino1_Color[x][y]);

//			KeepColor[x][y] = mino_color[x][y]; //テトリミノの色をホールド
//			mino_color[x][y] = HoldMino1_Color[x][y]; //上のやつとやってることは同じ
//			HoldMino1_Color[x][y] = KeepColor[x][y];
		}
	}

	//第2ホールド
	for (int y = 0; y < piece_height; y++) //4×4のブロックを1つずづ格納していく
	{
		for (int x = 0; x < piece_width; x++)
		{
			std::swap(mino[x][y], HoldMino2[x][y]);

//			KeepMino[x][y] = mino[x][y];
//			mino[x][y] = HoldMino2[x][y];
//			HoldMino2[x][y] = KeepMino[x][y];


			std::swap(mino_color[x][y], HoldMino2_Color[x][y]);

//			KeepColor[x][y] = mino_color[x][y];
//			mino_color[x][y] = HoldMino2_Color[x][y];
//			HoldMino2_Color[x][y] = KeepColor[x][y];
		}
	}

}

void Tetrimino::Next() //ネクストテトリミノを配置する
{
	
}

