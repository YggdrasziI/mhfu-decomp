/* unit_0885BB00: 0x0885BB00-0x0885BD0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_0885BB00: removes arg2 units of item arg1 from the slot table at
 * D_089CC438 + 0x4A0 + 0x2F88 (4-byte slots: u16 id, s16 count). With a slot
 * index (arg3 != 0xFFFF) it takes from that slot first, then recurses with
 * 0xFFFF for the rest; otherwise it walks the func_08850EC4() slots from the
 * last one down. Returns the amount still missing (0 when fully taken), 0 for
 * a negative amount, item 0 or an item whose table byte is 0xFF.
 *
 * Speed setting (loop counter strength-reduced, test at the bottom). Every
 * quantity is s16 and the subtractions are compound assignments: they keep
 * the raw parameter / local register in the subtraction and the store
 * through the field pointer, while the compares sign-extend.
 */

typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 id;
    s16 cnt;
} Slot;

typedef struct {
    char pad[0x2F88];
    Slot slot[1];
} Box;

extern char *D_089CC438;
extern u8 D_0899D19B[][24];
extern s16 func_08850EC4(char *arg0);

s16 func_0885BB00(char *arg0, u16 arg1, s16 arg2, u16 arg3) {
    Box *box = (Box *)(D_089CC438 + 0x4A0);
    s16 rem;
    s16 n;
    s16 i;

    if (arg2 < 0) {
        return 0;
    }
    if (arg1 == 0 || D_0899D19B[arg1][0] == 0xFF) {
        return 0;
    }
    n = func_08850EC4(D_089CC438);
    rem = arg2;
    if (arg3 != 0xFFFF) {
        if (box->slot[arg3].cnt != 0) {
            if (box->slot[arg3].id == arg1) {
                if (box->slot[arg3].cnt >= arg2) {
                    box->slot[arg3].cnt -= arg2;
                    rem = 0;
                } else {
                    rem -= box->slot[arg3].cnt;
                    box->slot[arg3].cnt = 0;
                }
                if (box->slot[arg3].cnt <= 0) {
                    box->slot[arg3].id = 0;
                }
                if (rem > 0) {
                    rem = func_0885BB00(arg0, arg1, rem, 0xFFFF);
                }
            } else {
                rem = func_0885BB00(arg0, arg1, arg2, 0xFFFF);
            }
        } else {
            rem = func_0885BB00(arg0, arg1, arg2, 0xFFFF);
        }
    } else {
        for (i = n - 1; i >= 0; i--) {
            if (box->slot[i].id == arg1) {
                if (box->slot[i].cnt >= rem) {
                    box->slot[i].cnt -= rem;
                    rem = 0;
                } else {
                    rem -= box->slot[i].cnt;
                    box->slot[i].cnt = 0;
                }
                if (box->slot[i].cnt <= 0) {
                    box->slot[i].id = 0;
                }
                if (rem <= 0) {
                    return 0;
                }
            }
        }
    }
    return rem;
}
