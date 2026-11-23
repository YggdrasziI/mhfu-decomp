/* unit_088629DC: 0x088629DC-0x08862BB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088629DC: sets the colour bytes 4-6 of every material of one group. */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Mat {
    u8 unk0[16];
} Mat;

typedef struct Part {
    s32 unk0;
    s32 unk4;
    Mat *unk8;
} Part;

extern s32 func_08862748(s32, s32);
extern u8 *func_08862768(s32, s32, s32);

void func_088629DC(Part *part, u16 arg1, u8 r, u8 g, u8 b) {
    u8 *ids;
    s32 n;
    s32 i;
    Mat *m;

    ids = func_08862768(part->unk0, arg1, 0);
    n = (u8) func_08862748(part->unk0, arg1);
    for (i = 0; i < n; i++) {
        m = &part->unk8[ids[i]];
        m->unk0[4] = r;
        m->unk0[5] = g;
        m->unk0[6] = b;
    }
}
