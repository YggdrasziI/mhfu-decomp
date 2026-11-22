/* unit_088855D0: 0x088855D0-0x08885644 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
extern u16 D_09BC8400[][3];
s32 func_088855D0(char *arg0, s32 arg1) {
    char *base;
    s32 i;
    u16 key;
    base = arg0 + 0x56243C;
    key = D_09BC8400[arg1][0];
    for (i = 0; i < 4; i++) {
        if (D_09BC8400[*(u8 *)(base + i + 0x20)][0] == key) {
            return ((s16 *)(base + 0x18))[i];
        }
    }
}
