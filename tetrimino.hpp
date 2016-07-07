class Tetrimino{

public:
	Tetrimino();
	~Tetrimino();

	const int piece_width = 4; //テトリミノの横のマス数
	const int piece_height = 4; //テトリミノの縦のマス数

	void Update();
	void Draw();

private:
	int gh_mino[10];
};