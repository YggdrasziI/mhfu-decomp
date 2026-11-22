/* unit_0889C75C: 0x0889C75C-0x0889C788 (ULES01213)
 *
 * Sorts the 0xC8-byte records at +0x57C (count at +0xEE3) with
 * func_0889C524, using a stack swap buffer.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern void func_0889C524(s32 arg0, s32 n, u8 *base, s32 size, u8 *key, u8 *tmp);

void func_0889C75C(u8 *arg0) {
    u8 tmp[0xC8];

    func_0889C524((s32)arg0, *(s8 *)(arg0 + 0xEE3), arg0 + 0x57C, 0xC8, arg0 + 0x57C, tmp);
}
