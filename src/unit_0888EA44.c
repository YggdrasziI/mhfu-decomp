/* unit_0888EA44: 0x0888EA44-0x0888EAF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Copies the current values of a block at +0xA0 to their "previous" slots,
 * one bit of the mask per field.
 */

typedef short s16;
typedef int s32;

static inline void copy_q(void *src, void *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

void func_0888EA44(char *obj, s32 mask) {
    char *p = obj + 0xA0;

    if (mask & 0x1) {
        copy_q(p, p + 0x10);
    }
    if (mask & 0x2) {
        copy_q(p + 0x20, p + 0x30);
    }
    if (mask & 0x4) {
        *(s16 *)(p + 0x66) = *(s16 *)(p + 0x64);
    }
    if (mask & 0x8) {
        *(s16 *)(p + 0x6A) = *(s16 *)(p + 0x68);
    }
    if (mask & 0x10) {
        *(s16 *)(p + 0x72) = *(s16 *)(p + 0x70);
    }
    if (mask & 0x20) {
        *(s16 *)(p + 0x7A) = *(s16 *)(p + 0x78);
    }
    if (mask & 0x40) {
        *(s16 *)(p + 0x82) = *(s16 *)(p + 0x80);
    }
    if (mask & 0x80) {
        *(s16 *)(p + 0x8A) = *(s16 *)(p + 0x88);
    }
}
