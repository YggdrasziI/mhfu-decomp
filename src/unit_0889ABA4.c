/* unit_0889ABA4: 0x0889ABA4-0x0889AC14 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;
typedef struct { F3 p0; F2 p1; } C3_2;

void func_0889ABA4(char *arg0) {
    C3_2 cpC;

    cpC.p0 = ((C3_2 *)arg0)->p0;
    cpC.p1 = ((C3_2 *)arg0)->p1;
    *(s32 *)((*(char * *)&cpC.p0.c) + 0x12C0) = (s32) (*(s32 *)((*(char * *)&cpC.p0.c) + 0x12C0) & ~0x2000);
    *(s8 *)((*(char * *)&cpC.p0.c) + 0x1AF4) = (s8) (*(s8 *)&cpC.p1.a == 0);
    *(s32 *)((*(char * *)&cpC.p0.c) + 0x1AF8) = (s32) *(u16 *)&cpC.p1.b;
    if (*(u16 *)&cpC.p1.b == 0x8003) {
        *(s8 *)((*(char * *)&cpC.p0.c) + 0x1AFC) = 1;
    }
}
