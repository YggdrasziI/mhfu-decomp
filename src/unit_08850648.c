/* unit_08850648: 0x08850648-0x088506A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

extern s32 func_088572B0(s32, s32);

void func_08850648(char *arg0, s32 arg1) {
    s32 i;

    i = func_088572B0((s32)arg0, arg1);
    ((u32 *)(arg0 + 0x6ADF0))[i >> 5] &= ~(1 << (i & 0x1F));
}
