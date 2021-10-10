#pragma once
#include "CLinkedList.h"
#include <vector>
class CJobQueue :
    public CLinkedList
{

public:
	CJobQueue();
	virtual ~CJobQueue();

private:
	CPCB* mpStartNode;
	int	  mJobQueueSize;
	
public:
	virtual CPCB*	pop()			override;
	virtual void	push(CPCB* PCB)	override;
	virtual void	print()			override;

public:
	void	Terminate(CPCB* PCB);
	bool	IsJobQueueEmpty() { return (mJobQueueSize == 0); }
};

