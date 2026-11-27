/* unit_08814A14: 0x08814A14-0x08814BE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Relocates a loaded block: turns stored offsets into pointers relative to
 * the block (hypothesis on the purpose; layout from the offsets used).
 * Speed setting: the last loop is unrolled by 8 in the original.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Ent {
    s32 count;
    s32 off;
} Ent;

typedef struct Sub {
    char pad[0x40];
} Sub;

typedef struct Blk {
    char pad0[5];
    u8 n;
    char pad6[0x12];
    s32 off18;
    s32 off1C;
    char pad20[0x2E0];
    Sub sub[1];
} Blk;

void func_08814A14(char *arg0, char *arg1) {
    Blk *p;
    s32 n;
    Ent *e;
    s32 *q;
    s32 total;
    s32 i;

    if (arg1 == 0) {
        *(char **)(arg0 + 0xAAC) = 0;
        return;
    }
    *(char **)(arg0 + 0xAAC) = arg1;
    p = (Blk *)(arg1 + 0x30);
    *(Blk **)(arg1 + 0x28) = p;
    for (n = *(u16 *)(arg1 + 2); n > 0; n--) {
        if (p->off1C != 0) {
            p->off18 = (s32)((char *)p + p->off18);
            p->off1C = (s32)((char *)p + p->off1C);
            p = (Blk *)((s32)((s32)p->sub + p->n * 64) + 0x20);
        } else {
            p->off18 = (s32)((char *)p + p->off18);
            p = (Blk *)((s32)p->sub + p->n * 64);
        }
    }
    total = 0;
    if (*(s32 *)(arg1 + 0x1C) != 0) {
        e = (Ent *)(arg1 + *(s32 *)(arg1 + 0x1C));
        *(Ent **)(arg1 + 0x1C) = e;
        for (n = *(u16 *)(arg1 + 4) * *(u16 *)(arg1 + 6); n > 0; n--, e++) {
            if (e->count != 0) {
                e->off = (s32)(arg1 + e->off);
                total += e->count;
            }
        }
    } else {
        *(s32 *)(arg1 + 0x1C) = 0;
    }
    if (*(s32 *)(arg1 + 0x20) != 0) {
        q = (s32 *)(arg1 + *(s32 *)(arg1 + 0x20));
        *(s32 **)(arg1 + 0x20) = q;
        for (i = total; i > 0; i--) {
            *q = (s32)(arg1 + *q);
            q++;
        }
    } else {
        *(s32 *)(arg1 + 0x20) = 0;
    }
}
