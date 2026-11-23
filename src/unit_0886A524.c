/* unit_0886A524: 0x0886A524-0x0886A58C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886A524: is the current entry of the slot matching a1->0x1E8 the last one */
typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s8 list[10]; /* 0x00 */
    s8 count;    /* 0x0A */
    s8 cur;      /* 0x0B */
    u8 pad[0x20];
} Slot; /* size 0x2C */

typedef struct {
    u8 pad[0x77C];
    Slot slot[2];
} Owner;

#pragma optimize_for_size off

s32 func_0886A524(Owner *a0, u8 *a1) {
    u8 id = a1[0x1E8];
    s32 i;
    Owner *p = a0;

    for (i = 0; i < 2; i++) {
        if (p->slot[0].list[p->slot[0].cur] == id) {
            return a0->slot[i].cur >= a0->slot[i].count - 1;
        }
        p = (Owner *)((char *)p + sizeof(Slot));
    }
    return 0;
}
