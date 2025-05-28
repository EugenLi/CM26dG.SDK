//Copyright (C) KONICA MINOLTA, INC.  All rights reserved. 2018

#pragma once

#ifdef KMAPI
#undef KMAPI
#endif

#define KMAPI __declspec(dllimport) __stdcall

#include "CMMISDK_Api.h"
