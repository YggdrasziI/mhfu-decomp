/* unit_0886171C: 0x0886171C-0x08861C7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886171C: 0x0886171C-0x08861C7C (ULES01213)
 *
 * Speed setting: the loop is guarded and tested at the bottom.
 * `prev = -1` sits before the last call so that it shares the saved register
 * of the masked fourth argument. The u8 index is compared with -1 (never true
 * in C, but the original compares with -1, not 0xFF).
 * try_unit.py scores 99.83 % only because the split piece has no %hi/%lo
 * relocations for the spilled `lui` of D_089CC000; the linked bytes are
 * identical (BOOT.BIN checksum).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern u32 *D_089CC000;
extern char *func_0886272C(char *, s32);
extern s32 func_08862E54(char *, s32);
extern void func_08862E64(s32);
extern s32 func_08862748(char *, s32);
extern u8 *func_08862768(char *, s32, s32);
extern char *func_088627B4(char *, s32, s32);

void func_0886171C(char *arg0, s32 arg1, char *arg2, s32 arg3) {
    char *s2;
    char *hdr;
    u8 *tbl;
    char *p;
    s32 i;
    s32 prev;
    u8 id;
    u8 *mat;
    u32 *tex;
    u32 addr;

    arg3 &= 0xFF;
    s2 = *(char **)arg0;
    hdr = func_0886272C(s2, arg3);
    func_08862E64(func_08862E54(arg0, arg3));
    *D_089CC000 = (*(u32 *)(hdr + 0) >> 8) | 0x48000000;
    D_089CC000++;
    *D_089CC000 = (*(u32 *)(hdr + 4) >> 8) | 0x49000000;
    D_089CC000++;
    func_08862748(s2, arg3);
    tbl = func_08862768(s2, arg3, 0);
    prev = -1;
    p = func_088627B4(s2, arg3, 0);
    for (i = 0; i < *(u16 *)(hdr + 0x14); i++, p += 0x10) {
        id = tbl[*(s8 *)p];
        if (id != -1) {
            mat = (u8 *)(*(char **)(arg0 + 8) + id * 16);
            if (mat[3] == 0) {
                continue;
            }
            *D_089CC000 = 0x53000003;
            D_089CC000++;
            *D_089CC000 = (mat[2] << 16) | 0x56000000 | (mat[1] << 8) | mat[0];
            D_089CC000++;
            *D_089CC000 = mat[3] | 0x58000000;
            D_089CC000++;
            *D_089CC000 = (mat[6] << 16) | 0x55000000 | (mat[5] << 8) | mat[4];
            D_089CC000++;
            if (mat[8] != 0xFF) {
                if (mat[8] != prev) {
                    tex = (u32 *)(*(char **)(arg2 + 4) + mat[8] * 32);
                    *D_089CC000 = 0x1E000001;
                    D_089CC000++;
                    *D_089CC000 = 0xC2000001;
                    D_089CC000++;
                    *D_089CC000 = tex[0];
                    D_089CC000++;
                    *D_089CC000 = tex[1];
                    D_089CC000++;
                    *D_089CC000 = tex[2];
                    D_089CC000++;
                    *D_089CC000 = tex[3];
                    D_089CC000++;
                    *D_089CC000 = tex[4];
                    D_089CC000++;
                    *D_089CC000 = tex[5];
                    D_089CC000++;
                    *D_089CC000 = tex[6];
                    D_089CC000++;
                    *D_089CC000 = tex[7];
                    D_089CC000++;
                    *D_089CC000 = 0xCB000000;
                    D_089CC000++;
                    prev = mat[8];
                }
            } else {
                *D_089CC000 = 0x1E000000;
                D_089CC000++;
                prev = mat[8];
            }
        }
        addr = *(s32 *)(arg0 + 4) + *(s32 *)(p + 4);
        *D_089CC000 = ((addr & 0xFF000000) >> 8) | 0x10000000;
        D_089CC000++;
        *D_089CC000 = 0x13000000;
        D_089CC000++;
        *D_089CC000 = (addr & 0xFFFFFF) | 0x0A000000;
        D_089CC000++;
    }
    *D_089CC000 = 0x27000000;
    D_089CC000++;
}
