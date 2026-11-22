/* unit_088718F4: 0x088718F4-0x08871B34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_09C121B0;
extern char *D_089CC438;
extern s32 D_09A4F0D0;

extern s32 func_0887184C(char *, u8);
extern char *func_0886DD3C(char *, char *);
extern void func_09AF4050(char *);
extern void func_0886AB7C(char *, char *);
extern void func_08871B34(char *, char *);
extern void func_09AB2E68(char *, s32);
extern void func_0886D2E4(char *, u16);
extern void func_09AB46A8(char *, u8);
extern void func_088DE3D4(s32, u32);
extern s32 *func_088697D4(char *, u16, s32, s8);

void func_088718F4(char *arg0) {
    s32 i;
    char *obj;
    char *p;
    s32 *list;

    for (i = 0; i < 20; i++) {
        {
            char *base = D_09C121B0;
            if (i < 0 || i >= 20) {
                obj = 0;
            } else {
                obj = *(char **)(i * 4 + base + 0x1220);
            }
        }
        if (obj == 0) {
            continue;
        }
        if (func_0887184C(arg0, *(u8 *)(obj + 0x1E8)) == 0) {
            continue;
        }
        p = func_0886DD3C(arg0, obj);
        if (p != 0 && *(s16 *)(p + 0x2E) != 1) {
            if (*(u8 *)(obj + 0x1E8) == 0x17) {
                func_09AF4050(obj);
            }
            if (*(u8 *)(obj + 0x1D4) >= 2 || *(u8 *)(obj + 0x298) == 5) {
                func_0886AB7C(arg0, obj);
                if (*(s16 *)(p + 0x2E) & 4) {
                    *(s16 *)(p + 0x2E) = 2;
                    *(s16 *)(p + 0x32) = -1;
                }
            } else {
                *(s16 *)(p + 0x32) = *(s16 *)(obj + 0x2E4);
            }
            *(s8 *)(p + 0x34) = -1;
        }
        func_08871B34(arg0, obj);
        func_09AB2E68(D_09C121B0, i);
    }
    func_0886D2E4(arg0, *(u16 *)(D_089CC438 + 0x6AF0E));
    func_09AB46A8(D_09C121B0, 0x12);
    func_09AB46A8(D_09C121B0, 0xA);
    func_09AB46A8(D_09C121B0, 0x4A);
    func_088DE3D4(D_09A4F0D0, 0x12);
    func_088DE3D4(D_09A4F0D0, 0xA);
    func_088DE3D4(D_09A4F0D0, 0x4A);
    list = func_088697D4(arg0, *(u16 *)(D_089CC438 + 0x6AF0E), 0, *(s8 *)(arg0 + 0x82));
    if (list == 0) {
        return;
    }
    while (*list != -1) {
        func_09AB46A8(D_09C121B0, *list);
        func_088DE3D4(D_09A4F0D0, *(u8 *)list);
        list++;
    }
}
