#include "Field.hpp"
#include "tetrimino.hpp"
#include "DxLib.h"

Field::Field()
{

}

Field::~Field()
{

}

int Field::DeleteLine() //埋まった行を消す
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
					mino_color[tx][ty] = mino_color[tx][ty - 1];
				}
				else //19行目から上の判定は無しに設定
				{
					FieldMino[tx][0] = 0;
					mino_color[tx][0] = 0;
				}
			}
		}

	}
}

void Field::MakeMainField() //テトリスフィールドを作成
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			FieldMino[x][y] = 0;
			color[x][y] = 0;
		}
	}

}

void Field::DrawMainField() //テトリスフィールドに30×30の枠線をつけ分かりやすくする
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			int Field_Cell_x = 220 + (x + 1)*Piece_Cell_Width;
			int Field_Cell_y = -5 + (y + 1)*Piece_Cell_Height;

			DrawBox(Field_Cell_x, Field_Cell_y, Field_Cell_x + Piece_Cell_Width, Field_Cell_y + Piece_Cell_Height, GetColor(255, 255, 255), false);
		}
	}
	DrawBox(250, 25, 550, 625, GetColor(255, 255, 255), false); //メインフィールドの描画
}

void Field::DrawMainField2() //テトリスフィールドに配置されたテトリミノに画像を付ける
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			int Field_Cell_x = (x + 1)*Piece_Cell_Width;
			int Field_Cell_y = (y + 1)*Piece_Cell_Height;

			if (FieldMino != 0)
			{
				switch (mino_color[x][y]) //mino_color変数ごとに画像を配置(Tetrimino::Minoを参照)　　　　画像は追加予定
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

void Field::DrawSabField()
{
	DrawBox(25, 35, 225, 235, GetColor(255, 255, 255), false); //第1ホールド
	DrawBox(25, 255, 225, 455, GetColor(255, 255, 255), false); //第2ホールド
	DrawBox(575, 35, 775, 235, GetColor(255, 255, 255), false); // ネクスト
	DrawBox(600, 250, 750, 400, GetColor(255, 255, 255), false); //ネクネク
	DrawBox(600, 415, 750, 565, GetColor(255, 255, 255), false); //ネクスト3
	DrawBox(590, 600, 820, 630, GetColor(255, 255, 255), false); //全消しゲージ
}

void Field::AllDelete() //全消しポイントが100ポイント貯まると、任意のタイミングで特定の1面を全消しできる
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			FieidMino[x][y] = 0; //テトリスフィールド上の判定を全て消去
			color[x][y] = 0; //テトリスフィールドのテトリミノの色を消去

		}
	}
	AllDeletePoint = 0;
}