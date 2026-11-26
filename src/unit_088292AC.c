/* unit_088292AC: 0x088292AC-0x088295C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * The compaction source pointer is volatile: the original reads its key
 * again after the zero test.
 * The three saved keys are Rec locals never set on every path: their
 * initial values are loaded from the stack in the prologue.
 */

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 key;
    s16 val;
} Rec;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *func_088DCEBC(s32, s32);
extern Rec *func_08856884(char *, s32);
extern s32 func_088295C0(s32, char *);
extern u16 func_088D7AD8(char *, u16, u8);
extern void func_088D8000(char *);
extern void func_0885C5DC(Rec *, u32);
extern int func_088D893C(char *);

void func_088292AC(s32 arg0, u8 arg1) {
    Rec a;
    Rec b;
    Rec c;
    char *p;
    Rec *tbl;
    Rec *e;
    volatile Rec *f;
    u32 i;
    u32 j;
    u32 n;
    u32 flags;
    u8 s0;
    u8 s1;

    p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    if (arg1 == 0) {
        tbl = func_08856884(D_089CC438, 0);
    } else {
        tbl = (Rec *)(D_089CC438 + 0x43C8);
    }
    flags = *(u32 *)(D_089CC438 + 0x6AF14);
    if (!((s32)((flags & 1) != 0) != 0 || (s32)((flags & 8) != 0) != 0)) {
        if (func_088295C0(arg0, p) < 0) {
            return;
        }
        *(u16 *)(p + 0x686) = (u8)func_088D7AD8(p, *(u8 *)(p + 0x686), 2);
        s0 = *(u8 *)(p + 0x67C);
        s1 = *(u8 *)(p + 0x5F6);
        func_088D8000(p);
        *(u8 *)(p + 0x67C) = s0;
        *(u8 *)(p + 0x5F6) = s1;
        a.key = func_08856884(D_089CC438, *(u16 *)(p + 0x648))->key;
        if (*(u8 *)(p + 0x686) != 0xFF) {
            b.key = func_08856884(D_089CC438, *(u8 *)(p + 0x686))->key;
        } else {
            b.key = 0;
        }
        if (*(u8 *)(p + 0x5F6) != 0xFF) {
            c.key = func_08856884(D_089CC438, *(u8 *)(p + 0x5F6))->key;
        }
    }
    j = 0x18;
    e = tbl;
    n = 0;
    for (i = 0x18; i != 0 && j != 0; i--, e++) {
        if (e->key != 0) {
            n++;
        } else {
            j = i - 1;
            f = e + 1;
            if (j != 0) {
                do {
                    if (f->key != 0) {
                        n++;
                        e->key = f->key;
                        e->val = f->val;
                        f->val = 0;
                        f->key = 0;
                        break;
                    }
                    j--;
                    f++;
                } while (j != 0);
            }
        }
    }
    func_0885C5DC(tbl, n);
    flags = *(u32 *)(D_089CC438 + 0x6AF14);
    if (!((s32)((flags & 1) != 0) != 0 || (s32)((flags & 8) != 0) != 0)) {
        if (arg1 == 0) {
            e = func_08856884(D_089CC438, 0);
            i = 0;
            do {
                    if (e->key == a.key) {
                        *(u16 *)(p + 0x648) = i;
                        break;
                    }
                    i++;
                    e++;
            } while (i < 0x18);
            e = func_08856884(D_089CC438, 0);
            i = 0;
            do {
                    if (e->key == b.key) {
                        *(u16 *)(p + 0x686) = (u8)i;
                        break;
                    }
                    i++;
                    e++;
            } while (i < 0x18);
            if (*(u8 *)(p + 0x5F6) != 0xFF) {
                e = func_08856884(D_089CC438, 0);
                i = 0;
                do {
                        if (e->key == c.key) {
                            *(u8 *)(p + 0x5F6) = i;
                            break;
                        }
                        i++;
                        e++;
                } while (i < 0x18);
            }
        }
    } else if (arg1 != 0 && p != 0) {
        func_088D893C(p);
    }
}
