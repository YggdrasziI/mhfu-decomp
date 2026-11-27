/* unit_0890D4C4: 0x0890D4C4-0x0890D7BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890D4C4: steps the record pointer at offset 8 past one action record
 * (code in the low 5 bits of its first byte) without running it; when the
 * pointer is null or the record has bit 0x80 set, the next frame is fetched
 * through func_0890DC24 / func_0890D7BC / func_0890DB88 instead. Then skips
 * the code-1 records that follow and returns the code of the current record.
 * Derived from the assembly only.
 *
 * Size setting (default). Owns the jump table jtbl_0893325C (0x0893325C,
 * 16 words, 0x40 bytes); codes 0, 1 and 14 share the default (func_0890C224).
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 unk0;
    u32 unk4;
    u8 *unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u8 unk18[1];
} Iter;

extern u8 *func_0890C490(u8 *, s32 *);
extern u8 *func_0890C3F4(u8 *, s32 *);
extern u32 func_0890DC24(void *, Iter *);
extern void func_0890D7BC(u32, Iter *);
extern void func_0890C224(void);
extern void func_0890DB88(void *, Iter *);

s32 func_0890D4C4(Iter *it) {
    void *ctx = it->unk18;
    u8 *a;
    u8 *q;

    for (;;) {
        a = it->unk8;
        if (((a != 0) ^ 1) || (*a & 0x80)) {
            func_0890D7BC(func_0890DC24(ctx, it), it);
            if (it->unk4 == 0) {
                func_0890C224();
            }
            func_0890DB88(ctx, it);
            if (it->unk8 == 0) {
                continue;
            }
            break;
        }
        switch (*a & 0x1F) {
        case 2: {
            s32 x0;
            it->unk8 = func_0890C490(a + 1, &x0) + 4;
            break;
        }
        case 3: {
            s32 x0;
            s32 x1;
            u8 *p = func_0890C490(a + 1, &x0);
            it->unk8 = func_0890C490(p, &x1) + 4;
            break;
        }
        case 4: {
            s32 x0;
            it->unk8 = func_0890C490(a + 1, &x0) + 4;
            break;
        }
        case 5: {
            s32 x0;
            s32 x1;
            s32 x2;
            u8 *p = func_0890C490(a + 1, &x0);
            p = func_0890C3F4(p, &x1);
            it->unk8 = func_0890C3F4(p, &x2) + 4;
            break;
        }
        case 6: {
            s32 x0;
            s32 x1;
            u8 *p = func_0890C490(a + 1, &x0);
            it->unk8 = func_0890C490(p, &x1) + 4;
            break;
        }
        case 7: {
            s32 x0;
            s32 x1;
            u8 *p = func_0890C490(a + 1, &x0);
            it->unk8 = func_0890C490(p, &x1) + 4;
            break;
        }
        case 8: {
            s32 x0;
            s32 x1;
            s32 x2;
            u8 *p = func_0890C490(a + 1, &x0);
            p = func_0890C490(p, &x1);
            it->unk8 = func_0890C490(p, &x2) + 4;
            break;
        }
        case 9: {
            s32 x0;
            s32 x1;
            s32 x2;
            s32 x3;
            u8 *p = func_0890C490(a + 1, &x0);
            p = func_0890C490(p, &x1);
            p = func_0890C3F4(p, &x2);
            it->unk8 = func_0890C3F4(p, &x3) + 4;
            break;
        }
        case 10: {
            s32 x0;
            it->unk8 = func_0890C490(a + 1, &x0) + 4;
            break;
        }
        case 11: {
            s32 x0;
            s32 x1;
            u8 *p = func_0890C490(a + 1, &x0);
            it->unk8 = func_0890C490(p, &x1) + 4;
            break;
        }
        case 12: {
            s32 x0[2];
            s32 x1;
            u8 *p = func_0890C3F4(a + 5, x0);
            it->unk8 = func_0890C490(p, &x1);
            break;
        }
        case 13: {
            s32 x0;
            it->unk8 = func_0890C490(a + 1, &x0);
            break;
        }
        case 15: {
            s32 n;
            s32 x1;
            s32 x2;
            u8 *p = func_0890C3F4(a + 1, &n);
            p = func_0890C3F4(p, &x1);
            it->unk8 = func_0890C490(p, &x2) + n * 4;
            break;
        }
        default:
            func_0890C224();
            break;
        }
        break;
    }
    q = it->unk8;
    if ((*q & 0x1F) == 1) {
        do {
            s32 off;
            func_0890C490(it->unk8 + 1, &off);
            q = it->unk8 + off;
            it->unk8 = q;
        } while ((*q & 0x1F) == 1);
    }
    return *q & 0x1F;
}
