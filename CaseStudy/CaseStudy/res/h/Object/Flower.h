//========================================================================================
//		File        : Player.h
//		Program     : プレイヤー
//
//		Description : プレイヤー個別の動き
//
//		History     : 2015/05/6	作成開始
//						   
//
//																Author : きんたまズ
//========================================================================================

#pragma once

//――――――――――――――――――――――――――――――――――――――――――――
// インクルード
//――――――――――――――――――――――――――――――――――――――――――――
#include "../System/PreInclude.h"
#
#include <d3d9.h>
#include <d3dx9.h>
#include "../System/Input.h"
#include "../System/System.h"
#include "../Object/Character.h"
#include "../Object/Stage.h"

//――――――――――――――――――――――――――――――――――――――――――――
// 定数定義
//――――――――――――――――――――――――――――――――――――――――――――
const int FLOWER_ANIME_SIZE_X = 1;	// テクスチャ
const int FLOWER_ANIME_SIZE_Y = 1;

const float FLOWER_POS_DEFAULT_X = -200;
const float FLOWER_POS_DEFAULT_Y = 100;

const float FLOWER_SIZE_X = 147;
const float FLOWER_SIZE_Y = 151;

enum
{
	FLOWER_PHASE_INIT = 0,
	FLOWER_PHASE_START,
	FLOWER_PHASE_FLOWER,
	FLOWER_PHASE_WAIT,
	FLOWER_PHASE_UNINIT
};

//――――――――――――――――――――――――――――――――――――――――――――
// クラス定義
//――――――――――――――――――――――――――――――――――――――――――――
class CFlower : public CCharacter
{
// ----- 定数
public:
	enum _eType {
		TYPE_FLOWER = 0,
		TYPE_JACK,
		TYPE_STONE,

		MAX_TYPE
	};

private:
	CObject2D* m_kuki;
	
protected:
	double	m_angle;
	int		m_nPhase;

	double m_nowTime;
	double m_lastTime;

	float	m_rotSpd;

	int		m_stageType;	// 出現するステージの種別

	int		m_type;

	double AngleOf2Vector(D3DXVECTOR3 A, D3DXVECTOR3 B );
public:
	CFlower();
	virtual void Init(D3DXVECTOR3 pos,D3DXVECTOR3 dir,const LPCTSTR pszFName);			// 初期化
	virtual void Uninit();
	virtual void Update();
	virtual void Animation();// アニメ			これクラスにした方がいいのかな
	virtual void Draw();
	static CFlower* Create(const LPCTSTR pszFName);			// 生成

	// ----- セッター
	void SetPhase(int no){m_nPhase = no;}
	void SetStageType(int type) {m_stageType = type;}
	void SetType(int type) {m_type = type;}

	// ----- ゲッター
	int GetPhase(){return m_nPhase;}
	int GetStageType() const {return m_stageType;}
	int GetType() const {return m_type;}
};

//========================================================================================
//	End of File
//========================================================================================