#include "CWaitQueue.h"
#include <iostream>

CWaitQueue::CWaitQueue() :
	CLinkedList()
{
}

CWaitQueue::~CWaitQueue()
{
}

void CWaitQueue::Finish()
{
	CPCB* pTemp = mpHead;
	while ((pTemp != nullptr) && (pTemp->getState() != PCB_STATE::PS_WAITING))
		pTemp = pTemp->getNext();
	if (pTemp)
		pTemp->setState(PCB_STATE::PS_WAITING_END);
}

CPCB* CWaitQueue::pop()
{
	if (mSize == 0)
		return nullptr;

	if (mpHead->getState() == PCB_STATE::PS_WAITING)
		return nullptr;
	CPCB* pTemp = mpHead;
	mpHead = mpHead->getNext();
	mSize--;
	return pTemp;
}

void CWaitQueue::push(CPCB* PCB)
{
	if (mpHead == nullptr)
		mpHead = mpTail = PCB;
	else
	{
		mpTail->setNext(PCB);
		mpTail = PCB;
	}
	mpTail->setNext(nullptr);
	mSize++;
	PCB->setState(PCB_STATE::PS_WAITING);
}

void CWaitQueue::print()
{
	std::cout << "Wait: ";
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

void CWaitQueue::pushFront(CPCB* PCB)
{
	if (mpHead == nullptr)
	{
		mpHead = mpTail = PCB;
		mpTail->setNext(nullptr);
	}
	else
	{
		PCB->setNext(mpHead);
		mpHead = PCB;
	}
	mSize++;
	PCB->setState(PCB_STATE::PS_WAITING_END);
}
