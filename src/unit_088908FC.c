/* unit_088908FC: 0x088908FC-0x08890B38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. Sets up three tables through
 * func_08811E18, copies D_08931ABC into them, fills six buffer pointers and
 * calls the initialisers of the record.
 *
 * func_08894B00 reads three arguments, but the original call sets only $a0:
 * it is declared without a prototype and called with one argument. arg1 and
 * arg2 are not used (the callers pass three arguments).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_089CBBE0;
extern const u16 D_08931ABC[];
extern void func_08811E18(s32, s32, s32, s32, s32, s32, s32);
extern void func_08890B38(char *);
extern void func_08890BBC(char *);
extern void func_08890CE0(char *);
extern void func_08894B00();

void func_088908FC(char *arg0, u8 arg1, s32 arg2) {
    const u16 *src;
    u16 *dst;
    s32 i;
    char *p;

    func_08811E18(D_089CBBE0, 3, 0x100, 0x100, 4, 0, -1);
    func_08811E18(D_089CBBE0, 4, 0x100, 0x100, 4, 0, -1);
    func_08811E18(D_089CBBE0, 5, 0x100, 0x100, 4, 0, -1);
    p = (char *)D_089CBBE0;
    *(u16 *)(p + 0x5C) = 2;
    src = D_08931ABC;
    dst = *(u16 **)(p + 0x58);
    for (i = 0; i < 0x40; i++) {
        *dst++ = *src++;
    }
    p = (char *)D_089CBBE0;
    *(u16 *)(p + 0x74) = 2;
    src = D_08931ABC;
    dst = *(u16 **)(p + 0x70);
    for (i = 0; i < 0x40; i++) {
        *dst++ = *src++;
    }
    p = (char *)D_089CBBE0;
    *(u16 *)(p + 0x8C) = 2;
    src = D_08931ABC;
    dst = *(u16 **)(p + 0x88);
    for (i = 0; i < 0x40; i++) {
        *dst++ = *src++;
    }
    *(char **)(arg0 + 0x140) = arg0 + 0x228;
    *(char **)(arg0 + 0x144) = arg0 + 0x828;
    *(char **)(arg0 + 0x148) = arg0 + 0xE28;
    *(char **)(arg0 + 0x14C) = arg0 + 0x1428;
    *(char **)(arg0 + 0x150) = arg0 + 0x1A28;
    *(char **)(arg0 + 0x154) = arg0 + 0x2028;
    *(u8 *)(arg0 + 0x130) = 0;
    func_08890B38(arg0);
    func_08890BBC(arg0);
    func_08890CE0(arg0);
    func_08894B00(arg0);
}
