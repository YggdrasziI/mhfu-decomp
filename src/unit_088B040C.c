/* unit_088B040C: 0x088B040C-0x088B047C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B03CC and unit_088B047C.
 *
 * Reads a field made of a big-endian 16-bit length and its bytes from
 * arg2: copies at most arg1 bytes of it to arg0 and returns the address
 * after the field.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern void memcpy(void *, void *, s32);

u8 *func_088B040C(char *arg0, u16 arg1, u8 *arg2) {
    u16 len;
    s32 n;

    len = (u16) (arg2[0] << 8) | arg2[1];
    n = len;
    if (arg1 < len) {
        n = arg1;
    }
    if (n != 0) {
        memcpy(arg0, arg2 + 2, (u16) n);
    }
    return arg2 + (len + 2);
}
