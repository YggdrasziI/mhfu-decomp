/* unit_08857558: 0x08857558-0x088575C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;

extern u16 *func_08856884(char *, s32);

s32 func_08857558(char *arg0, u16 arg1) {
    s32 i;

    i = 0;
    do {
        if (arg1 == *func_08856884(arg0, i)) {
            return (s16)i;
        }
        i++;
    } while (i < 24);
    return 0xFF;
}
