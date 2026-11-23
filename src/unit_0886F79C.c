/* unit_0886F79C: 0x0886F79C-0x0886F7FC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8 pad0[0x5AC];
    u8 unk5AC;
    u8 pad5AD[3];
    s32 unk5B0[1];
} Obj0;

s32 func_0886F79C(Obj0 *arg0, char *arg1, s32 arg2) {
    s32 ret;

    arg0->unk5B0[*(u16 *)(arg1 + 0x1E6)] += arg2;
    ret = 0;
    if (arg0->unk5B0[*(u16 *)(arg1 + 0x1E6)] > 300000) {
        arg0->unk5B0[*(u16 *)(arg1 + 0x1E6)] = 300000;
        ret = 1;
    }
    arg0->unk5AC = *(u16 *)(arg1 + 0x1E6) + 1;
    return ret;
}
