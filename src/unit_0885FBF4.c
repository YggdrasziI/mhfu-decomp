/* unit_0885FBF4: 0x0885FBF4-0x0885FC9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

void func_0885FBF4(char *arg0, s32 arg1) {
    if (*(u16 *)(arg0 + 0x114) == arg1 || arg1 == -1) {
        float *src = (float *)(arg0 + 0x150);
        float *dst = (float *)(arg0 + 0x1D0);
        asm {
            lv.q C000, 0x0(src)
            lv.q C010, 0x10(src)
            lv.q C020, 0x20(src)
            lv.q C030, 0x30(src)
            sv.q C000, 0x0(dst)
            sv.q C010, 0x10(dst)
            sv.q C020, 0x20(dst)
            sv.q C030, 0x30(dst)
        }
        *(float *)(arg0 + 0x210) = *(float *)(arg0 + 0x190);
        *(float *)(arg0 + 0x214) = *(float *)(arg0 + 0x194);
        *(float *)(arg0 + 0x218) = *(float *)(arg0 + 0x198);
        if (*(char **)(arg0 + 0x14C) != 0) {
            func_0885FBF4(*(char **)(arg0 + 0x14C), arg1);
        }
    }
    if (*(char **)(arg0 + 0x148) != 0) {
        func_0885FBF4(*(char **)(arg0 + 0x148), arg1);
    }
}
