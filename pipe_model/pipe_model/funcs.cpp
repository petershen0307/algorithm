#include "stdafx.h"
#include "funcs.h"
#include "common.h"

#define TEST_PATH_NUM 10

DWORD WINAPI scanner(LPVOID lpParam)
{
    _tprintf(L"this is in %S\n", __FUNCTION__);
    DWORD const sleepMilliseconds = 500;
    // get path
    for (int i = 0; i < TEST_PATH_NUM; ++i)
    {
        TSTRING strPath(L"c:\\");
        TCHAR temp[4] = {0};
        _stprintf_s(temp, 4, L"%d", i);
        strPath.append(temp);
        Sleep(sleepMilliseconds);
        // put path into queue
        bool bWaitMutex = false;
        do
        {
            DWORD dwWaitResult = WaitForSingleObject(
                pathQueueMutex,    // handle to mutex
                INFINITE);  // no time-out interval
            if (WAIT_OBJECT_0 == dwWaitResult)
            {
                PPathQueue queue = (PPathQueue)lpParam;
                if (MAX_PATH_QUEUE != queue->size())
                {
                    queue->push(strPath);
                    bWaitMutex = false;
                }
                else
                {
                    bWaitMutex = true;
                }
                if (!ReleaseMutex(pathQueueMutex))
                {
                    // log error
                    _tprintf(L"[%S]-[%d] release mutex failed\n", __FUNCTION__, __LINE__);
                }
            }
            else
            {
                // log error
                _tprintf(L"[%S]-[%d] wait mutex with error (%lu)\n", __FUNCTION__, __LINE__, dwWaitResult);
                return 1;
            }
        } while (bWaitMutex);
    }
    return 0;
}

DWORD WINAPI calculator(LPVOID lpParam)
{
    return 0;
}

DWORD WINAPI outputer(LPVOID lpParam)
{
    return 0;
}