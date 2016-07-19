#pragma once


class Field {
	Field();
	~Field();

public:
	static const int FieldWidth = 10; // テトリスフィールドの横のマス数
	static const int FieldHeight = 20; //テトリスフィールドの縦のマス数

	const int Window_Width_Cell = 850; //ウィンドウサイズ横
	const int Window_Height_Cell = 650; //ウィンドウサイズ縦
	const int FieldMino[FieldWidth][FieldHeight]; //テトリスフィールドのマス
	int AllDeletePoint = 0; //全消しするために貯めるポイント

	int DeleteLine(); //埋まった行を消す
	void MinoShift(int DeleteCount); //判定を下へずらす
	void MakeMainField(); //テトリスフィールドを作成
	void DrawMainField(); //テトリスフィールドに30×30の枠線をつけ分かりやすくする
	void DrawMainField2(); //テトリスフィールドに配置されたテトリミノに画像を付ける
	void DrawSabField(); //ネクスト、ホールド等のボックスを描画
	void AllDelete(); //全消しポイントが100ポイント貯まると、任意のタイミングで特定の1面を全消しできる


private:
    int color[FieldWidth][FieldHeight]; //テトリスフィールドの色

};