#include "CLinkedList.h"

CLinkedList::CLinkedList()	:
	mSize(0),
	mpHead(nullptr),
	mpTail(nullptr)
{
}

CLinkedList::~CLinkedList()
{
	CPCB* pTemp;
	while (mpHead != nullptr)
	{
		pTemp = mpHead;
		mpHead = mpHead->getNext();
		if (pTemp)
			delete pTemp;
	}
}