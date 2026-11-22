/* unit_0889A1E4: 0x0889A1E4-0x0889A290 (ULES01213) */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct { f32 x, y, z; } F3;
typedef struct { f32 x, y; } F2;
typedef struct { F3 a; F2 b; } Msg;

extern void func_0889CF34(char *, s32);
extern void func_0889D6EC(char *);

void func_0889A1E4(Msg *arg0) {
    Msg m;
    char *p;

    m.a = arg0->a;
    m.b = arg0->b;
    p = *(char **) ((char *) &m + 8);
    *(s32 *) (p + 0x12C0) &= ~4;
    *(u8 *) (p + 0x1AF4) = *(s8 *) ((char *) &m + 0xC) == 0;
    *(s32 *) (p + 0x1AF8) = *(u16 *) ((char *) &m + 0x10);
    if (*(u8 *) (p + 0x1AF4)) {
        func_0889CF34(p, 0);
        func_0889D6EC(p);
    } else if (*(s32 *) (p + 0x1AF8) == 0x8003) {
        *(u8 *) (p + 0x1AFC) = 1;
    }
}
