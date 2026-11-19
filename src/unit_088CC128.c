/* unit_088CC128: 0x088CC128-0x088CC190 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088CC128 asm piece, 1 function
 * between unit_088CC0E4 and unit_088CC190.
 *
 * Copies three 4-byte values from a stream into the object (0x450, 0x448,
 * 0x44C) and returns the stream position after them.
 */

typedef int s32;

extern void func_0880C084(void *, void *, s32);

char *func_088CC128(char *arg0, char *arg1) {
    s32 *p = (s32 *) arg1;

    func_0880C084(arg0 + 0x450, p++, 4);
    func_0880C084(arg0 + 0x448, p++, 4);
    func_0880C084(arg0 + 0x44C, p++, 4);
    return (char *) p;
}
