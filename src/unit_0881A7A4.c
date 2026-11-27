/* unit_0881A7A4: 0x0881A7A4-0x0881A8E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881A7A4: draws two sprites selected by a value against a range. */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Range {
    u8 unk0[4];
    s16 lo;
    s16 mid;
    s16 hi;
} Range;

extern s32 func_0882A9DC(char *, u16, u16, s32);

s16 func_0881A7A4(char *a, Range *r, s32 x, s32 y, s16 v)
{
    u8 b;

    if (v == 0 || (r->hi < v && v < r->lo)) {
        return 0;
    }
    if (r->hi >= v || v >= r->mid) {
        b = 1;
    } else {
        b = 0;
    }
    if (b == 0) {
        func_0882A9DC(a, x, y, 0x1F);
        func_0882A9DC(a, (s16)x + 5, (s16)y + 4, 0x1A5);
    } else {
        func_0882A9DC(a, x, y, 0x20);
        func_0882A9DC(a, (s16)x + 5, (s16)y + 4, v <= r->hi ? 0x1A4 : 0x1A5);
    }
    return b + 1;
}
