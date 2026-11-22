/* unit_0889C0D4: 0x0889C0D4-0x0889C144 (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
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

void func_0889C0D4(Arg *arg) {
    Arg copy;
    char *p;
    u8 k;

    copy.a = arg->a;
    copy.b = arg->b;
    p = *(char **)&copy.a.c;
    k = *(u8 *)(p + 0x12D5);
    if ((k == 3) | (k == 4) | (k == 5)) {
        *(u32 *)(p + 0x12C4) |= 0x400;
    }
}
