/* unit_0886B7C0: 0x0886B7C0-0x0886B8DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;

/* Sums seven little-endian u16 values stored unaligned at 0x11D..0x12A into
 * the u16 at 0x132; 0 becomes 0x1C3. */
void func_0886B7C0(char *arg0) {
    u16 t;

    *(u16 *)(arg0 + 0x132) = 0;
    *(u16 *)(arg0 + 0x132) += (u16)(*(u8 *)(arg0 + 0x11D) + (u16)(*(u8 *)(arg0 + 0x11E) << 8));
    t = *(u8 *)(arg0 + 0x11F);
    t += (u16)(*(u8 *)(arg0 + 0x120) << 8);
    *(u16 *)(arg0 + 0x132) += t;
    t = *(u8 *)(arg0 + 0x121);
    t += (u16)(*(u8 *)(arg0 + 0x122) << 8);
    *(u16 *)(arg0 + 0x132) += t;
    t = *(u8 *)(arg0 + 0x123);
    t += (u16)(*(u8 *)(arg0 + 0x124) << 8);
    *(u16 *)(arg0 + 0x132) += t;
    t = *(u8 *)(arg0 + 0x125);
    t += (u16)(*(u8 *)(arg0 + 0x126) << 8);
    *(u16 *)(arg0 + 0x132) += t;
    t = *(u8 *)(arg0 + 0x127);
    t += (u16)(*(u8 *)(arg0 + 0x128) << 8);
    *(u16 *)(arg0 + 0x132) += t;
    t = *(u8 *)(arg0 + 0x129);
    t += (u16)(*(u8 *)(arg0 + 0x12A) << 8);
    *(u16 *)(arg0 + 0x132) += t;
    if (*(u16 *)(arg0 + 0x132) == 0) {
        *(u16 *)(arg0 + 0x132) = 0x1C3;
    }
}
