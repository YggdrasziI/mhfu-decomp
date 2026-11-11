/* unit_08829E6C: 0x08829E6C-0x08829EEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_08A62C7C;
extern int func_0886C8AC(s32, s32);
extern s32 func_08872F0C(s32);
extern int func_088966C0(char *, s32);
extern s32 func_088D7904(s32);

void func_08829E6C(char *arg0, s32 arg1) {
    if ((func_088D7904(*(s32 *)(arg0 + 0x530)) & 0xFFFF) > 0) {
        func_0886C8AC(D_08A62C7C, arg1);
        *(s8 *)(arg0 + 0x1207) = 1;
        if ((func_08872F0C(D_08A62C7C) & 0xFF) == 1) {
            func_088966C0(arg0, 0xF);
        }
    }
}
