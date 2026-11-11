/* unit_088B0044: 0x088B0044-0x088B0084 (ULES01213)
 *
 * Bounds (hypothesis): one function (appends a big-endian 32-bit value to a buffer) between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 unk0;
    u16 pos;
} Buf;

void func_088B0044(Buf *b, u32 v) {
    u8 *p = (u8 *)b + b->pos;

    p[0x18] = v >> 24;
    p[0x19] = v >> 16;
    p[0x1A] = v >> 8;
    p[0x1B] = v;
    b->unk0 += 4;
    b->pos += 4;
}
