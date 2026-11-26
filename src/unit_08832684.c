/* unit_08832684: 0x08832684-0x08832838 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Size_08939DE4;

extern Size_08939DE4 D_08939DE4;
extern Size_08939DE4 D_08939DF0;
extern void func_0882BE60(s32, u16, u16, u16, u16, s32, s32, s32, s32);

void func_08832684(s32 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4, s32 arg5) {
    Size_08939DE4 *a = (Size_08939DE4 *)(s32)&D_08939DE4;
    Size_08939DE4 *b = (Size_08939DE4 *)(s32)&D_08939DF0;

    func_0882BE60(arg0, arg1, arg2, arg3, (u16) a->unk6, arg5, arg5, arg5, 0x105);
    func_0882BE60(arg0, arg1, arg2 + arg4 - a->unk6, arg3, a->unk6, arg5, arg5, arg5, 0x105);
    func_0882BE60(arg0, arg1, arg2 + a->unk6, (u16) b->unk4, arg4 - a->unk6 * 2, arg5, arg5, arg5, 0x106);
    func_0882BE60(arg0, arg1 + arg3 - b->unk4, arg2 + a->unk6, b->unk4, arg4 - a->unk6 * 2, arg5, arg5, arg5, 0x106);
    func_0882BE60(arg0, arg1 + b->unk4, arg2 + a->unk6, arg3 - b->unk4 * 2, arg4 - a->unk6 * 2, arg5, arg5, arg5, 0x107);
}
