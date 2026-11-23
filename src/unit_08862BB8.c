/* unit_08862BB8: 0x08862BB8-0x08862D34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Mat {
    u8 unk0[16];
} Mat;

typedef struct Part {
    s32 unk0;
    s32 unk4;
    Mat *unk8;
} Part;

extern u8 *func_08862768(s32, s32, s32);
extern s32 func_08862748(s32, s32);

void func_08862BB8(Part *arg0, u16 arg1, u8 arg2) {
    u8 *ids;
    s32 n;
    s32 i;

    ids = func_08862768(arg0->unk0, arg1, 0);
    n = (u8) func_08862748(arg0->unk0, arg1);
    for (i = 0; i < n; i++) {
        arg0->unk8[ids[i]].unk0[3] = arg2;
    }
}
