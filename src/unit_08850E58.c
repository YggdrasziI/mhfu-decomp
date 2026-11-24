/* unit_08850E58: 0x08850E58-0x08850EC4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

extern char *D_08A62C50;
extern u8 func_0885C5CC(char *, u16);

s16 func_08850E58(char *arg0) {
    s16 count;
    u16 i;

    count = 8;
    for (i = 0x33D; i <= 0x33E; i++) {
        if (func_0885C5CC(D_08A62C50, i) == 1) {
            count++;
        }
    }
    return count;
}
