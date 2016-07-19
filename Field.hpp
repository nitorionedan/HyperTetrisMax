#pragma once


class Field {
	Field();
	~Field();

public:
	static const int FieldWidth = 10; // �e�g���X�t�B�[���h�̉��̃}�X��
	static const int FieldHeight = 20; //�e�g���X�t�B�[���h�̏c�̃}�X��

	const int Window_Width_Cell = 850; //�E�B���h�E�T�C�Y��
	const int Window_Height_Cell = 650; //�E�B���h�E�T�C�Y�c
	const int FieldMino[FieldWidth][FieldHeight]; //�e�g���X�t�B�[���h�̃}�X
	int AllDeletePoint = 0; //�S�������邽�߂ɒ��߂�|�C���g

	int DeleteLine(); //���܂����s������
	void MinoShift(int DeleteCount); //��������ւ��炷
	void MakeMainField(); //�e�g���X�t�B�[���h���쐬
	void DrawMainField(); //�e�g���X�t�B�[���h��30�~30�̘g������������₷������
	void DrawMainField2(); //�e�g���X�t�B�[���h�ɔz�u���ꂽ�e�g���~�m�ɉ摜��t����
	void DrawSabField(); //�l�N�X�g�A�z�[���h���̃{�b�N�X��`��
	void AllDelete(); //�S�����|�C���g��100�|�C���g���܂�ƁA�C�ӂ̃^�C�~���O�œ����1�ʂ�S�����ł���


private:
    int color[FieldWidth][FieldHeight]; //�e�g���X�t�B�[���h�̐F

};