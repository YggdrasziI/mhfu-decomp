/* unit_08859C40: 0x08859C40-0x08859D14 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08859C40: frees a block from func_08859B44 (hypothesis). */

typedef int s32;

typedef struct Blk {
    struct Blk *unk0;
    struct Blk *unk4;
    struct Blk *unk8;
    struct Blk *unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Blk;

void func_08859C40(char *arg0, char *arg1) {
    Blk *b;
    Blk *o;
    Blk *n;
    Blk *a;
    Blk *c;
    Blk *q;

    if (arg1 == 0) {
        return;
    }
    b = (Blk *)(arg1 - 0x20);
    o = b->unk4;
    if (o == 0) {
        return;
    }
    o->unk14 += b->unk10 + b->unk14;
    b->unk4 = 0;
    n = b->unk0;
    if (n == 0) {
        o->unk0 = 0;
    } else {
        o->unk0 = n;
        n->unk4 = o;
    }
    c = b->unkC;
    a = b->unk8;
    if (o->unkC == 0) {
        if (c == 0) {
            arg0 += 8;
            n = o->unk4;
            if (n != 0) {
                do {
                    if (n->unkC != 0) {
                        arg0 = (char *)n;
                        break;
                    }
                    n = n->unk4;
                } while (n != 0);
            }
            n = ((Blk *)arg0)->unk8;
            ((Blk *)arg0)->unk8 = o;
            o->unkC = (Blk *)arg0;
            o->unk8 = n;
            if (n != 0) {
                n->unkC = o;
            }
        } else {
            c->unk8 = o;
            o->unkC = c;
            o->unk8 = a;
            if (a != 0) {
                a->unkC = o;
            }
        }
    } else if (c != 0) {
        o->unk8 = a;
        if (a != 0) {
            a->unkC = o;
        }
    }
}
