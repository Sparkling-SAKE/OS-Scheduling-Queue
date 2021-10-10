#include "CReadyQueue.h"
#include <iostream>

CReadyQueue::CReadyQueue()	:
	CLinkedList()
{
}

CReadyQueue::~CReadyQueue()
{
}

CPCB* CReadyQueue::pop()
{
	if (mSize == 0)
		return nullptr;

	CPCB* pTemp = mpHead;
	mpHead = mpHead->getNext();
	mSize--;
	return pTemp;
}

void CReadyQueue::push(CPCB* PCB)
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
	PCB->setState(PCB_STATE::PS_READY);
}

void CReadyQueue::print()
{
	std::cout << "Ready: ";
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
