/* unit_0886A054: 0x0886A054-0x0886A0B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_09A1DAEC;
extern s32 func_0886A30C(s32, s32);
extern int func_088AB514(s32, s32, s32);

void func_0886A054(s32 arg0) {
    if (func_0886A30C(arg0, 1) == 0) {
        *(s8 *)(D_089CC438 + 0x2E) = 7;
        *(s8 *)(arg0 + 6) = 7;
        *(s16 *)(arg0 + 0x1C) = -1;
        func_088AB514(D_09A1DAEC, 0xC, 0);
    }
}
