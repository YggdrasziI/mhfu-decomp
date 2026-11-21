/* unit_08901664: 0x08901664-0x08901814 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Walks the func_08850E58(D_089CC438) * 100 records of 0xC bytes at
 * D_089CC438 + 0x548 and counts those whose byte 1 is D_089B9140[arg1]:
 * with a list D_089B9100[arg1] (D_089B9150[arg1] entries), the u16 at
 * record + 2 must equal one of the list entries; without one,
 * func_0885C83C must give at least 8. Returns 1 as soon as arg2 records
 * are counted, 0 otherwise.
 *
 * Optimized for speed: guarded loops tested at the bottom.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;
extern char *D_08A62C54;
extern u16 *D_089B9100[];
extern u8 D_089B9140[];
extern u16 D_089B9150[];

extern s16 func_08850E58(char *);
extern s32 func_0885C83C(char *, u8, u16);

s32 func_08901664(s32 arg0, s8 arg1, s8 arg2)
{
    s32 n;
    u8 key;
    u8 count;
    u8 *p;
    s32 i;
    s32 found;
    u16 *list;
    s32 j;

    n = func_08850E58(D_089CC438) * 100;
    key = D_089B9140[arg1];
    count = 0;
    p = (u8 *) (D_089CC438 + 0x548);
    for (i = 0; i < n; i++) {
        list = D_089B9100[arg1];
        found = 0;
        if (list != 0) {
            for (j = 0; j < D_089B9150[arg1]; j++) {
                if (p[1] == key && *(u16 *) (p + 2) == *list) {
                    found = 1;
                    break;
                }
                list++;
            }
            if (found) {
                count++;
                if (count >= arg2) {
                    return 1;
                }
            }
            p += 0xC;
        } else {
            if (key == p[1]) {
                if ((u8) func_0885C83C(D_08A62C54, p[1], *(u16 *) (p + 2)) >= 8) {
                    count++;
                    if (count >= arg2) {
                        return 1;
                    }
                }
            }
            p += 0xC;
        }
    }
    return 0;
}
