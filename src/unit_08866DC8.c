/* unit_08866DC8: 0x08866DC8-0x08866E10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08866DC8: looks up a u16 entry of D_09A67EA0 and tests func_088673CC. */
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

extern u16 D_09A67EA0[];
extern s32 func_088673CC(s32, u16, u8);

s32 func_08866DC8(s32 arg0, s32 arg1, s32 arg2)
{
    return (func_088673CC(arg0, D_09A67EA0[(u8)arg2], (u8)arg1 * 8) & 0xFF) == 1;
}
