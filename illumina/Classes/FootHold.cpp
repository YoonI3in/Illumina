#include "FootHold.h"

CFootHoldTree::CFootHoldTree()
{
	m_nLevel = 0;
	m_vFirstPos = Vec2(-5000,-5000);
	m_vSecPos = Vec2(5000, 5000);

	m_vCenPos = Vec2((m_vSecPos.x - m_vFirstPos.x) / 2, (m_vSecPos.y - m_vFirstPos.y) / 2);
}

CFootHoldTree::CFootHoldTree(Vec2 fp, Vec2 sp, int lv)
{
	m_vFirstPos = fp;
	m_vSecPos = sp;
	m_nLevel = lv;

	m_vCenPos = Vec2((m_vSecPos.x - m_vFirstPos.x) / 2, (m_vSecPos.y - m_vFirstPos.y) / 2);
}

CFootHoldTree::CFootHoldTree(Vec2 fp, Vec2 sp)
{
	m_nLevel = 0;

	m_vFirstPos = fp;
	m_vSecPos = sp;

	m_vCenPos = Vec2((m_vSecPos.x - m_vFirstPos.x) / 2, (m_vSecPos.y - m_vFirstPos.y) / 2);
}

void CFootHoldTree::InsertTree(CFootHold fh)
{
	if (m_nLevel == MAX_LEVEL || (fh.getFirstPosX() >= m_vFirstPos.x && fh.getSecPosX() <= m_vSecPos.x
		&& fh.getFirstPosY() >= m_vFirstPos.y && fh.getSecPosY() <= m_vSecPos.y)) {
		footholds.push_back(fh);
	}
	else {
		if (m_fhNw == nullptr) {
			m_fhNw = new CFootHoldTree(m_vFirstPos, m_vCenPos, m_nLevel + 1);
			m_fhNe = new CFootHoldTree(Vec2(m_vCenPos.x, m_vFirstPos.y), Vec2(m_vSecPos.x, m_vCenPos.y), m_nLevel + 1);
			m_fhSw = new CFootHoldTree(Vec2(m_vFirstPos.x, m_vCenPos.y), Vec2(m_vCenPos.x, m_vSecPos.y), m_nLevel + 1);
			m_fhSe = new CFootHoldTree(m_vCenPos, m_vSecPos, m_nLevel + 1);
		}

		if (fh.getSecPosX() <= m_vCenPos.x && fh.getSecPosY() <= m_vCenPos.y) {
			m_fhNw->InsertTree(fh);
		}
		else if (fh.getFirstPosX() > m_vCenPos.x && fh.getSecPosY() <= m_vCenPos.y) {
			m_fhNe->InsertTree(fh);
		}
		else if (fh.getSecPosX() <= m_vCenPos.x && fh.getFirstPosY() > m_vCenPos.y) {
			m_fhSw->InsertTree(fh);
		}
		else {
			m_fhSe->InsertTree(fh);
		}
	}
}

std::vector<CFootHold> CFootHoldTree::getAllRelevants(std::vector<CFootHold> fhlist)
{
	fhlist.insert(fhlist.end(), footholds.begin(), footholds.end());

	if (m_fhNw != nullptr) {
		m_fhNw->getAllRelevants(fhlist);
		m_fhNe->getAllRelevants(fhlist);
		m_fhSw->getAllRelevants(fhlist);
		m_fhSe->getAllRelevants(fhlist);
	}
	return fhlist;
}

std::vector<CFootHold> CFootHoldTree::getAllRelevants()
{
	return getAllRelevants(std::vector<CFootHold>());
}

void CFootHoldTree::getRelevants(Vec2 pos, std::vector<CFootHold>& fhlist)
{
	fhlist.insert(fhlist.end(), footholds.begin(), footholds.end());

	if (m_fhNw != nullptr) {
		if (pos.x <= m_vCenPos.x && pos.y <= m_vCenPos.y) {
			m_fhNw->getRelevants(pos, fhlist);
		}
		else if (pos.x > m_vCenPos.x && pos.y <= m_vCenPos.y) {
			m_fhNe->getRelevants(pos, fhlist);
		}
		else if (pos.x <= m_vCenPos.x && pos.y <= m_vCenPos.y) {
			m_fhSw->getRelevants(pos, fhlist);
		}
		else {
			m_fhSe->getRelevants(pos, fhlist);
		}
	}
}

std::vector<CFootHold> CFootHoldTree::getRelevants(Vec2 pos)
{
	auto tempList = std::vector<CFootHold>();
	getRelevants(pos, tempList);
	return tempList;
}

