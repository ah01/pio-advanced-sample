#include "core.h"

static int _counter = 0;

int core_get_counter()
{
    return _counter;
}

bool core_increment()
{
    if (_counter >= CORE_MAX_VALUE)
    {
        return false;
    }

    _counter++;
    return true;
}

void core_reset()
{
    _counter = 0;
}
