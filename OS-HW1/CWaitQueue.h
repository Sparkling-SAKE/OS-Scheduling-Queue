#pragma once
#include "CLinkedList.h"
class CWaitQueue :
    public CLinkedList
{
public:
    CWaitQueue();
    virtual ~CWaitQueue();
public:
    virtual void Finish();

public:
    virtual CPCB*   pop()			override;
    virtual void	push(CPCB* PCB)	override;
    virtual void	print()			override;
    virtual void    pushFront(CPCB* PCB);
};

