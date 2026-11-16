/* unit_088A7E44: 0x088A7E44-0x088A7F6C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A7DC0 and unit_088A7F6C.
 * Optimized for speed (`-opt speed`): the double constant is loaded as two
 * immediates instead of from the data (notes/COMPILER.md).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u64 sceKernelGetSystemTimeWide(void);
extern s32 sceKernelSysClock2USecWide(u64, u32 *, u32 *);

static inline double scale(double k, float v) {
    return k * v;
}

void func_088A7E44(float *acc, u64 *last) {
    u32 sec;
    u32 usec;
    u64 now;
    u64 diff;

    if (*last == 0) {
        *last = sceKernelGetSystemTimeWide();
        *acc = 0.0f;
        return;
    }
    now = sceKernelGetSystemTimeWide();
    diff = now - *last;
    if (diff != 0) {
        sceKernelSysClock2USecWide(diff, &sec, &usec);
        *acc += (float) ((float) (s32) sec + scale(0.000001, (float) (s32) usec));
        *last = now;
    }
}
