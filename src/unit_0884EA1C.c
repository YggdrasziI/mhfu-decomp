/* unit_0884EA1C: 0x0884EA1C-0x0884EB00 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884EA1C: maps each byte of a buffer through the byte table
 * D_0899A018, four at a time, then XORs each word with func_0884ECAC(arg0).
 */
#pragma optimize_for_size off

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern u8 D_0899A018[];
extern s32 func_0884ECAC(char *);

void func_0884EA1C(char *arg0, u8 *buf, s32 size, u32 arg3) {
    u8 *p0 = buf;
    u8 *p1 = buf + 1;
    u8 *p2 = buf + 2;
    u8 *p3 = buf + 3;
    s32 i;

    for (i = 0; i < size; i += 4) {
        *p0 = D_0899A018[*p0];
        *p1 = D_0899A018[*p1];
        *p2 = D_0899A018[*p2];
        *p3 = D_0899A018[*p3];
        *(u32 *)p0 ^= func_0884ECAC(arg0);
        p0 += 4;
        p1 += 4;
        p2 += 4;
        p3 += 4;
    }
}
