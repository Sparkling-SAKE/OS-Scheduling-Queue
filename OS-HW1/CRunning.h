#pragma once
#include "CLinkedList.h"
class CRunning :
    public CLinkedList
{
private:
    static constexpr int MAX_SIZE = 1;
public:
    CRunning();
    virtual ~CRunning();
public:
    virtual bool IsFull()   const { return (mSize == MAX_SIZE); }

    virtual CPCB*   pop()			override;
    virtual void	push(CPCB* PCB)	override;
    virtual void	print()			override;

};

