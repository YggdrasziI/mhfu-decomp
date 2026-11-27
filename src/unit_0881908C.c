/* unit_0881908C: 0x0881908C-0x08819128 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern void func_08819128(char *, s32, s32, s32);

void func_0881908C(char *p) {
    s32 mode = *(u8 *)(p + 0x5FE);
    s32 id = *(u16 *)(p + 0x5FC);

    if (mode == 3) {
        if ((id == 8 && *(u8 *)(p + 0x5E4) == 1) ||
            (id == 10 && *(s8 *)(p + 0x60A) == 1)) {
            id = 12;
        } else if ((id == 8 && *(u8 *)(p + 0x5E4) == 2) ||
                   (id == 10 && *(s8 *)(p + 0x60A) == 2)) {
            id = 13;
        }
    }
    func_08819128(p, mode, id, *(s8 *)(p + 0x5FF));
}
