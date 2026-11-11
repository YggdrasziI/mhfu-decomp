/* unit_088AB490: 0x088AB490-0x088AB4B0 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_088AB490(u8 bit, u8 *o) {
    o[0x173] |= (u8)(1 << bit);
}
