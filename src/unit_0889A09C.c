/* unit_0889A09C: 0x0889A09C-0x0889A138 (ULES01213)
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

extern s32 func_088B0724(s32, s32);

void func_0889A09C(char *arg0) {
    C3_2 cp1C;

    cp1C.p0 = ((C3_2 *)arg0)->p0;
    cp1C.p1 = ((C3_2 *)arg0)->p1;
    *(s32 *)((*(char * *)&cp1C.p0.c) + 0x12C0) = (s32) (*(s32 *)((*(char * *)&cp1C.p0.c) + 0x12C0) & ~1);
    *(u8 *)((*(char * *)&cp1C.p0.c) + 0x1AF4) = (u8) (*(s8 *)&cp1C.p1.a == 0);
    *(s32 *)((*(char * *)&cp1C.p0.c) + 0x1AF8) = (s32) *(u16 *)&cp1C.p1.b;
    if (*(u8 *)((*(char * *)&cp1C.p0.c) + 0x1AF4) != 0) {
        func_088B0724((s32) ((*(char * *)&cp1C.p0.c) + 0xEE0), (s32) ((*(char * *)&cp1C.p0.c) + 0xDC));
        return;
    }
    if (*(s32 *)((*(char * *)&cp1C.p0.c) + 0x1AF8) == 0x8003) {
        *(s8 *)((*(char * *)&cp1C.p0.c) + 0x1AFC) = 1;
    }
}
