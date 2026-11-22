/* unit_088911A0: 0x088911A0-0x088912BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4;
    u8 unk5;
    s8 unk6;
    u8 unk7;
    u16 *unk8;
} Entry;

void func_088911A0(u8 *arg0, u16 *arg1) {
    s8 idx = *(s8 *) (arg0 + 0x12F);
    s32 wraps = 0;
    u8 *countp = (u8 *) (idx + (s32) arg0) + 0x134;
    u8 count = *countp;
    Entry *e;
    u16 *dst;
    u16 c;

    if (count < 0x80) {
        e = ((Entry **) (arg0 + 0x140))[idx] + count;
        *countp = count + 1;
        e->unk0 = *(s16 *) (arg0 + 0x120);
        e->unk2 = *(s16 *) (arg0 + 0x122);
        e->unk4 = arg0[0x12C];
        e->unk5 = arg0[0x12D];
        e->unk7 = arg0[0x15F];
        e->unk6 = *(s8 *) (arg0 + 0x12E);
        dst = (u16 *) (arg0 + *(u16 *) (arg0 + 0x160) + 0x22CF8);
        e->unk8 = dst;
        while ((c = *arg1) != 0) {
            *dst = c;
            *(u16 *) (arg0 + 0x160) += 2;
            dst++;
            arg1++;
            if (*(u16 *) (arg0 + 0x160) >= 0x3000) {
                *(u16 *) (arg0 + 0x160) = 0x2FFE;
                dst = (u16 *) (arg0 + *(u16 *) (arg0 + 0x160) + 0x22CF8);
                wraps++;
            }
        }
        *dst = 0;
        if (wraps == 0) {
            *(u16 *) (arg0 + 0x160) += 2;
            if (*(u16 *) (arg0 + 0x160) >= 0x3000) {
                *(u16 *) (arg0 + 0x160) = 0x2FFE;
            }
        }
    }
}
