// pipe_model.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "funcs.h"
#include "common.h"

#define MAX_THREAD 1

HANDLE pathQueueMutex;

void creaetScanner(HANDLE *, DWORD *, PPathQueue);

int _tmain()
{
    _tprintf(L"creating thread\n");
    HANDLE threadHandle[MAX_THREAD];
    DWORD threadId[MAX_THREAD];

    // scanner
    pathQueueMutex = CreateMutex(
        NULL,              // default security attributes
        FALSE,             // initially not owned
        NULL);             // unnamed mutex
    PPathQueue pathQueue = new PathQueue();
    creaetScanner(&threadHandle[0], &threadId[0], pathQueue);
    _tprintf(L"thread id %u\n", threadId[0]);

    // wait children threads
    WaitForMultipleObjects(MAX_THREAD, threadHandle, TRUE, INFINITE);

    // free thread handle
    for (int i = 0; i < MAX_THREAD; ++i)
    {
        CloseHandle(threadHandle[i]);
    }
    _tprintf(L"print path queue\n");
    while (!pathQueue->empty())
    {
        PathQueue::value_type path = pathQueue->front();
        pathQueue->pop();
        _tprintf(L"%s\n", path.c_str());
    }
    return 0;
}

void creaetScanner(HANDLE *threadHandle, DWORD *threadId, PPathQueue pathQueue)
{
    *threadHandle = CreateThread(
        NULL,                   // default security attributes
        0,                      // use default stack size
        scanner,                // thread function name
        pathQueue,              // argument to thread function
        0,                      // use default creation flags
        threadId);              // returns the thread identifier
}