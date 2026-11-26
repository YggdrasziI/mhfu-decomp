/* unit_08821CA8: 0x08821CA8-0x08821D48 (ULES01213) */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_0893AEB8[];
extern u8 func_08826EF4(char *, char *, u8 *);

void func_08821CA8(char *arg0, char *arg1) {
    s32 i;
    char *e;
    u16 *p;

    for (i = 0; i < 5; i++) {
        e = arg1 + D_0893AEB8[i] * 12;
        p = (u16 *)(e + 0x4F6);
        if (*p != 0) {
            if (func_08826EF4(arg0, arg1, (u8 *)(e + 0x4F4)) == 0) {
                *p = 0;
            }
        }
    }
}
