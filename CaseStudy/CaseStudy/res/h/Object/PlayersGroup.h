//========================================================================================
//		File        : PlayerGroups.h
//		Program     : プレイヤーども
//
//		Description : プレイヤーども個別の動き
//						プレイヤーの初期化はここではないとこでやって
//						プレイヤーの後始末はここで一括で行う
//
//		History     : 2015/05/11	作成開始
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
#include "../System/MapData.h"
#include "../Object/Stage.h"
#include "../Object/Player.h"
#include "../Object/Character.h"

//――――――――――――――――――――――――――――――――――――――――――――
// 定数定義
//――――――――――――――――――――――――――――――――――――――――――――


//――――――――――――――――――――――――――――――――――――――――――――
// クラス定義
//――――――――――――――――――――――――――――――――――――――――――――
class CPlayersGroup
{
private:
		
	int								m_nCurrentControllNo;		// 現在の番号

	std::list<CPlayer*>				m_list;						// 種共(追加と削除が楽そうという小並感から)
	std::list<CPlayer*>::iterator	m_listIt;					// イテレータ(いっぱい使いそうだからここに用意しとく)



	CStage*							m_pStage;					// ステージデータ
	
	LPCTSTR							m_lpTex;					// Playerのテクスチャ

	bool							m_bOver;					// ゲームオーバかどうか

public:	
	CPlayersGroup();
	virtual void Init();
	virtual void Uninit();
	virtual void Update();
	virtual void Draw();

	void AddPlayer(CPlayer* p);							// 集合にPlayerを追加
	void AddPlayer(D3DXVECTOR3 pos);

	void PlayersTranslateZ(float z);
	void TactilesTranslateZ(float z);

	void ClearDirection();

	// ----- セッター
	void SetPlaylNo(int no){m_nCurrentControllNo = no;}
	void SetTexture(const LPCTSTR tex){m_lpTex = tex;}
	void SetStage(CStage* s){m_pStage = s;}

	// ----- ゲッター
	int GetPlayNo(){return m_nCurrentControllNo;}
	int GetGroupSize(){return m_list.size();}
	bool GetOver(){return m_bOver;}
	CPlayer* GetPlayer(int no);
	
	// ----- デバッグ用
	void		AddPlayer();						// プレイヤー追加
	void		RedusePlayer();						// プレイヤー削除

	static CPlayersGroup* Create(const LPCTSTR pszFName);	// 生成
};
//========================================================================================
//	End of File
//========================================================================================