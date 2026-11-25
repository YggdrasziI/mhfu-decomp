/* unit_0885F7D4: 0x0885F7D4-0x0885F82C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    char pad[8];
} E10;

extern E10 D_08979758[];

s32 func_0885F7D4(s32 arg0, u8 *arg1) {
    E10 *e;
    s32 i;

    if (arg1[1] == 5) {
        i = 0;
        e = D_08979758;
        for (; e->id != 0xFFFF; i++) {
            if (e->id == *(u16 *)(arg1 + 2)) {
                return i;
            }
            e++;
        }
    }
    return -1;
}
