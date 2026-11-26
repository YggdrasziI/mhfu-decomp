/* unit_0883A8A4: 0x0883A8A4-0x0883AB44 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_09A0B544;
extern s32 D_08A62D8C;

extern char *func_0883B3D4(char *, s32);
extern u8 func_0883AB44(char *, char *);
extern void memcpy(void *, void *, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0881C2E4(char *, u8 *, s32, u8);
extern void func_0881C45C(char *, u8 *, s32, u8);

s32 func_0883A8A4(char *arg0, s32 arg1) {
    char *rec;
    char *g;
    char *found;
    s32 i;
    char *e;
    s32 j;
    s32 r;

    switch (*(u8 *)(arg0 + 0x57E)) {
    case 0:
        if ((u16)arg1 & 0x4000) {
            rec = func_0883B3D4(arg0, *(u8 *)(arg0 + 0x57F));
            if (func_0883AB44(arg0, rec) == 0) {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            } else {
                (*(u8 *)(arg0 + 0x57E))++;
                memcpy(arg0 + 0x1172, rec, 8);
                *(u8 *)(arg0 + 0x582) = 0;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                *(s32 *)(arg0 + 0x5E8) &= ~4;
            }
        } else {
            func_0881C2E4(arg0, (u8 *)(arg0 + 0x57F), arg1, 3);
        }
        break;
    case 1:
        g = D_09A0B544;
        for (i = 0; i < *(s8 *)(g + 0xEE3); i++) {
            e = g + i * 200 + 0x57C;
            for (j = 0; j < 6; j++) {
                if (*(u8 *)(arg0 + j + 0x1172) < *(u8 *)(e + j)) {
                    r = -1;
                    goto cmpd;
                }
                if (*(u8 *)(e + j) < *(u8 *)(arg0 + j + 0x1172)) {
                    r = 1;
                    goto cmpd;
                }
            }
            r = 0;
        cmpd:
            if (r == 0) {
                found = g + i * 200 + 0x57C;
                goto done;
            }
        }
        found = 0;
    done:
        if (func_0883AB44(arg0, found) == 0) {
            (*(u8 *)(arg0 + 0x57E))--;
            arg1 = (u16)(arg1 & 0xDFFF);
            *(s32 *)(arg0 + 0x5E8) |= 4;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if ((u16)arg1 & 0x2000) {
            (*(u8 *)(arg0 + 0x57E))--;
            arg1 = (u16)(arg1 & 0xDFFF);
            *(s32 *)(arg0 + 0x5E8) |= 4;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else {
            func_0881C45C(arg0, (u8 *)(arg0 + 0x582), arg1, 2);
        }
        break;
    }
    return arg1;
}
