#pragma once
#include "struct.h" 

class Circle{
protected:
	//メンバ変数
	Vector2<float> pos_;
	Vector2<int> radius_;
	Vector2<float> velocity_;
	unsigned int color_;

public:
	//コンストラクタ,デストラクタ
	Circle();
	virtual ~Circle();

	//メンバ関数
	/// <summary>
	/// アップデート関数
	/// </summary>
	virtual void Update(const char* keys [[maybe_unused]] );

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();
};