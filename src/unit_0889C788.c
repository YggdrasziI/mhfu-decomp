/* unit_0889C788: 0x0889C788-0x0889C7B4 (ULES01213)
 *
 * Sorts the records at +0x12DC (count at +0x12D8, 100 bytes each) with
 * func_0889C524, using a stack swap buffer.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern void func_0889C524(s32 arg0, s32 n, u8 *base, s32 size, u8 *key, u8 *tmp);

void func_0889C788(u8 *arg0) {
    u8 tmp[100];

    func_0889C524((s32)arg0, *(s8 *)(arg0 + 0x12D8), arg0 + 0x12DC, 100, arg0 + 0x12DC, tmp);
}
