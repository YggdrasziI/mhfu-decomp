/* unit_0889B160: 0x0889B160-0x0889B1A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef unsigned int u32;
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

void func_0889B160(Arg *arg) {
    Arg copy;
    char *p;

    copy.a = arg->a;
    copy.b = arg->b;
    p = *(char **)&copy.a.c;
    *(u32 *)(p + 0x12C4) |= 0x10;
}
