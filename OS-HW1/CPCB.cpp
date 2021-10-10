#include "CPCB.h"

int CPCB::mCount = -1;

CPCB::CPCB() :
	mState(PCB_STATE::PS_JOB),
	mpNext(nullptr),
	mpJobQueueNext(nullptr)
{
	mCount++;
	mPCDName = "PCB" + std::to_string(mCount);
	mPID = "PID" + std::to_string(mCount);
}

CPCB::~CPCB()
{
}
