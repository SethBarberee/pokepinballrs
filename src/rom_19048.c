#include "global.h"
#include "functions.h"
#include "main.h"

extern StateFunc gIdlePinballGameStateFuncs[11];

void IdlePinballGameMain(void)
{
    gIdlePinballGameStateFuncs[gMain.subState]();
}

