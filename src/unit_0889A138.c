/* unit_0889A138: 0x0889A138-0x0889A1E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct {
    f32 a, b, c;
} F3;
typedef struct {
    f32 a, b;
} F2;
typedef struct {
    F3 a;
    F2 b;
} Arg;

extern void func_0889CF34(char *, s32);
extern void func_0889D6EC(char *);

void func_0889A138(Arg *arg) {
    Arg copy;
    char *p;

    copy.a = arg->a;
    copy.b = arg->b;
    p = *(char **)&copy.a.c;
    *(u32 *)(p + 0x12C0) &= ~2;
    *(u8 *)(p + 0x1AF4) = *(s8 *)&copy.b.a == 0;
    *(u32 *)(p + 0x1AF8) = *(u16 *)&copy.b.b;
    if (*(u8 *)(p + 0x1AF4)) {
        func_0889CF34(p, 1);
        func_0889D6EC(p);
    } else if (*(u32 *)(p + 0x1AF8) == 0x8003) {
        *(u8 *)(p + 0x1AFC) = 1;
    }
}
