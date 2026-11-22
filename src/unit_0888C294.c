/* unit_0888C294: 0x0888C294-0x0888C318 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* Linear interpolation of x over [p[2], p[3]] -> [p[4], p[5]], clamped. */

float func_0888C294(void *arg0, float x, float *p) {
    float y0;
    float t;

    if (x <= p[2]) {
        return p[4];
    }
    if (x >= p[3]) {
        return p[5];
    }
    if (p[3] == p[2]) {
        return 0.5f * (p[4] + p[5]);
    }
    y0 = p[4];
    t = (p[5] - y0) * (x - p[2]) / (p[3] - p[2]);
    return t + y0;
}
