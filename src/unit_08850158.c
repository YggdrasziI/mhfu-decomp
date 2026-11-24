/* unit_08850158: 0x08850158-0x08850238 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08850158: arg1 is masked to u8 for the first call and the table
 * index but passed unmasked to func_08850338 (as in the original). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 func_0884FFCC(char *, s32);
extern s32 func_08850338(char *, s32, u8 *);
extern float D_0899C760[];

float func_08850158(char *arg0, s32 arg1, s32 arg2) {
    u8 tmp;
    u16 v;

    if (arg2 == 0) {
        v = func_0884FFCC(arg0, (u8)arg1);
        return (float)v * D_0899C760[(u8)arg1] / 100.0f;
    }
    v = func_08850338(arg0, arg1, &tmp);
    return (float)v * D_0899C760[(u8)arg1] / 100.0f;
}
