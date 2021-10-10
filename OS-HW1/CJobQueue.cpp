#include "CJobQueue.h"
#include <iostream>

CJobQueue::CJobQueue() :
	CLinkedList(),
	mJobQueueSize(0)
{
	mpStartNode = new CPCB;
}

CJobQueue::~CJobQueue()
{
	if (mpStartNode)
		delete mpStartNode;
}

CPCB* CJobQueue::pop()
{
	if (mSize == 0)
		return nullptr;

	CPCB* pTemp = mpHead;
	mpHead = mpHead->getJobQueueNext();
	mpStartNode->setNext(mpHead);
	mSize--;
	return pTemp;
}

void CJobQueue::push(CPCB* PCB)
{
	if (mJobQueueSize == 0)
	{
		mpStartNode->setNext(PCB);
		mpStartNode->setJobQueueNext(PCB);
		mpHead = mpTail = PCB;
	}
	else
	{
		mpTail->setJobQueueNext(PCB);
		mpTail->setNext(PCB);
		mpTail = PCB;
	}
	mpTail->setNext(nullptr);
	mpTail->setJobQueueNext(nullptr);
	mSize++;
	mJobQueueSize++;
	PCB->setState(PCB_STATE::PS_JOB);
}

void CJobQueue::print()
{
	std::cout << "Job Queue: ";

	if (mJobQueueSize == 0)
		return;

	CPCB* pTemp = mpStartNode->getJobQueueNext();
	for (int i = 0; i < mJobQueueSize - 1; ++i)
	{
		std::cout << pTemp->getPCBName() << ", ";
		pTemp = pTemp->getJobQueueNext();
	}
	std::cout << pTemp->getPCBName() << std::endl;
	std::cout << "==================================" << std::endl;
}

void CJobQueue::Terminate(CPCB* PCB)
{
	if (mJobQueueSize == 0)
		return;

	CPCB* pTemp = mpStartNode;
	while (pTemp->getJobQueueNext() != PCB)
		pTemp = pTemp->getJobQueueNext();

	pTemp->setJobQueueNext(PCB->getJobQueueNext());

	--mJobQueueSize;
	if (PCB)
		delete PCB;
}
