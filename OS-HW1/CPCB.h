#pragma once
#include <string>
#include "state.h"

class CPCB
{
private:
	static int		mCount;

private:
	std::string		mPCDName;
	std::string		mPID;
	PCB_STATE		mState;
	CPCB*			mpNext;
	CPCB*			mpJobQueueNext;

public:
	CPCB();
	virtual ~CPCB();

public:
	std::string getPCBName()		const { return mPCDName; }
	std::string getPID()			const { return mPID; }
	PCB_STATE	getState()			const { return mState; }
	CPCB*		getNext()			const { return mpNext; }
	CPCB*		getJobQueueNext()	const { return mpJobQueueNext; }

	void		setPCBName(std::string PCDName) { mPCDName = PCDName; }
	void		setPID(std::string PID)			{ mPID = PID; }
	void		setState(PCB_STATE state)		{ mState = state; }
	void		setNext(CPCB* pNext)			{ mpNext = pNext; }
	void		setJobQueueNext(CPCB* pJobNext)	{ mpJobQueueNext = pJobNext; }
};

