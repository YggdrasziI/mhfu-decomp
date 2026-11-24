/* unit_08850078: 0x08850078-0x08850158 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern u16 func_0884FFB8(char *, u8);
extern u16 func_0885028C(char *, s32, u8 *);
extern float D_0899C760[];

float func_08850078(char *arg0, s32 arg1, s32 arg2) {
    u8 buf;
    u32 v;
    float *p;

    if (arg2 == 0) {
        v = func_0884FFB8(arg0, (u8)arg1);
        p = &D_0899C760[(u8)arg1];
        return (float)v * *p / 100.0f;
    }
    v = func_0885028C(arg0, arg1, &buf);
    p = &D_0899C760[(u8)arg1];
    return (float)v * *p / 100.0f;
}
