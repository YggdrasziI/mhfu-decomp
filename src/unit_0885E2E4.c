/* unit_0885E2E4: 0x0885E2E4-0x0885E348 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef struct { char b[12]; } E12;

extern char *D_089CC438;
extern u8 func_0885E244(s32, s16);

s32 func_0885E2E4(s32 arg0, s16 arg1) {
    char *p = D_089CC438 + 0x4A0;
    if (func_0885E244(arg0, arg1) == 0) {
        return 0;
    }
    return *(u16 *)((char *)(arg1 * 12) + (s32)p + 0xAC) & 0xF;
}
