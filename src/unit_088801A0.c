/* unit_088801A0: 0x088801A0-0x088801E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function that fills a request block on the
 * stack and passes it to func_0889EACC.
 */

typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8[7];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
} Struct_088801A0;

extern void func_0889EACC(s32, s32, s32, Struct_088801A0 *);

void func_088801A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   s32 arg6, s32 arg7, s32 arg8) {
    Struct_088801A0 sp14;

    sp14.unk4 = arg2;
    sp14.unk30 = arg5;
    sp14.unk24 = arg6;
    sp14.unk28 = arg7;
    sp14.unk38 = arg8;
    sp14.unk0 = 0x2B01;
    func_0889EACC(arg1, arg3, arg4, &sp14);
}
