/* unit_088854D0: 0x088854D0-0x08885530 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;

extern s32 D_08A62D84;

extern void func_088802C4(s32, s32, s32);

void func_088854D0(s32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    u32 i;

    for (i = arg1; i <= arg2; arg1 = i) {
        func_088802C4(D_08A62D84, arg1, arg3);
        i++;
    }
}
