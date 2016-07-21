#pragma once

enum eTetrimino_State
{
	eTetrimino_Falling,
	eTetrimino_Next1,
    eTetrimino_Next2,
	eTetrimino_Next3,

	eTetrimino_None,
};



class Tetrimino{//��Ƀe�g���~�m�̏����A�`�������N���X

public:
	Tetrimino();
	~Tetrimino();

	const int piece_width = 4; //�e�g���~�m�̉��̃}�X��
	const int piece_height = 4; //�e�g���~�m�̏c�̃}�X��
	static const int Piece_Cell_Width = 30; //�e�g���~�m�̉��̃s�N�Z����
	static const int Piece_Cell_Height = 30; //�e�g���~�m�̏c�̃s�N�Z����
	int mino[4][4];//���݈ړ����̃u���b�N
	int mino_position_x; //���݈ړ����̃e�g���~�m��x���W(����̒��_)
	int mino_position_y; //���݈ړ����̃e�g���~�m��y���W(����̒��_)

	eTetrimino_State state;

	bool move; //�e�g���~�m�̈ړ�����
	static int mino_color[4][4];//���݈ړ����̃u���b�N�̐F
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
	void Mino_Teigi(); //�e�g���~�m�p��4�~4�̔z������
	Tetrimino& Create_Mino(); //���ۂ̃e�g���~�m���쐬����
	void Copy_Mino(); //������e�g���~�m���R�s�[�������p�̃e�g���~�m���쐬
	void Move_Mino_Down(); //��������e�g���~�m
	void Draw_Falling_Mino(); //�������Ă����e�g���~�m��`��
	void Turn_right(); //�e�g���~�m�E��]
	void Turn_left(); // �e�g���~�m����]
	void Hold(); //�e�g���~�m���z�[���h����
	void Next(); //�l�N�X�g�e�g���~�m��z�u����



private:
	int gh_mino[10]; //�e�g���~�m�̉摜
	int gh_mino_piece[10]; //�e�g���~�m�̃s�[�X�̉摜
};