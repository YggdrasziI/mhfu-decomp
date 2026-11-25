/* unit_088474DC: 0x088474DC-0x088476F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088474DC (ULES01213), 0x088474DC-0x088476F4. */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A8;
extern u8 D_0899D198[][24];
extern char D_0893B650[];
extern char D_0893B6F4[];
extern u16 D_0893B6F2;
extern u16 D_089AC848;

extern u8 *func_08856884(char *, s32);
extern void func_08890E38(char *, s8);
extern char *func_08851528(char *, u16);
extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern s32 func_08890E48(char *, char *);
extern void func_08891474(char *, s16, s32, char *, ...);

s32 func_088474DC(char *arg0, s32 arg1, s32 arg2) {
    char buf[0x20];
    char *obj;
    u8 *ent;
    u8 cnt;
    u8 key;
    u16 id;
    u8 ofs;
    s32 v;
    s32 w;

    obj = *(char **)(arg0 + 0x530);
    key = arg1;
    ofs = 0;
    if (key == 0xFF) {
        return 0;
    }
    id = *(u16 *)func_08856884(D_089CC438, key);
    ent = D_0899D198[id];
    if (!(ent[1] & 6)) {
        return 0;
    }
    cnt = func_08856884(D_089CC438, key)[2];
    if (cnt == 0) {
        return 0;
    }
    if (*(u8 *)(obj + 0x1E8) != 10) {
        if (ent[8] != *(u8 *)(obj + 0x689)) {
            v = 5;
        } else {
            v = 0;
        }
    } else {
        if (key == *(u8 *)(obj + 0x5F6)) {
            v = 5;
        } else {
            v = 0;
        }
    }
    func_08890E38(D_08A631A8, v);
    if (id == 0x80) {
        func_0880E8F0(buf, D_0893B650, func_08851528(D_089CC438, id));
        ofs = 4;
    } else if (ent[3] == 0xFF) {
        char *fmt = func_0885151C(D_089CC438, D_089AC848);
        func_0880E8F0(buf, fmt, func_08851528(D_089CC438, id));
    } else {
        func_0880E8F0(buf, D_0893B6F4, func_08851528(D_089CC438, id), cnt);
    }
    w = func_08890E48(D_08A631A8, buf);
    func_08891474(D_08A631A8, (s16)(u16)(D_0893B6F2 - ofs - ((w * 14) >> 2)), arg2, D_0893B650, buf);
    return 1;
}
