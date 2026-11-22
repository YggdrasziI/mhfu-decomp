/* unit_08873554: 0x08873554-0x08873614 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef short s16;
typedef int s32;

typedef struct {
    char pad0[0x56C];
    s32 unk56C[16];
    char pad5AC[0x718 - 0x5AC];
    s32 unk718;
    s32 unk71C;
} Obj08873554;

extern void func_08873614(Obj08873554 *arg0, s32 arg1, s16 *arg2);
extern void func_0887370C(Obj08873554 *arg0, s32 arg1, s16 *arg2);

void func_08873554(Obj08873554 *arg0, s16 *arg1) {
    s16 *p = arg1;
    s32 i;

    for (i = 0; i < 16; i++) {
        arg0->unk56C[i] = 0;
    }
    for (i = 0; i < 0x5A; i++) {
        *arg1++ = 0;
    }
    func_08873614(arg0, arg0->unk71C, p);
    func_0887370C(arg0, arg0->unk718, p);
}
