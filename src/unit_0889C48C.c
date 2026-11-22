/* unit_0889C48C: 0x0889C48C-0x0889C4D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

/* func_0889C48C: copies its 0x14-byte float record argument to the stack
 * and sets bit 0x8000 of the word at 0x12C4 of the object held in the
 * record's third word (same record as func_0889A138). */

typedef int s32;
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

void func_0889C48C(Arg *arg) {
    Arg copy;
    char *p;

    copy.a = arg->a;
    copy.b = arg->b;
    p = *(char **)&copy.a.c;
    *(u32 *)(p + 0x12C4) |= 0x8000;
}
