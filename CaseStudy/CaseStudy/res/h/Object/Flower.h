//========================================================================================
//		File        : Player.h
//		Program     : �v���C���[
//
//		Description : �v���C���[�ʂ̓���
//
//		History     : 2015/05/6	�쐬�J�n
//						   
//
//																Author : ���񂽂܃Y
//========================================================================================

#pragma once

//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
// �C���N���[�h
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
#include "../System/PreInclude.h"
#
#include <d3d9.h>
#include <d3dx9.h>
#include "../System/Input.h"
#include "../System/System.h"
#include "../Object/Character.h"
#include "../Object/Stage.h"

//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
// �萔��`
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
const int FLOWER_ANIME_SIZE_X = 1;	// �e�N�X�`��
const int FLOWER_ANIME_SIZE_Y = 1;

const float FLOWER_POS_DEFAULT_X = -200;
const float FLOWER_POS_DEFAULT_Y = 100;

const float FLOWER_SIZE_X = 147;
const float FLOWER_SIZE_Y = 151;

//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
// �N���X��`
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
class CFlower : public CCharacter
{
private:
	
protected:
	
public:
	CFlower();
	virtual void Init(D3DXVECTOR3 pos,float angle);			// ������
	virtual void Uninit();
	virtual void Update();
	virtual void Animation();								// �A�j��			����N���X�ɂ������������̂���
	static CFlower* Create(const LPCTSTR pszFName);			// ����

	// ----- �Z�b�^�[

	// ----- �Q�b�^�[
	
};
//========================================================================================
//	End of File
//========================================================================================