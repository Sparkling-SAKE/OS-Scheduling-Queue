#pragma once
#include "CPCB.h"

class CLinkedList
{
protected:
	CPCB*	mpHead;
	CPCB*	mpTail;
	int		mSize;

public:
	CLinkedList();
	virtual ~CLinkedList();

public:
	virtual int		getSize()	const { return mSize; }
	virtual void	setSize(int size) { mSize = size; }
	virtual CPCB*	getHead()	const { return mpHead; }
	virtual void	setHead(CPCB* PCB) { mpHead = PCB; }
	virtual CPCB*	getTail()	const { return mpTail; }
	virtual void	setTail(CPCB* PCB) { mpTail = PCB; }

public:
	virtual bool	IsEmpty()	const { return (mSize == 0); }

public:
	virtual CPCB*	pop() = 0;
	virtual void	push(CPCB* PCB) = 0;
	virtual void	print() = 0;
};

