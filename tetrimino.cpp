#include "tetrimino.hpp"
#include "Field.hpp"
#include "Dxlib.h"
#include <algorithm>


int Tetrimino::mino_color[4][4];//���݈ړ����̃u���b�N�̐F


Tetrimino::Tetrimino() //���[�h������delete
{
	gh_mino[0] = LoadGraph("mino0.png"); //�e�g���~�m�̉摜
	gh_mino[1] = LoadGraph("mino1.png");
	gh_mino[2] = LoadGraph("mino2.png");
	gh_mino[3] = LoadGraph("mino3.png");
	gh_mino[4] = LoadGraph("mino4.png");
	gh_mino[5] = LoadGraph("mino5.png");
	gh_mino[6] = LoadGraph("mino6.png");

	gh_mino_piece[0] = LoadGraph("mino_piece0.png"); //�e�g���~�m�̃s�[�X�̉摜
	gh_mino_piece[1] = LoadGraph("mino_piece1.png");
	gh_mino_piece[2] = LoadGraph("mino_piece2.png");
	gh_mino_piece[3] = LoadGraph("mino_piece3.png");
	gh_mino_piece[4] = LoadGraph("mino_piece4.png");
	gh_mino_piece[5] = LoadGraph("mino_piece5.png");
	gh_mino_piece[6] = LoadGraph("mino_piece6.png");

	state = eTetrimino_None;


}
	

Tetrimino::~Tetrimino()
{
	for (int i = 0; i < sizeof(gh_mino) / sizeof(gh_mino[0]); i++)
	{
		if (gh_mino[i] != 0 && gh_mino[i] != -1)
			DeleteGraph(gh_mino[i]);

		if (gh_mino_piece[i] != 0 && gh_mino_piece[i] != -1)
			DeleteGraph(gh_mino_piece[i]);
	}
}


void Tetrimino::Update() //����������
{
	switch (state)
	{
	case eTetrimino_Falling:
		Turn_right();
		Turn_left();
		//����
		break;
	case eTetrimino_Next1:
		//�l�N�X�g
	}

	Mino_Teigi();
	Create_Mino();
	Hold();
}

void Tetrimino::Draw() //�`�������
{

}

void Tetrimino::Mino_Teigi() //�e�g���~�m�p��4�~4�̔z������
{
	for (int x = 0; x >piece_height; x++)
		for (int y = 0; y > piece_width; y++)
		{
			mino[x][y] = 0; //4�~4�̋󔒂̔z������
			mino_color[x][y] = 0; //�F�����߂�
		}
}

