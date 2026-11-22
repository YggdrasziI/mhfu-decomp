/* unit_0888D004: 0x0888D004-0x0888D0A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CBBE4;
extern char *D_08A62C60;
extern u8 func_0888D600(char *);

void func_0888D004(char *arg0) {
    char *g = D_089CBBE4;
    char *p = arg0 + 0xA0;

    if (*(u8 *)(g + 0xA8D) == 0 && *(u8 *)(g + 0x961) == 0) {
        if (func_0888D600(arg0) == 1) {
            *(u16 *)(p + 0x84) = *(u16 *)(g + 0xA70);
            *(u16 *)(p + 0x86) = *(u16 *)(g + 0xA72);
            return;
        }
        if (*(u8 *)(D_08A62C60 + 0x74) == 0) {
            *(u16 *)(p + 0x84) = *(u16 *)(g + 0xA70) & 0x100;
            *(u16 *)(p + 0x86) = *(u16 *)(g + 0xA72) & 0x100;
            return;
        }
    }
    *(u16 *)(p + 0x86) = 0;
    *(u16 *)(p + 0x84) = 0;
}
