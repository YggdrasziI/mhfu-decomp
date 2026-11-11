/* unit_08890080: 0x08890080-0x088900A0 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_08890080(char *o, u8 v) {
    *(u16 *)(o + 0xF7A56C) = v;
    *(u16 *)(o + 0xF7A56E) = v;
}
