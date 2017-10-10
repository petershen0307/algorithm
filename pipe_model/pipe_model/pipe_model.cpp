// pipe_model.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "funcs.h"
#include "common.h"

#define MAX_THREAD 2

HANDLE pathQueueMutex;
HANDLE outputQueueMutex;

void createScanner(HANDLE *, DWORD *, PScanPipeParameter);
void createCalculator(HANDLE *, DWORD *, PScanPipeParameter);

int _tmain()
{
    _tprintf(L"creating thread\n");
    HANDLE threadHandle[MAX_THREAD];
    DWORD threadId[MAX_THREAD];

    // mutex
    pathQueueMutex = CreateMutex(
        NULL,              // default security attributes
        FALSE,             // initially not owned
        NULL);             // unnamed mutex
    outputQueueMutex = CreateMutex(
        NULL,              // default security attributes
        FALSE,             // initially not owned
        NULL);             // unnamed mutex

    // scanner
    PPathQueue pathQueue = new PathQueue();
    POutputQueue outputQueue = new OutputQueue();
    PScanPipeParameter pScanPipeParam = new ScanPipeParameter();
    pScanPipeParam->pPathQueue = pathQueue;
    pScanPipeParam->pOutputQueue = outputQueue;
    pScanPipeParam->bEndScan = false;
    pScanPipeParam->bEndCalc = false;
    createScanner(&threadHandle[0], &threadId[0], pScanPipeParam);
    _tprintf(L"thread id %u\n", threadId[0]);


    createCalculator(&threadHandle[1], &threadId[1], pScanPipeParam);
    _tprintf(L"thread id %u\n", threadId[1]);

    // wait children threads
    WaitForMultipleObjects(MAX_THREAD, threadHandle, TRUE, INFINITE);

    // free thread handle
    for (int i = 0; i < MAX_THREAD; ++i)
    {
        CloseHandle(threadHandle[i]);
    }
    CloseHandle(pathQueueMutex);
    CloseHandle(outputQueueMutex);
    _tprintf(L"finish");
    return 0;
}

void createScanner(HANDLE *threadHandle, DWORD *threadId, PScanPipeParameter param)
{
    *threadHandle = CreateThread(
        NULL,                   // default security attributes
        0,                      // use default stack size
        scanner,                // thread function name
        param,              // argument to thread function
        0,                      // use default creation flags
        threadId);              // returns the thread identifier
}

void createCalculator(HANDLE *threadHandle, DWORD *threadId, PScanPipeParameter param)
{
    *threadHandle = CreateThread(
        NULL,                   // default security attributes
        0,                      // use default stack size
        calculator,                // thread function name
        param,              // argument to thread function
        0,                      // use default creation flags
        threadId);              // returns the thread identifier
}