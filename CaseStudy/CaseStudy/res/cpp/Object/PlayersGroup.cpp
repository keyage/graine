//========================================================================================
//		File        : PlayersGroup.h
//		Program     : �v���C���[�ǂ�
//
//		Description : �v���C���[�ǂ��̓���,��΂���
//
//		History     : 2015/05/6	�쐬�J�n
//						   
//
//																Author : ���񂽂܃Y
//========================================================================================


//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
// �C���N���[�h
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
#include "../../h/System/Input.h"
#include "../../h/Object/PlayersGroup.h"

//========================================================================================
// public:
//========================================================================================
// �\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
// using�錾
//�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\
using namespace Input;
//����������������������������������������������������������������������������������������
//	Name        : �R���X�g���N�^
//	Arguments   : None.
//����������������������������������������������������������������������������������������
CPlayersGroup::CPlayersGroup()
{
	m_nCurrentControllNo = 0;		// ���삷����擪�ɃZ�b�g
}
//����������������������������������������������������������������������������������������
//	Name        : ����
//	Description : �I�u�W�F�N�g�𐶐�����
//	Arguments   : pszFName / �ǂݍ��݃t�@�C����
//	Returns     : �I�u�W�F�N�g�f�[�^
//����������������������������������������������������������������������������������������
CPlayersGroup* CPlayersGroup::Create(const LPCTSTR pszFName)
{
	// ----- �ϐ��錾
	CPlayersGroup* pObj;

	// ----- ����������
	pObj = new CPlayersGroup();

	pObj->SetTexture(pszFName);

	return pObj;
}
//����������������������������������������������������������������������������������������
//	Name        : ������
//	Description : �����ȏ�����
//	Arguments   : �Ȃ���
//	Returns     : �Ȃ���
//����������������������������������������������������������������������������������������
void CPlayersGroup::Init()
{
		// �v�f�S���폜
	for(m_listIt = m_list.begin(); m_listIt != m_list.end();)
	{
		// ����ȁAUTSUWA���Ȃ��ƒ�������Ȃ���
		CPlayer* p = *m_listIt;

		// ������
		p->Init();

		// �����΂ɍŌ�ȁ�(�Ă����񂱂ꂢ��Ȃ��ǂ�)
		++m_listIt;
	}

	AddPlayer();
}
//����������������������������������������������������������������������������������������
//	Name        : ��n��
//	Description : �����Ȍ�n��
//	Arguments   : �Ȃ���
//	Returns     : �Ȃ���
//����������������������������������������������������������������������������������������
void CPlayersGroup::Uninit()
{
	// �v�f�S���폜
	for(m_listIt = m_list.begin(); m_listIt != m_list.end();)
	{
		// ����ȁAUTSUWA���Ȃ��ƒ�������Ȃ���
		CPlayer* p = *m_listIt;

		// ��n��
		p->Uninit();

		// ���X�g����v�f���폜
		if( (*m_listIt) == 0 ) {
			 m_listIt = m_list.erase( m_listIt );
			 continue;
		}

		// �����΂ɍŌ�ȁ�(�Ă����񂱂ꂢ��Ȃ��ǂ�)
		++m_listIt;
	}

	m_pStage = NULL;

	CObject2D::Uninit();
}

