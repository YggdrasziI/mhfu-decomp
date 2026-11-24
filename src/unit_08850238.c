/* unit_08850238: 0x08850238-0x0885028C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08850238: scales an unsigned value by a per-index float percentage. */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern float D_0899C760[];

float func_08850238(s32 arg0, u8 arg1, u32 arg2) {
    return (float)arg2 * D_0899C760[arg1] / 100.0f;
}
