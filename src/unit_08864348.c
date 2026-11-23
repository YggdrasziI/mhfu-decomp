/* unit_08864348: 0x08864348-0x08864408 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    char pad0[0x10];
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    char pad20[0x1C];
    u16 unk3C;
    s8 unk3E;
    char pad3F[1];
} Entry;

s32 func_08864348(Entry *arg0, s32 arg1, float arg2) {
    float lo;
    float end;
    float lim;
    s32 wrapped = 0;

    if (arg0->unk3E != 0) {
        return 0;
    }
    lo = arg0[arg1].unk10;
    end = lo + arg0[arg1].unk14;
    lim = arg0[arg1].unk1C;
    if (end > lim) {
        if (arg0[arg1].unk3C & 2) {
            end = arg0[arg1].unk18 + (end - lim);
            wrapped = 1;
        } else {
            end = lim;
        }
    }
    if (!wrapped) {
        if (arg2 >= lo && arg2 < end) {
            return 1;
        }
    } else {
        if (arg2 >= lo && end < lim) {
            return 1;
        }
    }
    return 0;
}
