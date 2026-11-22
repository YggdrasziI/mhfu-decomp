/* unit_0888C344: 0x0888C344-0x0888C3AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;

typedef union {
    s32 w;
    struct {
        s16 lo;
        s16 hi;
    } h;
} Fixed;

typedef struct {
    char pad[0x240];
    s16 a[1];
} Table;

float func_0888C344(float t, void *arg0, Table *arg1, s32 arg2) {
    Fixed f;
    s16 base;

    f.w = (s32)(65536.0f * t) * (arg1->a[arg2 + 1] - (base = arg1->a[arg2]));
    f.h.hi += base;
    return f.h.hi * 9.58738019e-05f;
}
