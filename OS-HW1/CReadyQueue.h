#pragma once
#include "CLinkedList.h"
class CReadyQueue :
    public CLinkedList
{
private:
    static constexpr int MAX_SIZE = 3;
public:
    CReadyQueue();
    virtual ~CReadyQueue();

public:
    int     GetMaxSize()    const { return MAX_SIZE; }

public:
    virtual bool IsFull()   const { return (mSize == MAX_SIZE); }

    virtual CPCB*   pop()			override;
    virtual void	push(CPCB* PCB)	override;
    virtual void	print()			override;

};