Tetrimino& Tetrimino::Create_Mino() //���ۂ̃e�g���~�m���쐬����
{
	int Random = rand() % 7 + 1;
	Tetrimino::Mino_Teigi();
	
	// �ꎞ�I�ȃe�g���~�m
	Tetrimino mino;

	switch (Random) {
	case 1:
		mino.mino[1][0] = 1;
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[1][3] = 1;

		mino.mino_color[1][0] = 1; //�F���`
		mino.mino_color[1][1] = 1;
		mino.mino_color[1][2] = 1;
		mino.mino_color[1][3] = 1;
		
		return	mino;	// ����ݒ肵���~�m��Ԃ�

	case 2:
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[2][1] = 1;
		mino.mino[2][2] = 1;

		mino.mino_color[1][1] = 2;
		mino.mino_color[1][2] = 2;
		mino.mino_color[2][1] = 2;
		mino.mino_color[2][2] = 2;

		return mino;

	case 3:
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[2][2] = 1;
		mino.mino[2][3] = 1;

		mino.mino_color[1][1] = 3;
		mino.mino_color[1][2] = 3;
		mino.mino_color[2][2] = 3;
		mino.mino_color[2][3] = 3;

		return mino;

	case 4:
		mino.mino[2][1] = 1;
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[0][2] = 1;

		mino.mino_color[2][1] = 4;
		mino.mino_color[1][1] = 4;
		mino.mino_color[1][2] = 4;
		mino.mino_color[0][2] = 4;

		return mino;

	case 5:
		mino.mino[1][1] = 1;
		mino.mino[2][1] = 1;
		mino.mino[2][2] = 1;
		mino.mino[2][3] = 1;

		mino.mino_color[1][1] = 5;
		mino.mino_color[2][1] = 5;
		mino.mino_color[2][2] = 5;
		mino.mino_color[2][3] = 5;

		return mino;

	case 6:
		mino.mino[2][1] = 1;
		mino.mino[1][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[1][3] = 1;

		mino.mino_color[2][1] = 6;
		mino.mino_color[1][1] = 6;
		mino.mino_color[1][2] = 6;
		mino.mino_color[1][3] = 6;

		return mino;

	case 7:
		mino.mino[2][1] = 1;
		mino.mino[1][2] = 1;
		mino.mino[2][2] = 1;
		mino.mino[3][2] = 1;

		mino.mino_color[2][1] = 7;
		mino.mino_color[1][2] = 7;
		mino.mino_color[2][2] = 7;
		mino.mino_color[3][2] = 7;

		return mino;

	default:	printfDx("����Ȃ��̂͂Ȃ�\n");	break;
	}

	return mino;
}

void Tetrimino::Copy_Mino() //������e�g���~�m���R�s�[�������p�̃e�g���~�m���쐬
{
	Tetrimino mino;

	for (int x = 0; x < piece_width; x++)
	{
		for (int y = 0; y < piece_height; y++)
		{
			this->mino[x][y] = mino.mino[x][y]; //���������e�g���~�m���R�s�[
			this->mino_color[x][y] = mino.mino_color[x][y];
		}
	}
	
}

void Tetrimino::Move_Mino_Down() //��������e�g���~�m
{

}

void Tetrimino::Draw_Falling_Mino() //�������Ă����e�g���~�m��`��
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


void Tetrimino::Turn_right() //�e�g���~�m�E��]
{
	int KeepMino[4][4]; //��U�ۗ����邽�߂̔z���p��
	int KeepColor[4][4]; //��U�ۗ����邽�߂̔z���p��

	for (int x = piece_width - 1; x >= 0; x--)
	{
		for (int y = 0; y < piece_height; y++)
		{
			KeepMino[x][y] = mino[y][abs(x-3)]; //���ۗ���
			mino[y][abs(x - 3)] = KeepMino[y][abs(x - 3)]; //�㏑������

			KeepColor[x][y] = mino_color[y][abs(x - 3)];
			mino_color[y][abs(x - 3)] = KeepColor[y][abs(x - 3)];
		}
	}
}

void Tetrimino::Turn_left() //�e�g���~�m����]
{
	int KeepMino[4][4]; //��U�����ۗ����邽�߂̔z���p��
	int KeepColor[4][4]; //��U�F��ۗ����邽�߂̔z���p��

	for (int x = 0; x < piece_width; x++)
	{
		for (int y = piece_height - 1; y >= 0; y--)
		{
			KeepMino[x][y] = mino[x][abs(y - 3)]; //���ۗ���
			mino[x][abs(y - 3)] = KeepMino[x][abs(y - 3)]; //�㏑������

			KeepColor[x][y] = mino_color[x][abs(y - 3)];
			mino_color[x][abs(y - 3)] = KeepColor[x][abs(y - 3)];
		}
	}
}

void Tetrimino::Hold() //�e�g���~�m���z�[���h����
{
	int KeepMino[4][4];
	int KeepColor[4][4];
	//��1�z�[���h
	for (int y = 0; y < piece_height; y++) //4�~4�̃u���b�N��1���Êi�[���Ă���
	{
		for (int x = 0; x < piece_width; x++)
		{
			std::swap(mino[x][y], HoldMino1[x][y]);

//			KeepMino[x][y] = mino[x][y]; //���݈ړ����̃e�g���~�m����U�i�[
//			mino[x][y] = HoldMino1[x][y]; //�z�[���h���Ă����e�g���~�m�����݈ړ����̃e�g���~�m��
//			HoldMino1[x][y] = KeepMino[x][y]; //��U�i�[���Ă����e�g���~�m���1�z�[���h��

			std::swap(mino_color[x][y], HoldMino1_Color[x][y]);

//			KeepColor[x][y] = mino_color[x][y]; //�e�g���~�m�̐F���z�[���h
//			mino_color[x][y] = HoldMino1_Color[x][y]; //��̂�Ƃ���Ă邱�Ƃ͓���
//			HoldMino1_Color[x][y] = KeepColor[x][y];
		}
	}

	//��2�z�[���h
	for (int y = 0; y < piece_height; y++) //4�~4�̃u���b�N��1���Êi�[���Ă���
	{
		for (int x = 0; x < piece_width; x++)
		{
			std::swap(mino[x][y], HoldMino2[x][y]);

//			KeepMino[x][y] = mino[x][y];
//			mino[x][y] = HoldMino2[x][y];
//			HoldMino2[x][y] = KeepMino[x][y];


			std::swap(mino_color[x][y], HoldMino2_Color[x][y]);

//			KeepColor[x][y] = mino_color[x][y];
//			mino_color[x][y] = HoldMino2_Color[x][y];
//			HoldMino2_Color[x][y] = KeepColor[x][y];
		}
	}

}

void Tetrimino::Next() //�l�N�X�g�e�g���~�m��z�u����
{
	
}

