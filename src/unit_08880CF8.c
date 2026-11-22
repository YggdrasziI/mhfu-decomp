/* unit_08880CF8: 0x08880CF8-0x08880D64 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 unk0[4];
    u16 unk8[4];
    u16 unk10[4];
    u16 unk18[4];
    u8 unk20[4];
    s32 unk24;
    s32 unk28;
} Struct_08880CF8;

void func_08880CF8(char *arg0, s32 arg1) {
    Struct_08880CF8 *a3;
    Struct_08880CF8 *t0;

    t0 = (Struct_08880CF8 *)(arg0 + 0x8B64);
    a3 = (Struct_08880CF8 *)(arg0 + 0x56243C);
    t0->unk0[arg1] = 0xFFFF;
    t0->unk8[arg1] = 0xFFFF;
    t0->unk10[arg1] = 0xFFFF;
    t0->unk18[arg1] = 0;
    t0->unk20[arg1] = 0;
    if (arg1 == 0) {
        t0->unk24 = -1;
        t0->unk28 = -1;
    }
    a3->unk0[arg1] = 0xFFFF;
    a3->unk8[arg1] = 0xFFFF;
    a3->unk10[arg1] = 0xFFFF;
    a3->unk18[arg1] = 0;
    a3->unk20[arg1] = 0;
}
