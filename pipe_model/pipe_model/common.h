#pragma once

#include <Windows.h>
#include <tchar.h>
#include <string>
#include <queue>
#include <utility>

typedef std::basic_string<TCHAR> TSTRING;

#define MAX_PATH_QUEUE 10
typedef std::queue<TSTRING> *PPathQueue, PathQueue;
extern HANDLE pathQueueMutex;

#define MAX_OUTPUT_QUEUE 100
typedef std::queue<std::pair<std::string, TSTRING> > *POutputQueue, OutputQueue;
extern HANDLE outputQueueMutex;
