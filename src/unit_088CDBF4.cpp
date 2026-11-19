/* unit_088CDBF4: 0x088CDBF4-0x088CDCB0 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions of the former text_088CD964 asm piece
 * (0x088CD964-0x088CDCB0), split around the NonMatching func_088CDA74.
 *
 * Scans four 0x20-byte slots; reads the 16-bit value of the current one.
 *
 * C++: the flag tests are bool conversions.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" {

extern char *D_089CBBE4;
extern void func_08813560(char *, s32, char *, s32);
extern s32 func_088CD2D4(char *, u8 *);

void func_088CDBF4(char *arg0) {
    u8 *p;
    s32 i;

    p = (u8 *)(arg0 + 4);
    i = 0;
    do {
        if (*p != 0 && func_088CD2D4(arg0, p) > 0) {
            *(s32 *)(arg0 + 0x88) = 1;
            *(u8 *)(arg0 + 1) = i;
            func_08813560(D_089CBBE4, 0x6A, 0, 0);
            return;
        }
        i++;
        p += 0x20;
    } while (i < 4);
    *(s32 *)(arg0 + 0x88) = 0;
}

s32 func_088CDC8C(char *arg0) {
    u16 v;

    v = *(u16 *)(*(char **)(arg0 + *(u8 *)(arg0 + 1) * 0x20 + 0x20) + 8);
    return v != 0 ? v : 0xFFFF;
}

}
