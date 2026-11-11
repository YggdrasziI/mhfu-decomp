/* unit_08885E00: 0x08885E00-0x08885E3C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

void func_08885E00(char *arg0) {
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    *(u16 *)(arg0 + 8) = 0xFFFF;
    *(u16 *)(arg0 + 0xC) = 0xFFFF;
    *(u16 *)(arg0 + 0xA) = 0xFFFF;
    *(u8 *)(arg0 + 0x18) = 0;
    *(u8 *)(arg0 + 0x19) = 0;
    *(u8 *)(arg0 + 0x1A) = 0;
    *(u16 *)(arg0 + 0x1C) = 0xFFFF;
    *(u16 *)(arg0 + 0x1E) = 0xFFFF;
    *(u16 *)(arg0 + 0x20) = 0xFFFF;
    *(s32 *)(arg0 + 0x24) = 0;
    *(u16 *)(arg0 + 0x2A) = 0;
}
