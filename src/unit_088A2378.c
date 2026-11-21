/* unit_088A2378: 0x088A2378-0x088A23C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;

typedef struct {
    char unk0[0x6C];
    s32 unk6C;
    u32 unk70;
} T;

void func_088A2378(T *arg0, s32 arg1) {
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 > 0x7F) {
        arg1 = 0x7F;
    }
    arg0->unk6C = arg1;
    arg0->unk70 = (u32)(arg1 << 15) / 127;
}
