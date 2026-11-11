/* unit_08813574: 0x08813574-0x08813594 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_08813574(u8 *o, int a, int b) {
    o[0xAAA] = 0;
    if (o[0xA80] == 0) {
        o[0xA80] = a;
        *(int *)(o + 0xA7C) = b;
    }
}