//����������������������������������������������������������������������������������������
//	Name        : �X�V
//	Description : �����ȍX�V
//	Arguments   : �Ȃ���
//	Returns     : �Ȃ���
//����������������������������������������������������������������������������������������
void CPlayersGroup::Update()
{
	int currentNo = 0;			// ���̔ԍ�
	CPlayer* Player = NULL;			// ���삷����

	// �����p
	int			throwNo = 0;

	if (GetTrgKey(DIK_UP)){
		if(m_list.size() > (unsigned int)m_nCurrentControllNo + 1){
			m_nCurrentControllNo++;
		}
	}

	bool bThrow =false;
	if (GetTrgKey(DIK_Z)){
		bThrow = true;
	}

	if(m_list.size() == 0)
	{
		printf("�I�[�o\n");
		return ;
	}

	// �F�߂�
	for(int i = 0;i < m_pStage->GetColBoxMax();i++){
		m_pStage->GetColBox(i)->SetColor(D3DXVECTOR3(255,255,255));
	}

	// �v�f�S���X�V
	for(m_listIt = m_list.begin(); m_listIt != m_list.end();)
	{
		// UTSUWA���Ȃ��ƒ�������Ȃ���
		CPlayer* p = *m_listIt;

		p->SetStage(m_pStage);

		// �v���C���[�Ɍ��݂̔ԍ����Z�b�g
		p->SetNo(currentNo);
		// ���݂̔ԍ�������ԍ��Ɠ����Ȃ�Player�𑀍�ݒ�ɂ���ȊO�͂��̑��ݒ��
		if(p->GetNo() == m_nCurrentControllNo){
			p->SetPlayerType(P_TYPE_PLAYER);
			Player = p;
		}
		// ���ɕt���Ă���z��
		if(p->GetNo() > m_nCurrentControllNo){
			p->SetPlayerType(P_TYPE_OTHER);
			// ���삷���ݒ�
			p->SetPlayer(GetPlayer(p->GetNo() - 1));
			Player = p;
			
		}
		// ������A��
		if(p->GetNo() < m_nCurrentControllNo){
			// �Ǐ]����v���C���[�����̓z��
			Player = GetPlayer(p->GetNo() + 1);
			p->SetPlayer(Player);
			// �����鏇�Ԃ�����
			p->SetThrowNo(throwNo);
			// �����鏇�Ԃ��X�V
			throwNo++;
			if(p->GetType() == P_TYPE_THROW_READY_READY || p->GetType() == P_TYPE_PLAYER){
				p->SetPlayerType(P_TYPE_THROW_READY_READY);
			}
			if(bThrow){
				for(int i = 0;i < m_nCurrentControllNo;++i){
					if(p->GetType() == P_TYPE_THROW_READY){
						p->SetPlayerType(P_TYPE_THROW);
						bThrow = false;
					}
				}
			}
		}

		// �X�V
		p->Update();

		// ��������폜
		if(p->GetPosY() < -1000){
			// ���삷���̏ꍇ���̓z�𑀍�ݒ�ɂ���
			switch(p->GetType())
			{
			case P_TYPE_PLAYER:
				if(m_nCurrentControllNo > 0){
					m_nCurrentControllNo--;
					GetPlayer(m_nCurrentControllNo)->SetPlayerType(P_TYPE_PLAYER);
				}
				else if(GetPlayer(m_nCurrentControllNo + 1)){
					GetPlayer(m_nCurrentControllNo + 1)->SetPlayerType(P_TYPE_PLAYER);
				}
				break;
			case P_TYPE_OTHER:
				break;
			case P_TYPE_THROW_READY_READY:
				break;
			case P_TYPE_THROW_READY:
				break;
			case P_TYPE_THROW:
				break;
			}
			// �폜
			p->Uninit();
			SAFE_RELEASE(p)
			m_listIt = m_list.erase(m_listIt);
			continue;

		}
		
		if( p->GetType() == P_TYPE_FLOWER){
			
		}

		// �ԍ����X�V����
		++currentNo;

		// �����΂ɍŌ�ȁ�
		++m_listIt;
	}

	// �f�o�b�O�p
	if (GetTrgKey(DIK_1)){		// 1
		AddPlayer();
	}
	if (GetTrgKey(DIK_2)){		// 2
		RedusePlayer();
	}
}
//����������������������������������������������������������������������������������������
//	Name        : �`��
//	Description : �����ȍX�V
//	Arguments   : �Ȃ���
//	Returns     : �Ȃ���
//����������������������������������������������������������������������������������������
void CPlayersGroup::Draw()
{
	// �v�f�S���`��
	for(m_listIt = m_list.begin(); m_listIt != m_list.end();)
	{
		// UTSUWA���Ȃ��ƒ�������Ȃ���
		CPlayer* p = *m_listIt;

		// �`��
		p->DrawAlpha();

		// �����΂ɍŌ�ȁ�
		++m_listIt;
	}
}
//����������������������������������������������������������������������������������������
//	Name        : Player���擾
//	Description : Player���擾
//	Arguments   : Player�̔ԍ�
//	Returns     : �Ȃ���
//����������������������������������������������������������������������������������������
CPlayer* CPlayersGroup::GetPlayer(int no)
{
	for(std::list<CPlayer*>::iterator it = m_list.begin(); it != m_list.end();)
	{
		// UTSUWA���Ȃ��ƒ�������Ȃ���
		CPlayer* p = *it;

		// ���ʔԍ����ꏏ��������Ԃ�
		if(p->GetNo() == no){
			return p;
		}

		// �����΂ɍŌ�ȁ�
		++it;
	}

	// �Ȃ�������NULL��
	return NULL;
}
//����������������������������������������������������������������������������������������
//	Name        : Player�ǉ�
//	Description : Player�ǉ�
//	Arguments   : Player�̃|�C���^
//	Returns     : �Ȃ���
//����������������������������������������������������������������������������������������
void CPlayersGroup::AddPlayer(CPlayer* p)
{
	m_list.push_back(p);
}
//����������������������������������������������������������������������������������������
//	Name        : Player�ǉ�
//	Description : �Ō����Player�ǉ�
//	Arguments   : Player�̃|�C���^
//	Returns     : nai!
//����������������������������������������������������������������������������������������
void CPlayersGroup::AddPlayer()
{
	CPlayer* p;		// �ǉ�������
	// ����
	p = CPlayer::Create(m_lpTex);
	// ������
	p->Init();

	// :::: ���X�g�ɒǉ� ::::: //
	m_list.push_back(p);
}
//����������������������������������������������������������������������������������������
//	Name        : Player�폜
//	Description : �Ō����Player�폜
//	Arguments   : Player�̃|�C���^
//	Returns     : �Ȃ��I
//����������������������������������������������������������������������������������������
void CPlayersGroup::RedusePlayer()
{
	// 1�̂������Ȃ������猸�炳�Ȃ�
	if(m_list.size() == 1)
		return;

	// UTSUWA
	CPlayer* p = m_list.back();
	// ��n��
	p->Uninit();
	// �J��
	SAFE_RELEASE(p)

	// :::: ���X�g����폜 ::::: //
	m_list.pop_back();
}

//========================================================================================
//	End of File
//========================================================================================