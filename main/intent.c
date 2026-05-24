#include "intent.h"
#include <math.h>

static float baseline;
static float energy;
static const float THRESHOLD = 50.0f;
static bool was_above_threshold;

void intent_init(void)
{
    baseline = 0.0f;
    energy = 0.0f;
    was_above_threshold = false;
}

float intent_get_energy(void)
{
    return energy;
}

float intent_get_baseline(void)
{
    return baseline;
}

bool intent_update(int sample)
{
    bool trigger = false;

    float alpha = 0.01f;
    float s = (float)sample;
    baseline = baseline + alpha * (s - baseline);
    float deviation = fabsf(s-baseline);
    float beta = 0.1f;
    energy = energy + beta * (deviation - energy);
    bool current = (energy > THRESHOLD);
    if (current && !was_above_threshold) {
        trigger = true;
    }
    was_above_threshold = current;
    return (trigger);

}