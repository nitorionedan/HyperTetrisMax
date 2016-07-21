#pragma once
#include "tetrimino.hpp"

class Field { //主にフィールドの処理、描画をするクラス

public:
	Field();
	~Field();

	static const int FieldWidth = 10; // テトリスフィールドの横のマス数
	static const int FieldHeight = 20; //テトリスフィールドの縦のマス数

	//const int Window_Width_Cell = 850; //ウィンドウサイズ横   いらん
	//const int Window_Height_Cell = 650; //ウィンドウサイズ縦　いらん
    static int FieldMino[FieldWidth][FieldHeight]; //テトリスフィールドのマス
	static int FieldColor[FieldWidth][FieldHeight];

	void Update(Tetrimino* mino);
	void Draw();
	int DeleteLine(Tetrimino* mino); //埋まった行を消す
	void MinoShift(int DeleteCount); //判定を下へずらす
	void MakeMainField(Tetrimino* mino); //テトリスフィールドを作成
	void DrawMainField(); //テトリスフィールドに30×30の枠線をつけ分かりやすくする
	void DrawFieldMino(); //テトリスフィールドに配置されたテトリミノに画像を付ける
	void DrawSubField(); //ネクスト、ホールド等のボックスを描画
	int gh_mino[10]; //テトリミノの画像
	int gh_mino_piece[10]; //テトリミノのピースの画像

private:

};