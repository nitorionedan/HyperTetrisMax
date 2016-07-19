class Tetrimino{

public:
	Tetrimino();
	~Tetrimino();

	const int piece_width = 4; //�e�g���~�m�̉��̃}�X��
	const int piece_height = 4; //�e�g���~�m�̏c�̃}�X��
	const int Piece_Cell_Width = 30; //�e�g���~�m�̉��̃s�N�Z����
	const int Piece_Cell_Height = 30; //�e�g���~�m�̏c�̃s�N�Z����
	int mino[4][4];//���݈ړ����̃u���b�N
	int mino_position_x; //���݈ړ����̃e�g���~�m��x���W(����̒��_)
	int mino_position_y; //���݈ړ����̃e�g���~�m��y���W(����̒��_)
	int piece_right;
	int piece_left;
	int piece_up;
	int piece_bottom;
	bool move; //�e�g���~�m�̈ړ�����
	int mino_color[4][4];//���݈ړ����̃u���b�N�̐F
	int HoldMino1[4][4]; //��1�z�[���h
	int HoldMino2[4][4]; //��2�z�[���h
	int HoldMino1_Color[4][4]; //��1�z�[���h�̐F
	int HoldMino2_Color[4][4]; //��2�z�[���h�̐F
	int NextMino1[4][4]; //�l�N�X�g
	int NextMino2[4][4]; //�l�N�l�N
	int NextMino3[4][4]; //�l�N�X�g3
	int NextMino1_Color[4][4]; //�l�N�X�g�~�m�̐F
	int NextMino2_Color[4][4]; //�l�N�l�N�~�m�̐F
	int NextMino3_Color[4][4]; //�l�N�X�g3�~�m�̐F

	void Update();
	void Draw();
	void Mino_teigi(); //�e�g���~�m�p��4�~4�̔z������
	void Mino1(); //I�^�e�g���~�m
	void Mino2(); //���^�e�g���~�m
	void Mino3(); //Z�^�e�g���~�m
	void Mino4(); //�^���΃e�g���~�m
	void Mino5(); //L�^�e�g���~�m
	void Mino6(); //L2�^�e�g���~�m
	void Mino7(); //T�^�e�g���~�m
	Tetrimino& Create_Mino(); //���ۂ̃e�g���~�m���쐬����
	void Copy_Mino(); //������e�g���~�m���R�s�[�������p�̃e�g���~�m���쐬
	void Move_Mino_Down(); //��������e�g���~�m
	void Draw_Falling_Mino(); //�������Ă����e�g���~�m��`��
	void Search_Piece_Boundary(); //�t�B�[���h�ɔz�u���ꂽ�s�[�X�̔�������o
	void Turn_right(); //�e�g���~�m�E��]
	void Turn_left(); // �e�g���~�m����]
	void Hold(); //�e�g���~�m���z�[���h����
	void Next(); //�l�N�X�g�e�g���~�m��z�u����



private:
	int gh_mino[10]; //�e�g���~�m�̉摜
	int gh_mino_piece[10]; //�e�g���~�m�̃s�[�X�̉摜
};