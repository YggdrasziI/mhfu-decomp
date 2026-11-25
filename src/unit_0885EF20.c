/* unit_0885EF20: 0x0885EF20-0x0885F068 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char D_08978474;
extern char *D_089CC438;
extern s32 func_08857A80(char *, s32);

u8 func_0885EF20(s32 arg0, char *arg1) {
    char *p;
    u8 v;

    if (*(u8 *)(arg1 + 1) >= 5) {
        return 0;
    }
    p = ((char **)&D_08978474)[*(u8 *)(arg1 + 1)];
    p += *(u16 *)(arg1 + 2) * 0x28;
    v = 0;
    if (*(u8 *)(p + 0x14) > 0) {
        v = *(u8 *)(p + 0x14);
    }
    if (v < *(u8 *)(p + 0x15)) v = *(u8 *)(p + 0x15);
    if (v < *(u8 *)(p + 0x16)) v = *(u8 *)(p + 0x16);
    if (v < *(u8 *)(p + 0x17)) v = *(u8 *)(p + 0x17);
    if (v < *(u8 *)(p + 0x18)) v = *(u8 *)(p + 0x18);
    if (v < *(u8 *)(p + 0x19)) v = *(u8 *)(p + 0x19);
    if ((u8)func_08857A80(D_089CC438, 0xE) == 1) {
        if (v < *(u8 *)(p + 0x1A)) v = *(u8 *)(p + 0x1A);
    }
    if (v) v--;
    if (v > 0x3F) {
        v = 0x3F;
    }
    return v;
}
