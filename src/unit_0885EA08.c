/* unit_0885EA08: 0x0885EA08-0x0885EAA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
/* func_0885EA08: clears out[0..2], then for each of the three non-zero u16
 * ids at arg1 + 6 writes the id func_0885E834(arg0, id)[0] times into out.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    char pad[6];
    u16 ids[3];
} S;

extern u8 *func_0885E834(s32, s32);

void func_0885EA08(s32 arg0, S *arg1, u16 *out) {
    s32 i;
    s32 j;
    u8 *p;

    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    for (i = 0; i < 3; i++) {
        if (arg1->ids[i] != 0) {
            p = func_0885E834(arg0, arg1->ids[i]);
            for (j = 0; j < *p; j++) {
                *out++ = arg1->ids[i];
            }
        }
    }
}
