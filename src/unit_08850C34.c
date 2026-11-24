/* unit_08850C34: 0x08850C34-0x08850C9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

/* 12-byte record; only the first two bytes are read here. */
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[10];
} Unk4A0Ent;

/* Sub-object at arg0 + 0x4A0, records from its offset 0xA8. */
typedef struct {
    u8 pad0[0xA8];
    Unk4A0Ent ent[1];
} Unk4A0;

s32 func_08850C34(char *arg0, u16 idx, u8 x, u8 y) {
    Unk4A0 *p = (Unk4A0 *)(arg0 + 0x4A0);

    if (idx == 0xFFFF) {
        return 0;
    }
    if (p->ent[idx].unk0 != 0) {
        if (p->ent[idx].unk1 == x || p->ent[idx].unk1 == y) {
            goto found;
        }
    }
    return 0;
found:
    return 1;
}
