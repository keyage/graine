//========================================================================================
//		File        : GameClear.h
//		Program     : ゲームクリアウィンドウ
//
//		Description : ゲームクリアウィンドウの定義
//
//		History     : 2015/06/22	作成開始
//						   
//
//																Author : Kei Hashimoto
//========================================================================================

#pragma once

//――――――――――――――――――――――――――――――――――――――――――――
// インクルード
//――――――――――――――――――――――――――――――――――――――――――――
#include "../System/PreInclude.h"
#
#include <d3d9.h>
#include <d3dx9.h>
#include "../Object/Camera.h"
#include "../Object/Button.h"

//――――――――――――――――――――――――――――――――――――――――――――
// クラス定義
//――――――――――――――――――――――――――――――――――――――――――――
class CGameClear
{
// ===== メンバ定数
public:
	enum
	{
		PHASE_INIT = 0,
		PHASE_INIT_DIRECTION,
		PHASE_FADEIN_DIRECTION,
		PHASE_DIRECTION,
		PHASE_UNINIT_DIRECTION,
		PHASE_WAIT,
		PHASE_ENTER,
		PHASE_UNINIT,
		PHASE_END,

		PHASE_MAX
	};

private:
	enum
	{
		GO_NEXT = 0,
		GO_SELECT
	};

	enum{
		NEXT_BUTTON = 0,
		GOSELECT_BUTTON,

		MAX_BUTTON
	};

	enum{
		TEX_WND_0	= 0,
		TEX_BUTTON_0,

		MAX_TEX
	};

	static const D3DXVECTOR2 W_0_DEFAULET_SIZE;
	static const D3DXVECTOR3 W_0_DEFAULET_POS;

	static const float B_0_POS_INTERVAL_X;

	static const D3DXVECTOR2 B_0_DEFAULET_SIZE;
	static const D3DXVECTOR3 B_0_DEFAULET_POS;

	static const D3DXVECTOR2 B_1_DEFAULET_SIZE;
	static const D3DXVECTOR3 B_1_DEFAULET_POS;
	
	static const LPCTSTR TEX_FILENAME[];			// テクスチャのファイル名

	static const D3DXVECTOR3 DIRECTION_CAMERA_SPD;		//　演出時のカメラ移動速度

// ===== メンバ変数
private:
	int				m_nPhase;
	int				m_nCurButton;

	int				m_nGo;			// 行先

	CTexture*		m_pWnd;

	CButton*		m_pButtonNext;
	CButton*		m_pButtonGoSelect;

	vector<CButton*> m_vecButton;

	CCamera*		m_pCamera;
	float			m_dirDist;

public:
	virtual void Initialize();
	virtual void Init();
	virtual void Uninit();
	virtual void Update();
	virtual void Draw();

	// ----- ゲッター
	int GetPhase(){return m_nPhase;}
	int GetGo(){return m_nGo;}

	// ----- セッター
	void SetPhase(int no){m_nPhase = no;}
	void SetCamera(CCamera* pCamera) {m_pCamera = pCamera;}
	void SetDirectionDistance(float distance) {m_dirDist = distance;}

	CGameClear();
	static CGameClear* Create();	// 生成
	void Release();

private:
	bool InitDirection();
	void FadeinDirection();
	void Direction();
	void UninitDirection();
	void Wait();
	void Enter();
};

//========================================================================================
//	End of File
//========================================================================================