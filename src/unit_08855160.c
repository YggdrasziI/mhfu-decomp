/* unit_08855160: 0x08855160-0x088551F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly. Its
 * initialised array (0x0899CBC0-0x0899CBFC, in .data) is linked from this
 * unit.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 func_0884FE80(s32, s32);

s32 func_08855160(s32 arg0) {
    u16 ids[30] = {
        0x2B06, 0x2B68, 0x2B69, 0x2B6A, 0x2B6B, 0x2BD0, 0x2BD1, 0x2BD2, 0x2BD3, 0x2BDA,
        0x84D, 0x84E, 0x84F, 0x8B9, 0x8BA, 0x8BB, 0x8BC, 0xBD0, 0xBD1, 0xC33,
        0xC34, 0xC35, 0xC36, 0xC90, 0xC91, 0xC92, 0xC93, 0xC94, 0xC95, 0,
    };
    u16 *p = ids;
    s32 id = *p;

    if (id != 0) {
        do {
            if ((u8) func_0884FE80(arg0, id) == 0) {
                return 0;
            }
            p++;
            id = *p;
        } while (id != 0);
    }
    return 1;
}