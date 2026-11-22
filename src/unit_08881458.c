/* unit_08881458: 0x08881458-0x088816AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern s32 D_08A62D94;
extern int func_08881438(s32, s32);
extern u16 func_0888670C(s32, s32);
extern void func_0888664C(s32, s32);
extern s32 func_088816AC(char *, s32, s32);
extern void func_088817E8(char *, s32, s32);
extern void func_0888291C(char *, s32);

s32 func_08881458(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 ids[3];
    u16 *out;
    s32 i;
    s32 j;

    out = (u16 *)(arg0 + 0x8B54);
    if ((u32)(arg2 - 0x19BE) < 2) {
        func_088817E8(arg0, 0x14, 0);
        arg4 = 0xFFFF;
    }
    ids[0] = arg2;
    ids[1] = arg3;
    ids[2] = arg4;
    *(s32 *)(arg0 + 0x562434) = 0;
    for (j = 0; j < 3; j++) {
        if (ids[*(s32 *)(arg0 + 0x562434)] != 0xFFFF) {
            *(s32 *)(arg0 + 0x562434) += 1;
        }
    }
    if (*(s32 *)(arg0 + 0x562434) == 0) {
        *(s32 *)(arg0 + 0x562434) = 3;
    }
    for (i = 0; i < *(s32 *)(arg0 + 0x562434); i++) {
        func_08881438((s32)arg0, i);
        if (ids[i] != func_0888670C(D_08A62D94, arg1 + i)) {
            func_0888664C(D_08A62D94, arg1 + i);
        }
        if (*(s32 *)(arg0 + 0x8B94) == 0) {
            out[i + 3] = arg1 + i;
            out[i] = ids[i];
            if (ids[i] != 0xFFFF) {
                func_088817E8(arg0, arg1 + i, func_088816AC(arg0, arg1 + i, ids[i]));
            }
        }
    }
    *(u8 *)((char *)out + 0xC) = arg5;
    if (*(s32 *)(arg0 + 0x8B94) == 0) {
        *(s32 *)(arg0 + 0x8B94) = 6;
        if (arg1 == 0x12) {
            func_0888291C(arg0, 2);
        } else if (arg1 == 0x13) {
            func_0888291C(arg0, 3);
        } else if (arg1 == 0x14) {
            func_0888291C(arg0, 4);
        }
        return 1;
    }
    return 0;
}
