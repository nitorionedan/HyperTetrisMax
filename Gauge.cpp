#include "Gauge.hpp"
#include "Field.hpp"


	Gauge::Gauge()
	{
		AllDeletePoint = 0; //全消しするために貯めるポイント
	}

	Gauge::~Gauge()
	{

	}

	void Gauge::AllDelete() //全消しポイントが100ポイント貯まると、任意のタイミングで特定の1面を全消しできる
	{
		for (int y = 0; y < Field::FieldHeight; y++)
		{
			for (int x = 0; x < Field::FieldWidth; x++)
			{
				Field::FieldMino[x][y] = 0; //テトリスフィールド上の判定を全て消去
				Field::FieldColor[x][y] = 0; //テトリスフィールドのテトリミノの色を消去

			}
		}
		AllDeletePoint = 0;
	}