bool CFootHoldTree::FindBelow(Vec2 pos, CFootHold &outfh)
{
	std::vector<CFootHold> relevants = getRelevants(pos);
	// find fhs with matching x coordinates
	std::vector<CFootHold> xMatches;
	for (CFootHold &fh : relevants) {
		if (fh.getFirstPosX() <= pos.x && fh.getSecPosX() >= pos.x) {
			xMatches.push_back(fh);
		}
	}
	//Collections.sort(xMatches);


	struct {
		bool operator()(CFootHold a, CFootHold b)
		{
			return a.getFirstPosY() >= b.getFirstPosY();
		}
	} customLess;


	std::sort(xMatches.begin(), xMatches.end(), customLess);

	for (CFootHold &fh : xMatches) {
		if (!fh.IsWall()) {
			if (fh.getFirstPosY() <= pos.y) {
				outfh = fh;
				return true;
			}
		}
	}
	return false;
}

std::vector<CFootHold> CFootHoldTree::getWallRelevants(Vec2 pos1, Vec2 pos2)
{
	std::vector<CFootHold> relevants;

	for (CFootHold &fh : footholds)
	{
		bool isWall = fh.IsWall();

		if (isWall == false)
		{
			continue;
		}

		float firstPosY = fh.getFirstPosY();
		float secondPosY = fh.getSecPosY();
	
		if ((firstPosY <= pos1.y && secondPosY > pos1.y)
			|| (firstPosY <= pos2.y && secondPosY >= pos2.y)
			)
		{
			relevants.push_back(fh);
		}

	}

	return relevants;
}
bool CFootHoldTree::FindWallR(Vec2 pos1, Vec2 pos2, CFootHold &outfh, bool isRightDir /*= true*/)
{
	std::vector<CFootHold> relevants = getWallRelevants(pos1, pos2);

	CFootHold ret;

	struct {
		bool operator()(CFootHold a, CFootHold b)
		{
			return a.getFirstPosX() <= b.getFirstPosX();
		}
	} customLessRight;

	struct {
		bool operator()(CFootHold a, CFootHold b)
		{
			return a.getFirstPosX() >= b.getFirstPosX();
		}
	} customLessLeft;


	if (isRightDir)
	{
		std::sort(relevants.begin(), relevants.end(), customLessRight);
		for (CFootHold &fh : relevants) {
			if (fh.getFirstPosX() >= pos1.x) {
				outfh = fh;
				return true;
			}
		}
	}
	else
	{

		std::sort(relevants.begin(), relevants.end(), customLessLeft);
		for (CFootHold &fh : relevants) {
			if (fh.getFirstPosX() <= pos1.x) {
				outfh = fh;
				return true;
			}
		}
	}

	/*for (CFootHold &fh : footholds)
	{
		bool isWall = fh.IsWall();
		float firstPosX = fh.getFirstPosX();
		float firstPosY = fh.getFirstPosY();
		float secondPosY = fh.getSecPosY();
			if (
				isWall
				&& firstPosX >= pos1.x
				&& firstPosX <= pos2.x
				&& firstPosY >= pos1.y
				&& secondPosY <= pos2.y
				)
			{
				outfh = fh;
				return true;
			}


		if (m_fhNw != nullptr) {
			if (pos1.x <= m_vCenPos.x && pos1.y <= m_vCenPos.y) {
				if (m_fhNw->FindWallR(pos1, pos2, outfh)) {
					return true;
				}
			}
			if ((pos1.x > m_vCenPos.x || pos2.x > m_vCenPos.x) && pos1.y <= m_vCenPos.y) {
				if (m_fhNe->FindWallR(pos1, pos2, outfh)) {
					return true;
				}
			}
			if (pos1.x <= m_vCenPos.x && pos1.y > m_vCenPos.y) {
				if (m_fhSw->FindWallR(pos1, pos2, outfh)) {
					return true;
				}
			}
			if ((pos1.x > m_vCenPos.x || pos2.x > m_vCenPos.x) && pos1.y > m_vCenPos.y) {
				if (m_fhSe->FindWallR(pos1, pos2, outfh)) {
					return true;
				}
			}
		}

	}
*/
	return nullptr;
}

bool CFootHoldTree::FindWall(Vec2 pos1, Vec2 pos2, CFootHold &outfh, bool isRightDir)
{
	/*if (pos1.y != pos2.y) {
		return false;
	}
	if ((pos1.x + 5.0f) >= pos2.x && (pos1.x - 5.0f) <= pos2.x) {
		pos2.x = pos1.x;
	}
	else {
		return false;
	}*/


	auto test = FindWallR(pos1, pos2, outfh, isRightDir);
	return test;
}
