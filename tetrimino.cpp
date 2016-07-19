#include "tetrimino.hpp"
#include "Field.hpp"
#include "Dxlib.h"


Tetrimino::Tetrimino() //ロードしたらdelete
{
	for (int i = 0; i < sizeof(gh_mino) / sizeof(gh_mino[0]); i++)
	{
		gh_mino[i] = 0;
		gh_mino_piece[i] = 0;
	}

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
}
	

Tetrimino::~Tetrimino()
{
	for (int i = 0; i < sizeof(gh_mino) / sizeof(gh_mino[0]); i++)
	{
		if (gh_mino[i] != 0 && gh_mino[i] != -1)
			DeleteGraph(gh_mino[i]);

		if (gh_mino_piece[i] != 0 && gh_mino_piece[1] != -1)
			DeleteGraph(gh_mino_piece[i]);
	}
}


void Tetrimino::Update()
{
}

void Tetrimino::Draw()
{
	DrawGraph(300, 300, gh_mino[0], TRUE);
}

void Tetrimino::Mino_teigi() //テトリミノ用の4×4の配列を作る
{
	for (int x = 0; x >piece_height; x++)
		for (int y = 0; y > piece_width; y++)
		{
			mino[x][y] = 0; //4×4の空白の配列を作る
			mino_color[x][y] = 0; //色を決める
		}
}

void Tetrimino::Mino1() //I型テトリミノ
{
	mino[1][0] = 1; //所定の欄の判定を有効に
	mino[1][1] = 1;
	mino[1][2] = 1;
	mino[1][3] = 1;

	mino_color[1][0] = 1; //色を定義
	mino_color[1][1] = 1;
	mino_color[1][2] = 1;
	mino_color[1][3] = 1;
}

void Tetrimino::Mino2() //□型テトリミノ
{
	mino[1][1] = 1;
	mino[1][2] = 1;
	mino[2][1] = 1;
	mino[2][2] = 1;

	mino_color[1][1] = 2;
	mino_color[1][2] = 2;
	mino_color[2][1] = 2;
	mino_color[2][2] = 2;
}

void Tetrimino::Mino3() //Z型テトリミノ
{
	mino[1][1] = 1;
	mino[1][2] = 1;
	mino[2][2] = 1;
	mino[2][3] = 1;

	mino_color[1][1] = 3;
	mino_color[1][2] = 3;
	mino_color[2][2] = 3;
	mino_color[2][3] = 3;
}

void Tetrimino::Mino4() //Z反対型テトリミノ
{
	mino[2][1] = 1;
	mino[1][1] = 1;
	mino[1][2] = 1;
	mino[0][2] = 1;

	mino_color[2][1] = 4;
	mino_color[1][1] = 4;
	mino_color[1][2] = 4;
	mino_color[0][2] = 4;
}

void Tetrimino::Mino5() //L型テトリミノ
{
	mino[1][1] = 1;
	mino[2][1] = 1;
	mino[2][2] = 1;
	mino[2][3] = 1;

	mino_color[1][1] = 5;
	mino_color[2][1] = 5;
	mino_color[2][2] = 5;
	mino_color[2][3] = 5;
}

void Tetrimino::Mino6() //L2型テトリミノ
{
	mino[2][1] = 1;
	mino[1][1] = 1;
	mino[1][2] = 1;
	mino[1][3] = 1;

	mino_color[2][1] = 6;
	mino_color[1][1] = 6;
	mino_color[1][2] = 6;
	mino_color[1][3] = 6;
}

void Tetrimino::Mino7() //T型テトリミノ
{
	mino[2][1] = 1;
	mino[1][2] = 1;
	mino[2][2] = 1;
	mino[3][2] = 1;

	mino_color[2][1] = 7;
	mino_color[1][2] = 7;
	mino_color[2][2] = 7;
	mino_color[3][2] = 7;
}

Tetrimino& Tetrimino::Create_Mino() //実際のテトリミノを作成する
{
	int Random = rand() % 7 + 1;
	Tetrimino::Mino_teigi();
	
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
//		Tetrimino::Mino2();

	case 3:
//		Tetrimino::Mino3();

	case 4:
//		Tetrimino::Mino4();

	case 5:
//		Tetrimino::Mino5();

	case 6:
//		Tetrimino::Mino6();

	case 7:
//		Tetrimino::Mino7();

	default:	printfDx("そんなものはない\n");	break;
	}
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

void Tetrimino::Search_Piece_Boundary() //フィールドに配置されたピースの判定を検出
{
	piece_right = 0;
	piece_left = piece_width;
	piece_up = piece_height;
	piece_bottom = 0;

	for (int y = 0; y < piece_height; y++)
	{
		for (int x = 0; x < piece_width; x++)
		{
			if(mino[x][y]==1)
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
			KeepMino[x][y] = mino[x][y]; //現在移動中のテトリミノを一旦格納
			mino[x][y] = HoldMino1[x][y]; //ホールドしていたテトリミノを現在移動中のテトリミノへ
			HoldMino1[x][y] = KeepMino[x][y]; //一旦格納していたテトリミノを第1ホールドへ

			KeepColor[x][y] = mino_color[x][y]; //テトリミノの色をホールド
			mino_color[x][y] = HoldMino1_Color[x][y]; //上のやつとやってることは同じ
			HoldMino1_Color[x][y] = KeepColor[x][y];
		}
	}

	//第2ホールド
	for (int y = 0; y < piece_height; y++) //4×4のブロックを1つずづ格納していく
	{
		for (int x = 0; x < piece_width; x++)
		{
			KeepMino[x][y] = mino[x][y];
			mino[x][y] = HoldMino2[x][y];
			HoldMino2[x][y] = KeepMino[x][y];

			KeepColor[x][y] = mino_color[x][y];
			mino_color[x][y] = HoldMino2_Color[x][y];
			HoldMino2_Color[x][y] = KeepColor[x][y];
		}
	}

}

void Tetrimino::Next() //ネクストテトリミノを配置する
{
	
}

