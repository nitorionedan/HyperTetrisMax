#ifndef DEF_GAME_HPP
#define DEF_GAME_HPP

#include "BaseScene.hpp"
#include "ISceneChanger.hpp"
#include "tetrimino.hpp"
#include "Field.hpp"
#include "Gauge.hpp"


//ゲーム画面クラス
class Game : public BaseScene
{
public:
	Game::Game(ISceneChanger* changer);
	~Game();
	void Update() override;     //更新処理をオーバーライド
	void Draw() override;       //描画処理をオーバーライド
	
private:
	Tetrimino* tetrimino;
	Field* field;
};

#endif
// EOF