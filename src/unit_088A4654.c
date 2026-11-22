/* unit_088A4654: 0x088A4654-0x088A47C4 (ULES01213) */

typedef int s32;

extern char D_09A0E980[];
extern char D_09A0E9C0[];
extern char D_09A0EA00[];
extern char D_09A0EA40[];

extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern void func_0889E8F8(s32, s32, s32, char *, s32, char *, s32, s32, s32);

char *func_088A4654(s32 arg0, char *arg1, unsigned int arg2) {
    char *buf0;
    char *buf1;
    s32 size0;
    s32 size1;
    s32 len;

    buf0 = 0;
    buf1 = 0;
    size0 = 0;
    size1 = 0;
    len = 0;
    switch (arg0) {
    case 0:
        break;
    case 0x309:
    case 1:
    case 2:
        buf0 = D_09A0EA40;
        buf1 = D_09A0EA00;
        size0 = 0x40;
        size1 = size0;
        arg2 = (arg2 < 0x40) ? arg2 : size0;
        len = arg2;
        break;
    case 0x64:
        buf0 = D_09A0E9C0;
        buf1 = D_09A0E980;
        size0 = 0x40;
        size1 = 0x20;
        arg2 = (arg2 < 0x40) ? arg2 : size0;
        len = arg2;
        break;
    case 0x65:
        break;
    }
    memset(buf0, 0xFF, size0);
    memset(buf1, 0xFF, size1);
    memcpy(buf0, arg1, len);
    func_0889E8F8(0, arg0, 0, buf0, size0, buf1, size1, 0, 0);
    return buf1;
}
