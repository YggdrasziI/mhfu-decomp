/* unit_088AE988: 0x088AE988-0x088AEB80 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AE894 and unit_088AEB80.
 *
 * Keeps a copy of the 20-byte header arg0 at D_09A20602 and its fields
 * (big-endian 16-bit values) in globals, then dispatches it on its kind
 * (byte 0) and type (byte 1): through the handler table of func_088AEB80,
 * or as request func_088AEE04.
 *
 * The header comes in as `void *` and is read through a `u8 *` local
 * declared after `code`: arg0 then lands in $s0 and code in $s1 (with
 * a `u8 *` parameter the two saved registers are swapped). The empty `if`
 * of the kind-2 case is `return;` (without it the test is dropped).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char D_09A20602[];
extern char D_09A202C0[];
extern u8 D_09A202E8;
extern u16 D_09A202DE;
extern u16 D_09A202DC;
extern u16 D_09A202E6;
extern s8 D_09A202E4;
extern u16 D_09A202E0[2];
extern u8 D_09A1FDE0;

extern void memcpy(void *, void *, s32);
extern s32 func_088AEB80(u16, u8);
extern void func_088AEE04(char *, u16);
extern void func_088B7E74(u16);
extern s32 func_088B6E14(u16, u16);

void func_088AE988(void *arg0) {
    u16 code;
    u8 *hdr = arg0;

    memcpy(D_09A20602, hdr, 0x14);
    D_09A202E8 = hdr[0];
    D_09A202DE = hdr[1];
    code = (u16) (hdr[2] << 8) | hdr[3];
    D_09A202DC = code;
    D_09A202E6 = hdr[8] << 8;
    D_09A202E6 |= hdr[9];
    if (!(D_09A202E6 & 0x8000)) {
        D_09A202E4 = 0;
    } else {
        D_09A202E4 = -1;
    }
    D_09A202E0[0] = hdr[6] << 8;
    D_09A202E0[0] |= hdr[7];
    D_09A202E0[1] = hdr[4] << 8;
    D_09A202E0[1] |= hdr[5];
    if (D_09A1FDE0 == 2) {
        if (hdr[0] == 2) {
            if (hdr[1] == 0x10) {
                if (func_088AEB80(code, hdr[1])) {
                    return;
                }
            }
        } else if (hdr[1] == 1) {
            func_088AEE04(D_09A202C0, code);
        }
    } else if (hdr[1] == 0x10 || hdr[1] == 1) {
        if (func_088AEB80(code, hdr[1])) {
            func_088B7E74(code);
        }
    } else if (hdr[1] == 2) {
        if (!func_088B6E14(code, D_09A202E0[0])) {
            if (func_088AEB80(code, hdr[1])) {
                func_088B7E74(code);
            }
        }
    }
}
