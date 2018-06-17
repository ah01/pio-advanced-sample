#include "tests.h"

#include "core.h"

test(core_counter_reset_value)
{
    core_reset();
    
    int v = core_get_counter();
    assertEqual(v, 0);
}

test(core_counter_increment_value)
{
    core_reset();
    auto r = core_increment();
    assertTrue(r);

    int v = core_get_counter();
    assertEqual(v, 0);
}

test(core_counter_max_value)
{
    core_reset();

    for(int i = 0; i < CORE_MAX_VALUE; i++) 
    {
        auto v = core_increment();
        assertTrue(v);
    }

    auto b = core_increment();
    assertFalse(b);
    
    int v = core_get_counter();
    assertEqual(v, CORE_MAX_VALUE);
}

void setup()
{
}

void loop()
{
    Test::run();
}
