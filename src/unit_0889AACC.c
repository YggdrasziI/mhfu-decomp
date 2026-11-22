/* unit_0889AACC: 0x0889AACC-0x0889ABA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;
typedef struct { F3 p0; F2 p1; } C3_2;

extern void func_0889CF34(char *, s32);
extern void func_088B3A3C(char *);
extern void func_0889D318(char *, char *);
extern void func_0889D6EC(char *);

void func_0889AACC(char *arg0) {
    C3_2 cp7C;
    char *p;
    char buf[0x64];

    cp7C.p0 = ((C3_2 *)arg0)->p0;
    cp7C.p1 = ((C3_2 *)arg0)->p1;
    p = *(char * *)&cp7C.p0.c;
    *(s32 *)(p + 0x12C0) = (s32) (*(s32 *)(p + 0x12C0) & ~0x1000);
    *(u8 *)(p + 0x1AF4) = (u8) (*(s8 *)&cp7C.p1.a == 0);
    *(s32 *)(p + 0x1AF8) = (s32) *(u16 *)&cp7C.p1.b;
    if (*(u8 *)(p + 0x1AF4) != 0) {
        func_0889CF34(p, 3);
        func_088B3A3C(buf);
        func_0889D318(p, buf);
        func_0889D6EC(p);
        return;
    }
    {
        s32 v = *(s32 *)(p + 0x1AF8);
        if (v == 0x8003 || v == 0x8007 || v == 0x8001) {
            *(s8 *)(p + 0x1AFC) = 1;
        }
    }
}
