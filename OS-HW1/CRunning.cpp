#include "CRunning.h"
#include <iostream>

CRunning::CRunning()	:
	CLinkedList()
{
}

CRunning::~CRunning()
{
}

CPCB* CRunning::pop()
{
	if (mSize == 0)
		return nullptr;

	CPCB* pTemp = mpHead;
	mpHead = mpTail = nullptr;
	mSize--;
	return pTemp;
}

void CRunning::push(CPCB* PCB)
{
	if (mpHead == nullptr)
	{
		mpHead = mpTail = PCB;
		mpTail->setNext(nullptr);
		mSize++;
		PCB->setState(PCB_STATE::PS_RUN);
	}
}

void CRunning::print()
{
	std::cout << "Running: ";
	CPCB* pTemp = mpHead;
	if (!pTemp)
	{
		std::cout << std::endl;
		return;
	}
	while (pTemp != mpTail)
	{
		std::cout << pTemp->getPCBName() << ", ";
		pTemp = pTemp->getNext();
	}
	std::cout << pTemp->getPCBName() << std::endl;
}
