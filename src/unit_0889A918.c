/* unit_0889A918: 0x0889A918-0x0889AA08 (ULES01213)
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
extern s32 func_0889C518(char *);
extern void func_0889CD24(char *, s32);
extern void func_0889D244(char *, s32);
extern void func_0889D6EC(char *);

void func_0889A918(char *arg0) {
    C3_2 cp1C;
    char *p;

    cp1C.p0 = ((C3_2 *)arg0)->p0;
    cp1C.p1 = ((C3_2 *)arg0)->p1;
    p = *(char **)&cp1C.p0.c;
    *(s32 *)(p + 0x12C0) = *(s32 *)(p + 0x12C0) & ~0x400;
    *(u8 *)(p + 0x1AF4) = (u8) (*(s8 *)&cp1C.p1.a == 0);
    *(s32 *)(p + 0x1AF8) = (s32) *(u16 *)&cp1C.p1.b;
    if (*(u8 *)(p + 0x1AF4) != 0) {
        func_0889CF34(p, 2);
        if (*(u8 *)(p + 0x12D6) != 0) {
            func_0889CD24(p, func_0889C518(p));
        }
        func_0889D244(p, 0);
        func_0889D6EC(p);
        return;
    }
    if (*(s32 *)(p + 0x1AF8) == 0x8003 || *(s32 *)(p + 0x1AF8) == 0x8007 || *(s32 *)(p + 0x1AF8) == 0x8001) {
        *(s8 *)(p + 0x1AFC) = 1;
    }
}
