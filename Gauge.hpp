#pragma once

class Gauge
{
public:
	Gauge();
	~Gauge();

	int AllDeletePoint; //全消しするために貯めるポイント

	void AllDelete(); //全消しポイントが100ポイント貯まると、任意のタイミングで特定の1面を全消しできる

private:
	
};