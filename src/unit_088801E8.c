/* unit_088801E8: 0x088801E8-0x08880254 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8[8];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
} Unk088801E8;

extern void func_088B8320(float, Unk088801E8 *);
extern void func_0889EACC(s32, s32, s32, Unk088801E8 *);

void func_088801E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, float f) {
    Unk088801E8 sp14;

    sp14.unk0 = 0x2A01;
    sp14.unk4 = arg2;
    sp14.unk30 = arg5;
    sp14.unk28 = arg6;
    sp14.unk38 = arg7;
    func_088B8320(f, &sp14);
    func_0889EACC(arg1, arg3, arg4, &sp14);
}
