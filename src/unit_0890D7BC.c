/* unit_0890D7BC: 0x0890D7BC-0x0890D950 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_0890D950.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} Range;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    Range *unkC;
    Range *unk10;
} Info;

extern s32 func_0890C3F4(s32, s32 *);
extern s32 func_0890DA3C(u32);
extern s32 func_0890DA8C(Info *, u32);

static inline Range *find(Range *tbl, s32 n, u32 addr) {
    s32 lo = 0;
    s32 hi = n;

    while (lo <= hi) {
        s32 mid = (lo + hi) >> 1;
        Range *r = &tbl[mid];

        if (addr < r->unk0) {
            hi = mid - 1;
        } else if (r->unk0 + (r->unk4 & ~1) < addr) {
            lo = mid + 1;
        } else {
            return r;
        }
    }
    return 0;
}

void func_0890D7BC(u32 arg0, Info *arg1) {
    u32 a;
    u32 b;
    u32 c;
    Range *r;
    u32 addr;
    u32 off;
    u32 acc;
    s32 p;

    arg1->unk4 = 0;
    arg1->unk8 = 0;
    if (func_0890DA8C(arg1, arg0) != 0) {
        addr = arg0 & ~1;
        r = find(arg1->unkC, (arg1->unk10 - arg1->unkC) - 1, addr);
        if (r != 0) {
            if (r->unk4 & 1) {
                arg1->unk4 = (u32) &r->unk8;
            } else {
                arg1->unk4 = r->unk8;
            }
            arg1->unk0 = r->unk0;
            off = addr - r->unk0;
            p = func_0890DA3C(arg1->unk4);
            acc = 0;
            do {
                p = func_0890C3F4(p, (s32 *) &a);
                if (a == 0) {
                    return;
                }
                p = func_0890C3F4(p, (s32 *) &b);
                p = func_0890C3F4(p, (s32 *) &c);
                acc += a;
                if (off < acc) {
                    return;
                }
                acc += b;
            } while (off > acc);
            arg1->unk8 = arg1->unk4 + c;
        }
    }
}