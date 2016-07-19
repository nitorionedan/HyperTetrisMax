#include "Field.hpp"
#include "tetrimino.hpp"
#include "DxLib.h"

Field::Field()
{

}

Field::~Field()
{

}

int Field::DeleteLine() //���܂����s������
{
	int DeleteCount = 0;
	
	for (int y = FieldHeight - 1; y > 0; y--)
	{
		int xNumPerLine = 0;
		for (int x = 0; x < FieldWidth; x++)
		{
			if (FieldMino[x][y])
			{
				xNumPerLine++;
			}
		}
		if (xNumPerLine != FieldWidth)
		{
			continue;
		}
		DeleteCount++;
		for (int x = 0; x < FieldWidth; x++)
		{
			FieldMino[x][y] = 0;
		}
	}
  //AllDeletePoint = AllDeletePoint + DeleteCount; //�����s���S�����|�C���g�𒙂߂Ă���
	return DeleteCount;
}

void Field::MinoShift(int DeleteCount) //��������ւ��炷
{
	for (int y = FieldHeight - 1; y >= 0 && DeleteCount > 0;) //Field::DeleteLine�ŕԂ��ꂽ�s���J��Ԃ�
	{
		int xNumPerLine = 0;
		for (int x = 0; x < FieldWidth; x++)
		{
			if (FieldMino[x][y])
			{
				xNumPerLine++;
			}
		}
		if (xNumPerLine != 0) //1�s���ׂď�����Ă��Ȃ����1�s����m�F����(countinue���Ń��[�v�𔲂���)
		{
			y--;
			continue;
		}
		DeleteCount--; //1�s���ׂĔ��肪�������
		for (int ty = y; ty >= 0; ty--) //�������炷�ׂĂ�FieldMino�z���1�s�������Ă���
		{
			for (int tx = 0; tx < FieldWidth; tx++)
			{
				if (ty - 1 > -0)
				{
					FieldMino[tx][ty] = FieldMino[tx][ty - 1];
					mino_color[tx][ty] = mino_color[tx][ty - 1];
				}
				else //19�s�ڂ����̔���͖����ɐݒ�
				{
					FieldMino[tx][0] = 0;
					mino_color[tx][0] = 0;
				}
			}
		}

	}
}

void Field::MakeMainField() //�e�g���X�t�B�[���h���쐬
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			FieldMino[x][y] = 0;
			color[x][y] = 0;
		}
	}

}

void Field::DrawMainField() //�e�g���X�t�B�[���h��30�~30�̘g������������₷������
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			int Field_Cell_x = 220 + (x + 1)*Piece_Cell_Width;
			int Field_Cell_y = -5 + (y + 1)*Piece_Cell_Height;

			DrawBox(Field_Cell_x, Field_Cell_y, Field_Cell_x + Piece_Cell_Width, Field_Cell_y + Piece_Cell_Height, GetColor(255, 255, 255), false);
		}
	}
	DrawBox(250, 25, 550, 625, GetColor(255, 255, 255), false); //���C���t�B�[���h�̕`��
}

void Field::DrawMainField2() //�e�g���X�t�B�[���h�ɔz�u���ꂽ�e�g���~�m�ɉ摜��t����
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			int Field_Cell_x = (x + 1)*Piece_Cell_Width;
			int Field_Cell_y = (y + 1)*Piece_Cell_Height;

			if (FieldMino != 0)
			{
				switch (mino_color[x][y]) //mino_color�ϐ����Ƃɉ摜��z�u(Tetrimino::Mino���Q��)�@�@�@�@�摜�͒ǉ��\��
				{
				case 1:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[1], true); //gh_mino_piece=�e�g���~�m�̃s�[�X�摜
					break;
				case 2:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[2], true);
					break;
				case 3:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[3], true);
					break;
				case 4:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[4], true);
					break;
				case 5:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[5], true);
					break;
				case 6:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[6], true);
					break;
				case 7:
					DrawGraph(Field_Cell_x, Field_Cell_y, gh_mino_piece[7], true);
					break;

				}
			}
		}
	}
}

void Field::DrawSabField()
{
	DrawBox(25, 35, 225, 235, GetColor(255, 255, 255), false); //��1�z�[���h
	DrawBox(25, 255, 225, 455, GetColor(255, 255, 255), false); //��2�z�[���h
	DrawBox(575, 35, 775, 235, GetColor(255, 255, 255), false); // �l�N�X�g
	DrawBox(600, 250, 750, 400, GetColor(255, 255, 255), false); //�l�N�l�N
	DrawBox(600, 415, 750, 565, GetColor(255, 255, 255), false); //�l�N�X�g3
	DrawBox(590, 600, 820, 630, GetColor(255, 255, 255), false); //�S�����Q�[�W
}

void Field::AllDelete() //�S�����|�C���g��100�|�C���g���܂�ƁA�C�ӂ̃^�C�~���O�œ����1�ʂ�S�����ł���
{
	for (int y = 0; y < FieldHeight; y++)
	{
		for (int x = 0; x < FieldWidth; x++)
		{
			FieidMino[x][y] = 0; //�e�g���X�t�B�[���h��̔����S�ď���
			color[x][y] = 0; //�e�g���X�t�B�[���h�̃e�g���~�m�̐F������

		}
	}
	AllDeletePoint = 0;
}