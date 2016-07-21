#include "Field.hpp"
#include "tetrimino.hpp"
#include "DxLib.h"

int Field::FieldMino[FieldWidth][FieldHeight]; //テトリスフィールドのマス
int Field::FieldColor[FieldWidth][FieldHeight];

Field::Field()
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
}

Field::~Field()
{
	for (int i = 0; i < sizeof(gh_mino) / sizeof(gh_mino[0]); i++)
	{
		if (gh_mino[i] != 0 && gh_mino[i] != -1)
			DeleteGraph(gh_mino[i]);

		if (gh_mino_piece[i] != 0 && gh_mino_piece[i] != -1)
			DeleteGraph(gh_mino_piece[i]);
	}
}

void Field::Update(Tetrimino* mino)
{
	DeleteLine(mino);
	//MinoShift();
	MakeMainField(mino);
}

void Field::Draw()
{
	DrawMainField();
	DrawFieldMino();
	DrawSubField();
}

int Field::DeleteLine(Tetrimino* mino) //埋まった行を消す
{
	int DeleteCount = 0;
	
	for (int y = FieldHeight - 1; y > 0; y--)
	{
		int xNumPerLine = 0;
		for (int x = 0; x < FieldWidth; x++)
		{
			if (FieldMino[x][y])
			{
				xNumPerLine++;
			}
		}
		if (xNumPerLine != FieldWidth)
		{
			continue;
		}
		DeleteCount++;
		for (int x = 0; x < FieldWidth; x++)
		{
			FieldMino[x][y] = 0;
		}
	}
  //AllDeletePoint = AllDeletePoint + DeleteCount; //消す行分全消しポイントを貯めていく
	return DeleteCount;
}

void Field::MinoShift(int DeleteCount) //判定を下へずらす
{
	for (int y = FieldHeight - 1; y >= 0 && DeleteCount > 0;) //Field::DeleteLineで返された行分繰り返す
	{
		int xNumPerLine = 0;
		for (int x = 0; x < FieldWidth; x++)
		{
			if (FieldMino[x][y])
			{
				xNumPerLine++;
			}
		}
		if (xNumPerLine != 0) //1行すべて消されていなければ1行上を確認する(countinue文でループを抜ける)
		{
			y--;
			continue;
		}
		DeleteCount--; //1行すべて判定が無ければ
		for (int ty = y; ty >= 0; ty--) //ここからすべてのFieldMino配列を1行ずつ下げていく
		{
			for (int tx = 0; tx < FieldWidth; tx++)
			{
				if (ty - 1 > -0)
				{
					FieldMino[tx][ty] = FieldMino[tx][ty - 1];
					FieldColor[tx][ty] = FieldColor[tx][ty - 1];
				}
				else //19行目から上の判定は無しに設定
				{
					FieldMino[tx][0] = 0;
					FieldColor[tx][0] = 0;
				}
			}
		}

	}
}

void Field::MakeMainField(Tetrimino* mino) //テトリスフィールドを作成
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			FieldMino[x][y] = 0;
			FieldColor[x][y] = 0;
		}
	}

}

void Field::DrawMainField() //テトリスフィールドに30×30の枠線をつけ分かりやすくする
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			int Field_Cell_x = 220 + (x + 1)*Tetrimino::Piece_Cell_Width;
			int Field_Cell_y = -5 + (y + 1)*Tetrimino::Piece_Cell_Height;

			DrawBox(Field_Cell_x, Field_Cell_y, Field_Cell_x + Tetrimino::Piece_Cell_Width, Field_Cell_y + Tetrimino::Piece_Cell_Height, GetColor(255, 255, 255), false);
		}
	}
	DrawBox(250, 25, 550, 625, GetColor(255, 255, 255), false); //メインフィールドの描画
}

void Field::DrawFieldMino() //テトリスフィールドに配置されたテトリミノに画像を付ける
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			int Field_Cell_x = (x + 1)*Tetrimino::Piece_Cell_Width;
			int Field_Cell_y = (y + 1)*Tetrimino::Piece_Cell_Height;

			if (FieldMino != 0)
			{
				switch (Field::FieldColor[x][y]) //mino_color変数ごとに画像を配置(Tetrimino::Minoを参照)　　　　画像は追加予定
				{
				case 1:
					
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[1], true); //gh_mino_piece=テトリミノのピース画像
					break;
				case 2:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[2], true);
					break;
				case 3:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[3], true);
					break;
				case 4:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[4], true);
					break;
				case 5:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[5], true);
					break;
				case 6:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[6], true);
					break;
				case 7:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[7], true);
					break;

				}
			}
		}
	}
}

void Field::DrawSubField()
{
	DrawBox(25, 35, 225, 235, GetColor(255, 255, 255), false); //第1ホールド
	DrawBox(25, 255, 225, 455, GetColor(255, 255, 255), false); //第2ホールド
	DrawBox(575, 35, 775, 235, GetColor(255, 255, 255), false); // ネクスト
	DrawBox(600, 250, 750, 400, GetColor(255, 255, 255), false); //ネクネク
	DrawBox(600, 415, 750, 565, GetColor(255, 255, 255), false); //ネクスト3
	DrawBox(590, 600, 820, 630, GetColor(255, 255, 255), false); //全消しゲージ
}