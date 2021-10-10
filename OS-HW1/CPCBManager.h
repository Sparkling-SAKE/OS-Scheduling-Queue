#pragma once
#include "CReadyQueue.h"
#include "CJobQueue.h"
#include "CWaitQueue.h"
#include "CRunning.h"

class CPCBManager
{
private:
	CJobQueue*		mpJobQueue;
	CReadyQueue*	mpReadyQueue;
	CWaitQueue*		mpWaitQueue;
	CRunning*		mpRunning;

public:
	CPCBManager();
	virtual ~CPCBManager();

private:
	void CreatePCB();
	void print();
	int	 MainMenu();

private:
	void IO_Event();
	void IO_Finish();
	void Terminate();
	void Running();
	void Update();
	void ReadyQueueUpdate();
	void RunningUpdate();

public:
	void run();
};
