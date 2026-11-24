/* unit_08855278: 0x08855278-0x088552E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08855278: tests bit arg1 of the 64-bit mask at arg0 + 0x678A0. */

typedef int s32;
typedef unsigned long long u64;

s32 func_08855278(char *arg0, s32 arg1) {
    return (*(u64 *)(arg0 + 0x678A0) & ((u64)1 << arg1)) != 0;
}
