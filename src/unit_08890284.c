/* unit_08890284: 0x08890284-0x088902A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_088902A8.
 */

typedef int s32;
typedef unsigned short u16;

/* Layout (hypothesis): u16 array at 0xF7A580 of the record passed in a0. */
typedef struct {
    char pad0[0xF7A580];
    u16 unkF7A580[1];
} Struct_08890284;

s32 func_08890284(Struct_08890284 *arg0, u16 arg1, s32 arg2) {
    return arg0->unkF7A580[arg2] == arg1;
}
