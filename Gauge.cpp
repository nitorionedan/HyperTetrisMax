#include "Gauge.hpp"
#include "Field.hpp"


	Gauge::Gauge()
	{
		AllDeletePoint = 0; //�S�������邽�߂ɒ��߂�|�C���g
	}

	Gauge::~Gauge()
	{

	}

	void Gauge::AllDelete() //�S�����|�C���g��100�|�C���g���܂�ƁA�C�ӂ̃^�C�~���O�œ����1�ʂ�S�����ł���
	{
		for (int y = 0; y < Field::FieldHeight; y++)
		{
			for (int x = 0; x < Field::FieldWidth; x++)
			{
				Field::FieldMino[x][y] = 0; //�e�g���X�t�B�[���h��̔����S�ď���
				Field::FieldColor[x][y] = 0; //�e�g���X�t�B�[���h�̃e�g���~�m�̐F������

			}
		}
		AllDeletePoint = 0;
	}