/* unit_08870D30: 0x08870D30-0x08870D40 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_08870D30(char *arg0) {
    *(u8 *)(arg0 + 0x716) = 0;
    *(u16 *)(arg0 + 0x714) = 0xFFFF;
}
