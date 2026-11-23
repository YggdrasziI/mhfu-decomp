/* unit_08864408: 0x08864408-0x08864440 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;
typedef float f32;

typedef struct {
    char pad0[0x10];
    f32 unk10;
    char pad14[0x2C];
} Ent; /* size 0x40 */

s32 func_08864408(Ent *p, s32 idx, f32 x)
{
    if (*(s8 *)((char *)p + 0x3E) != 0) {
        return 0;
    }
    if (x <= p[idx].unk10) {
        return 1;
    }
    return 0;
}
