#pragma once
#include <iostream>
#include <cocos2d.h>
#include <vector>

USING_NS_CC;

#define MAX_LEVEL	8

struct CFootHold
{
	Vec2	m_vFistPos;
	Vec2	m_SecPos;
	int		m_nId;

public:
	CFootHold() {}
	CFootHold(Vec2 fp, Vec2 sp, int id) {
		m_vFistPos = fp;
		m_SecPos = sp;
		m_nId = id;
	}

	bool IsWall() {
		if (m_SecPos.x + 5 >= m_vFistPos.x && m_SecPos.x - 5.0f <= m_vFistPos.x) {
			m_SecPos.x = m_vFistPos.x;
		}
		return m_vFistPos.x == m_SecPos.x;
	}

	int		Compareto(CFootHold fh) {

	}

	Vec2 getFirstPos()
	{
		return m_vFistPos;
	}

	Vec2 getSecPos()
	{
		return m_SecPos;
	}	

	float getFirstPosX(){
		return m_vFistPos.x;
	}

	float getFirstPosY() {
		return m_vFistPos.y;
	}

	float getSecPosX() {
		return m_SecPos.x;
	}

	float getSecPosY() {
		return m_SecPos.y;
	}
};

class CFootHoldTree
{
	//4개의 영역
	CFootHoldTree	*m_fhNw = nullptr;
	CFootHoldTree	*m_fhNe = nullptr;
	CFootHoldTree	*m_fhSw = nullptr;
	CFootHoldTree	*m_fhSe = nullptr;

	Vec2	m_vFirstPos;	//첫번째 좌표
	Vec2	m_vSecPos;		//두번째 좌표
	Vec2	m_vCenPos;		//중간 좌표

	int		m_nLevel;		//영역

	int		m_nMaxDropX;	
	int		m_nMinDropX;

	std::vector<CFootHold> footholds;

public:
	CFootHoldTree();
	CFootHoldTree(Vec2 fp, Vec2 sp);

	CFootHoldTree(Vec2 fp, Vec2 sp, int lv );

	//Tree 생성
	void InsertTree(CFootHold fh);
	std::vector<CFootHold> getWallRelevants(Vec2 pos1, Vec2 pos2);
	std::vector<CFootHold> getAllRelevants();

	std::vector<CFootHold> getAllRelevants(std::vector<CFootHold> fhlist);

	CFootHoldTree* getTreeWithContainIndex(int index)
	{
		for (int i = 0; i < footholds.size(); ++i)
		{
			if (index== footholds[i].m_nId)
			{
				return this;
			}
		}

		if (m_fhNw)
		{
			auto p = m_fhNw->getTreeWithContainIndex(index);
			if (p)
			{
				return p;
			}
		}
		if (m_fhNe)
		{
			auto p = m_fhNe->getTreeWithContainIndex(index);
			if (p)
			{
				return p;
			}
		}
		if (m_fhSw)
		{
			auto p = m_fhSw->getTreeWithContainIndex(index);
			if (p)
			{
				return p;
			}
		}
		if (m_fhSe)
		{
			auto p = m_fhSe->getTreeWithContainIndex(index);
			if (p)
			{
				return p;
			}
		}
		return nullptr;
	}
	CFootHoldTree* getTreeWithContainFoothold(CFootHold &hold)
	{
		for (int i = 0; i < footholds.size(); ++i)
		{
			if (hold.m_nId == footholds[i].m_nId)
			{
				return this;
			}
		}
		
		if (m_fhNw)
		{
			auto p = m_fhNw->getTreeWithContainFoothold(hold);
			if (p)
			{
				return p;
			}
		}
		if (m_fhNe)
		{
			auto p = m_fhNe->getTreeWithContainFoothold(hold);
			if (p)
			{
				return p;
			}
		}
		if (m_fhSw)
		{
			auto p = m_fhSw->getTreeWithContainFoothold(hold);
			if (p)
			{
				return p;
			}
		}
		if (m_fhSe)
		{
			auto p = m_fhSe->getTreeWithContainFoothold(hold);
			if (p)
			{
				return p;
			}
		}
		return nullptr;
	}

	bool deleteHold(CFootHold& hold)
	{
		CFootHoldTree* tree = getTreeWithContainFoothold(hold);

		if (tree == nullptr)
		{
			return false;
		}

		auto itr = tree->footholds.begin();
		auto end = tree->footholds.end();

		for ( ; itr != end; ++itr )
		{
			if ((*itr).m_nId == hold.m_nId)
			{
				tree->footholds.erase(itr);
				break;
			}
		}

	}

	bool deleteHoldWithIndex(int index)
	{
		CFootHoldTree* tree = getTreeWithContainIndex(index);

		if (tree == nullptr)
		{
			return false;
		}

		auto itr = tree->footholds.begin();
		auto end = tree->footholds.end();

		for (; itr != end; ++itr)
		{
			if ((*itr).m_nId == index)
			{
				tree->footholds.erase(itr);

				return true;
				break;
			}
		}

		return false;
	}
	std::vector<CFootHold> getRelevants(Vec2 pos);

	void getRelevants(Vec2 pos, std::vector<CFootHold>& fhlist);

	bool FindBelow( Vec2 pos, CFootHold &outfh);

	bool FindWallR(Vec2 pos1, Vec2 pos2, CFootHold &outfh, bool isRightDir = true );

	bool FindWall(Vec2 pos1, Vec2 pos2, CFootHold &outfh, bool isRightDir = true);
};
