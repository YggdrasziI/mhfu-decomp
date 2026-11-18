/* unit_088B0010: 0x088B0010-0x088B0044 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AFFD0 and unit_088B0044.
 *
 * Appends a big-endian 16-bit value to a buffer (as func_088B0044 does
 * for 32 bits). The value is an `s32` narrowed in the body: a `u16`
 * parameter extends it into another register.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 unk0;
    u16 pos;
} Buf;

void func_088B0010(Buf *b, s32 v) {
    u8 *p = (u8 *)b + b->pos;

    v = (u16) v;
    p[0x18] = v >> 8;
    p[0x19] = v;
    b->unk0 += 2;
    b->pos += 2;
}
