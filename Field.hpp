#pragma once
#include "tetrimino.hpp"

class Field { //��Ƀt�B�[���h�̏����A�`�������N���X

public:
	Field();
	~Field();

	static const int FieldWidth = 10; // �e�g���X�t�B�[���h�̉��̃}�X��
	static const int FieldHeight = 20; //�e�g���X�t�B�[���h�̏c�̃}�X��

	//const int Window_Width_Cell = 850; //�E�B���h�E�T�C�Y��   �����
	//const int Window_Height_Cell = 650; //�E�B���h�E�T�C�Y�c�@�����
    static int FieldMino[FieldWidth][FieldHeight]; //�e�g���X�t�B�[���h�̃}�X
	static int FieldColor[FieldWidth][FieldHeight];

	void Update(Tetrimino* mino);
	void Draw();
	int DeleteLine(Tetrimino* mino); //���܂����s������
	void MinoShift(int DeleteCount); //��������ւ��炷
	void MakeMainField(Tetrimino* mino); //�e�g���X�t�B�[���h���쐬
	void DrawMainField(); //�e�g���X�t�B�[���h��30�~30�̘g������������₷������
	void DrawFieldMino(); //�e�g���X�t�B�[���h�ɔz�u���ꂽ�e�g���~�m�ɉ摜��t����
	void DrawSubField(); //�l�N�X�g�A�z�[���h���̃{�b�N�X��`��
	int gh_mino[10]; //�e�g���~�m�̉摜
	int gh_mino_piece[10]; //�e�g���~�m�̃s�[�X�̉摜

private:

};