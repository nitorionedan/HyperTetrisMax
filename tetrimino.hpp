class Tetrimino{

public:
	Tetrimino();
	~Tetrimino();

	const int piece_width = 4; //�e�g���~�m�̉��̃}�X��
	const int piece_height = 4; //�e�g���~�m�̏c�̃}�X��

	void Update();
	void Draw();

private:
	int gh_mino[10];
};