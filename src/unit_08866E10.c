/* unit_08866E10: 0x08866E10-0x08866F6C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08866E10: 0x08866E10-0x08866F6C (ULES01213) */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u16 D_089B6524[][6];
extern u16 D_089B650C[][6];
extern s32 func_088673CC(s32, s32, s32);
extern s32 func_088D6388(s32, s32, s32, s32, s32);

s32 func_08866E10(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                  s32 arg6, s32 arg7) {
    u8 slot = (u8)arg3 + (u8)arg1 * 8;
    s32 id;

    if ((u8)arg7 == 1 || ((u8)arg7 == 0 && D_089B6524[(u8)arg2][(u8)arg3] == 0xFFFF)) {
        id = (u16)(D_089B650C[(u8)arg2][(u8)arg3] + (u16)func_088D6388(arg2, arg3, arg4, arg5, arg6));
    } else {
        id = (u16)(D_089B6524[(u8)arg2][(u8)arg3] + (u16)func_088D6388(arg2, arg3, arg4, arg5, arg6));
    }
    if ((u8)func_088673CC(arg0, id, slot) == 1) {
        return 1;
    }
    return 0;
}
