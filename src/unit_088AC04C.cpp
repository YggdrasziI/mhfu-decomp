/* unit_088AC04C: 0x088AC04C-0x088AC0D0 (ULES01213)
 *
 * Bounds (hypothesis): last function of the old asm piece text_088AB980,
 * before unit_088AC0D0.
 *
 * C++: the flag tests keep their `sltu` (bool).
 *
 * If the current entry (index at +0x420) of the four 0x8C-byte records of
 * D_089CC438 is not active (+0x30), selects the first active one.
 */

typedef unsigned char u8;

typedef struct {
    char unk0[0x30];
    u8 active;
    char unk31[0x5B];
} Rec;

extern "C" {

extern char *D_089CC438;

void func_088AC04C(void) {
    Rec *g = (Rec *) D_089CC438;
    u8 *cur = (u8 *) ((char *) g + 0x420);
    u8 i;

    if ((bool) g[*cur].active == 0) {
        i = 0;
        do {
            if ((bool) g[i].active != 0) {
                *cur = i;
                break;
            }
            i++;
        } while (i < 4);
    }
}

}
