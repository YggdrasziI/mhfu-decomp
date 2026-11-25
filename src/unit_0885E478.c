/* unit_0885E478: 0x0885E478-0x0885E528 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885E478: when func_0885E244(arg0, arg1) holds, sets bit 5 and clears
 * bits 4 and 7 of the u16 at D_089CC438 + 0x4A0 + 0xAC + arg1 * 12 if arg2 is
 * 0, else clears bit 5.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 f;
    char pad[10];
} E12;

extern char *D_089CC438;

extern s32 func_0885E244(s32 arg0, s16 arg1);

void func_0885E478(s32 arg0, s16 arg1, s32 arg2) {
    E12 *t = (E12 *)(D_089CC438 + 0x4A0);

    if ((u8)func_0885E244(arg0, arg1)) {
        if (arg2 == 0) {
            ((E12 *)((char *)t + 0xAC))[arg1].f |= 0x20;
            ((E12 *)((char *)t + 0xAC))[arg1].f &= ~0x10;
            ((E12 *)((char *)t + 0xAC))[arg1].f &= ~0x80;
        } else {
            ((E12 *)((char *)t + 0xAC))[arg1].f &= ~0x20;
        }
    }
}
