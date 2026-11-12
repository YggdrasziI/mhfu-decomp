/* unit_08866FB0: 0x08866FB0-0x08867008 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char D_089B653C;
extern s32 func_088673CC(s32, s32, s32);

s32 func_08866FB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return (func_088673CC(arg0, ((arg3 & 0xFF) + ((u16 *)&D_089B653C)[(arg2 & 0xFF)]) & 0xFFFF, (((arg1 & 0xFF) * 8) + 7) & 0xFF) & 0xFF) == 1;
}
