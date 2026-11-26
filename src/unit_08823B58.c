/* unit_08823B58: 0x08823B58-0x08823C84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char *D_089CC438;
extern int func_0885A934(char *, u8, s16, s16, u8);
extern int func_0885A95C(char *, s32, u8, s32);

void func_08823B58(char *arg0) {
    s32 i;
    char *p;
    char *e;
    u8 kind;

    if ((s32)((*(s32 *)(D_089CC438 + 0x70000 - 0x50EC) & 1) != 0) != 0 ||
        *(u8 *)(D_089CC438 + 0x422) != 1) {
        i = 0;
        p = arg0;
        do {
            if ((((*(u8 *)(p + 0xE28) != 0)) ^ 1) == 0) {
                return;
            }
            i++;
            p += 0x24;
        } while (i < 0x14);
        if (*(s8 *)(arg0 + 0x10F8) > 0) {
            e = arg0 + *(s8 *)(arg0 + 0x10F9) * 0x24 + 0xE28;
            kind = *(u8 *)(e + 0x1A);
            if (kind == 0xFF) {
                func_0885A95C(e, *(s32 *)(e + 0x20), *(u8 *)(e + 0x1B), 0);
            } else if (kind == 0xFE) {
                func_0885A95C(e, *(s32 *)(e + 0x20), *(u8 *)(e + 0x1B), 1);
            } else {
                func_0885A934(e, kind, *(s16 *)(e + 0x1C), *(s16 *)(e + 0x1E), *(u8 *)(e + 0x1B));
            }
            if (++*(s8 *)(arg0 + 0x10F9) >= 0x14) {
                *(s8 *)(arg0 + 0x10F9) = 0;
            }
            *(s8 *)(arg0 + 0x10FA) = 0x3C;
            *(s8 *)(arg0 + 0x10F8) -= 1;
        }
    }
}
