/* unit_0885ACA8: 0x0885ACA8-0x0885AED0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885ACA8: adds arg2 to the count of item arg1 in the 24 (id, count)
 * slots at D_089CC438 + 0x4A0 + 0x3F28, capped by the table byte
 * D_0899D19B[arg1 * 24] (a 0xFF byte sets the amount to 0xFF).
 * Not held: takes a free slot (returns 0) or returns 5 if none. Held:
 * returns 3 (already at the cap), 1 (negative with 0xFF cap, or added),
 * 4 (count dropped to 0, slot freed through func_0885AFF8), 2 (capped);
 * held but no slot found: r is returned uninitialised, as in the original.
 * Speed setting (strength-reduced slot offsets). func_0885AFF8 receives
 * the slot index: it keeps the counter in $a1 across the second loop.
 */

#pragma optimize_for_size off
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 id;
    s16 count;
} Slot;

typedef struct {
    char pad[0x3F28];
    Slot slots[24];
} Inv;

extern char *D_089CC438;
extern u8 D_0899D19B[][24];

extern s32 func_0885AED0(char *, u16);
extern void func_0885ACA0(char *, u16);
extern s32 func_0885AFF8(char *, s16);

u16 func_0885ACA8(char *arg0, u16 arg1, s16 arg2) {
    s16 j;
    s32 r;
    u8 *ent;
    Inv *inv;
    s16 i;
    u8 max;
    s16 m;

    inv = (Inv *)(D_089CC438 + 0x4A0);
    ent = D_0899D19B[arg1];
    if (*ent == 0xFF) {
        arg2 = 0xFF;
    }
    if ((s16)func_0885AED0(arg0, arg1) == 0) {
        r = 5;
        for (i = 0; i < 24; i++) {
            if (inv->slots[i].id == 0 && arg2 > 0) {
                m = *ent;
                inv->slots[i].id = arg1;
                if (m < arg2) {
                    arg2 = m;
                }
                inv->slots[i].count = arg2;
                func_0885ACA0(arg0, arg1);
                r = 0;
                goto end;
            }
        }
    } else {
        for (j = 0; j < 24; j++) {
            if (inv->slots[j].id == arg1) {
                max = *ent;
                m = max;
                if (arg2 > 0 && inv->slots[j].count >= m) {
                    inv->slots[j].count = m;
                    func_0885ACA0(arg0, arg1);
                    r = 3;
                    goto end;
                }
                if (arg2 < 0 && max == 0xFF) {
                    r = 1;
                    goto end;
                }
                inv->slots[j].count += arg2;
                if (inv->slots[j].count <= 0) {
                    func_0885AFF8(arg0, j);
                    inv->slots[j].id = 0;
                    inv->slots[j].count = 0;
                    r = 4;
                    goto end;
                }
                if (inv->slots[j].count > m) {
                    inv->slots[j].count = m;
                    r = 2;
                } else {
                    r = 1;
                }
                func_0885ACA0(arg0, arg1);
                goto end;
            }
        }
    }
end:
    return r;
}
