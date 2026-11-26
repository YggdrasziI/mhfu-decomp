/* unit_08823960: 0x08823960-0x088239FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern s32 func_088D6A1C(char *, s32);
extern s32 func_088D6A54(char *, s32);
extern s32 func_088DAE98(char *, s32);

s32 func_08823960(char *arg0, char *arg1, s16 arg2) {
    if (arg2 >= 0) {
        if (arg2 < 5) {
            if ((u8)func_088DAE98(arg1, 0x2000) == 1) {
                return 1;
            }
            return func_088D6A1C(arg1, 0x44);
        }
        if ((u8)func_088D6A1C(arg1, 0x43) == 1) {
            return 1;
        }
        return func_088D6A54(arg1, 9);
    }
    return 0;
}
