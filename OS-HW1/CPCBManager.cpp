#include "CPCBManager.h"
#include <iostream>

using namespace std;

CPCBManager::CPCBManager()
{
	mpJobQueue = new CJobQueue;
	mpReadyQueue = new CReadyQueue;
	mpRunning = new CRunning;
	mpWaitQueue = new CWaitQueue;
}

CPCBManager::~CPCBManager()
{
	if (mpJobQueue)
		delete mpJobQueue;
	if (mpReadyQueue)
		delete mpReadyQueue;
	if (mpRunning)
		delete mpRunning;
	if (mpWaitQueue)
		delete mpWaitQueue;
}

void CPCBManager::CreatePCB()
{
	CPCB* pNewPCB = new CPCB;
	mpJobQueue->push(pNewPCB);
}

void CPCBManager::IO_Event()
{
	CPCB* pTemp = mpRunning->pop();
	if (!pTemp)
	{
		print();
		return;
	}

	mpWaitQueue->push(pTemp);
	cout << "#" << pTemp->getPCBName() << " - " << pTemp->getPID() << " HDD I/O Event" << endl;
	print();
	Update();
}

void CPCBManager::IO_Finish()
{
	mpWaitQueue->Finish();
	CPCB* pTemp = mpWaitQueue->pop();
	if (!pTemp)
	{
		print();
		return;
	}

	if (mpReadyQueue->IsFull())
		mpWaitQueue->pushFront(pTemp);
	else
		mpReadyQueue->push(pTemp);

	cout << "#" << pTemp->getPID() << " HDD I/O Finished" << endl;
	print();
	Update();
}

void CPCBManager::Terminate()
{
	CPCB* pTemp = mpRunning->pop();
	if (!pTemp)
	{
		print();
		return;
	}

	cout << "#" << pTemp->getPID() << " Process Terminated" << endl;
	mpJobQueue->Terminate(pTemp);
	//delete pTemp;
	print();
	Update();
}

void CPCBManager::Running()
{
	Update();
	CPCB* pTemp = mpRunning->getHead();
	if (!pTemp)
	{
		print();
		return;
	}

	cout << "#" << pTemp->getPCBName() << " - " << pTemp->getPID() << " Process Running" << endl;
	print();
}

void CPCBManager::Update()
{
	for (int i = 0; i < mpReadyQueue->GetMaxSize(); ++i)
		ReadyQueueUpdate();
	RunningUpdate();
	ReadyQueueUpdate();
}

void CPCBManager::ReadyQueueUpdate()
{
	if (!mpReadyQueue->IsFull())
	{
		if (!mpWaitQueue->IsEmpty() && mpWaitQueue->getHead()->getState() != PCB_STATE::PS_WAITING)
			mpReadyQueue->push(mpWaitQueue->pop());

		else if (!mpJobQueue->IsEmpty())
			mpReadyQueue->push(mpJobQueue->pop());
	}
}

void CPCBManager::RunningUpdate()
{
	if (!mpRunning->IsFull())
		if (!mpReadyQueue->IsEmpty())
			mpRunning->push(mpReadyQueue->pop());
}

void CPCBManager::print()
{
	mpRunning->print();
	mpReadyQueue->print();
	mpWaitQueue->print();
	mpJobQueue->print();
}

int CPCBManager::MainMenu()
{
	int menu;
	cout << "==================================" << endl;
	cout << "1. HDD I/O Event" << endl;
	cout << "2. HDD I/O finished" << endl;
	cout << "3. Process Terminated" << endl;
	cout << "4. Process Running" << endl;
	cout << "5. exit" << endl;
	cout << "==> ";	cin >> menu;
	cout << "==================================" << endl;
	return menu;
}

void CPCBManager::run()
{
	int cnt;
	cout << "사용할 PCB의 수를 입력하세요 : ";	cin >> cnt;
	if (cnt == 0)
		return;
	for (int i = 0; i < cnt; ++i)
		CreatePCB();

	Running();

	int menu;
	bool flag = true;
	while (!mpJobQueue->IsJobQueueEmpty() && flag)
	{
		menu = MainMenu();
		switch (MAIN_MENU(menu))
		{
		case MAIN_MENU::MM_IO_EVENT:
			IO_Event();
			break;
		case MAIN_MENU::MM_IO_FINISH:
			IO_Finish();
			break;
		case MAIN_MENU::MM_TERMINATE:
			Terminate();
			break;
		case MAIN_MENU::MM_RUN:
			Running();
			break;
		case MAIN_MENU::MM_EXIT:
			flag = false;
			break;
		default:
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
	}

	cout << "==================================" << endl;
	cout << "모든 프로세스가 종료되었습니다." << endl;
}
