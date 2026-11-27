/* unit_08816508: 0x08816508-0x088165FC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08816508: encodes a code point as a UTF-8 style byte sequence. */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s32 func_088167EC(s32 arg0, u32 arg1);

void func_08816508(s32 arg0, u8 **arg1, u32 arg2) {
    u8 *p;
    u8 *end;
    u8 *q;
    u32 limit;
    s32 n;
    u8 mask;

    p = *arg1;
    if ((u8)func_088167EC(arg0, arg2) == 0) {
        arg2 = 0x3F;
    }
    if (arg2 < 0x80) {
        *p = arg2;
        end = p + 1;
    } else {
        limit = 0x800;
        n = 1;
        while (arg2 >= limit) {
            limit <<= 5;
            n++;
        }
        end = p + (n + 1);
        mask = (1 << (7 - n)) - 1;
        q = end;
        while (n--) {
            q--;
            *q = (arg2 & 0x3F) | 0x80;
            arg2 >>= 6;
        }
        q[-1] = (u8)~mask | (arg2 & (mask >> 1));
    }
    *arg1 = end;
}
