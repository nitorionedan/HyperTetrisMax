class Tetrimino{

public:
	Tetrimino();
	~Tetrimino();

	const int piece_width = 4; //テトリミノの横のマス数
	const int piece_height = 4; //テトリミノの縦のマス数
	const int Piece_Cell_Width = 30; //テトリミノの横のピクセル数
	const int Piece_Cell_Height = 30; //テトリミノの縦のピクセル数
	int mino[4][4];//現在移動中のブロック
	int mino_position_x; //現在移動中のテトリミノのx座標(左上の頂点)
	int mino_position_y; //現在移動中のテトリミノのy座標(左上の頂点)
	int piece_right;
	int piece_left;
	int piece_up;
	int piece_bottom;
	bool move; //テトリミノの移動判定
	int mino_color[4][4];//現在移動中のブロックの色
	int HoldMino1[4][4]; //第1ホールド
	int HoldMino2[4][4]; //第2ホールド
	int HoldMino1_Color[4][4]; //第1ホールドの色
	int HoldMino2_Color[4][4]; //第2ホールドの色
	int NextMino1[4][4]; //ネクスト
	int NextMino2[4][4]; //ネクネク
	int NextMino3[4][4]; //ネクスト3
	int NextMino1_Color[4][4]; //ネクストミノの色
	int NextMino2_Color[4][4]; //ネクネクミノの色
	int NextMino3_Color[4][4]; //ネクスト3ミノの色

	void Update();
	void Draw();
	void Mino_teigi(); //テトリミノ用の4×4の配列を作る
	void Mino1(); //I型テトリミノ
	void Mino2(); //□型テトリミノ
	void Mino3(); //Z型テトリミノ
	void Mino4(); //型反対テトリミノ
	void Mino5(); //L型テトリミノ
	void Mino6(); //L2型テトリミノ
	void Mino7(); //T型テトリミノ
	Tetrimino& Create_Mino(); //実際のテトリミノを作成する
	void Copy_Mino(); //作ったテトリミノをコピーし落下用のテトリミノを作成
	void Move_Mino_Down(); //落下するテトリミノ
	void Draw_Falling_Mino(); //落下していくテトリミノを描画
	void Search_Piece_Boundary(); //フィールドに配置されたピースの判定を検出
	void Turn_right(); //テトリミノ右回転
	void Turn_left(); // テトリミノ左回転
	void Hold(); //テトリミノをホールドする
	void Next(); //ネクストテトリミノを配置する



private:
	int gh_mino[10]; //テトリミノの画像
	int gh_mino_piece[10]; //テトリミノのピースの画像
};