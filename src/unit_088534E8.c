/* unit_088534E8: 0x088534E8-0x088538B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* Character class test: a1 is a UTF-16 code unit (masked to 16 bits).
 * Two case groups (the second compared first, in reverse source order);
 * 0x20AC is the LAST label of the first group so that it compares
 * first among them, as a beql with the body store stolen.
 */

typedef int s32;
typedef unsigned short u16;

s32 func_088534E8(s32 arg0, u16 c) {
    s32 ret;

    ret = 0;
    switch (c) {
    case 0x2019:
    case 0x201D:
    case 0x3000:
    case 0x3001:
    case 0x3002:
    case 0x300C:
    case 0x300D:
    case 0x30FB:
    case 0x30FC:
    case 0xFF01:
    case 0xFF03:
    case 0xFF04:
    case 0xFF05:
    case 0xFF06:
    case 0xFF08:
    case 0xFF09:
    case 0xFF0A:
    case 0xFF0B:
    case 0xFF0C:
    case 0xFF0E:
    case 0xFF0D:
    case 0xFF0F:
    case 0xFF10:
    case 0xFF11:
    case 0xFF12:
    case 0xFF13:
    case 0xFF14:
    case 0xFF15:
    case 0xFF16:
    case 0xFF17:
    case 0xFF18:
    case 0xFF19:
    case 0xFF1A:
    case 0xFF1B:
    case 0xFF1C:
    case 0xFF1D:
    case 0xFF1E:
    case 0xFF1F:
    case 0xFF20:
    case 0xFF3B:
    case 0xFF3C:
    case 0xFF3D:
    case 0xFF3E:
    case 0xFF3F:
    case 0xFF40:
    case 0xFF5B:
    case 0xFF5C:
    case 0xFF5D:
    case 0xFF5E:
    case 0xFFE5:
    case 0xA2:
    case 0xA3:
    case 0xA4:
    case 0xA5:
    case 0xA7:
    case 0xD7:
    case 0xF7:
    case 0x20AC:
        ret = 1;
        break;
    case 0xA1:
    case 0xA6:
    case 0xAA:
    case 0xAB:
    case 0xB0:
    case 0xB4:
    case 0xB5:
    case 0xBB:
    case 0xBF:
    case 0x2018:
    case 0x201A:
    case 0x201C:
    case 0x201E:
        ret = 1;
        break;
    }
    if (c >= 0x20 && c < 0x41) {
        ret = 1;
    }
    if (c >= 0x5B && c < 0x61) {
        ret = 1;
    }
    if (c >= 0x7B && c < 0x80) {
        ret = 1;
    }
    return ret;
}
