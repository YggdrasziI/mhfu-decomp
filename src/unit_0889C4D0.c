/* unit_0889C4D0: 0x0889C4D0-0x0889C518 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

/* func_0889C4D0: callback registered with func_088B0C3C (id 0x13). */
#pragma optimize_for_size off

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    s32 unk0;
    s32 unk4;
    char *unk8;
    s32 unkC;
    u16 unk10;
} Msg;

void func_0889C4D0(Msg *arg0) {
    Msg m = *arg0;

    *(s32 *) (m.unk8 + 0x1AF8) = m.unk10;
    *(u8 *) (m.unk8 + 0x1AFC) = 1;
}
