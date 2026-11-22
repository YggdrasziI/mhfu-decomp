/* unit_088921FC: 0x088921FC-0x08892708 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern s32 D_089CBBE8;
extern char D_089AD274[];

extern void func_0880F178(char *, char *, s32);
extern void memset(void *, s32, s32);
extern char *func_08894B0C(char *, char *, s16 *, s32, s32);
extern int func_0889134C(char *, char *, ...);
extern void func_08890DFC(char *, s16, s32);
extern void func_08890E38(char *, s8);
extern void func_08894EE4(char *, char *, s16, s32);
extern s32 func_088169FC(s32, char *);
extern void func_0880EF34(char *, char *, s32);
extern void func_08895220(char *, s16, s32, u8, s8, s16);
extern s32 func_08891B5C(char *, char *);
extern s32 func_08816930(s32, s32);

static inline void clear(char *q, u32 n) {
    if (q != 0) {
        do {
            *q++ = 0;
        } while (--n != 0);
    }
}

void func_088921FC(char *arg0, s32 arg1, char *arg2) {
    s16 code;
    char buf0[0x300];
    char buf1[0x300];
    char *bufs[2];
    s32 mode;
    char *p;
    char *save;
    char **slot;
    s32 len;
    s32 cur;
    s32 n;
    s32 i;
    s32 kind;
    s16 x;
    s32 y;
    s16 x0;

    clear((char *) bufs, 8);
    p = buf0;
    bufs[1] = buf1;
    bufs[0] = buf0;
    mode = 0;
    cur = 0;
    func_0880F178(buf0, arg2, 0x300);
    buf0[0x2FF] = 0;
    memset(buf1, 0, 0x300);
    x0 = *(s16 *) (arg0 + 0x120);
    y = *(s16 *) (arg0 + 0x122);
    len = 0;
    x = x0;
    for (;;) {
        if (*p == 0) {
            break;
        }
        if (*p == '~') {
            if (mode != 0) {
                save = p;
                p = func_08894B0C(arg0, p, &code, 0, 1);
                if ((code & 0xFF00) != 0x800) {
                    p = save;
                    goto text;
                }
                mode = 0;
                continue;
            }
            bufs[cur ^ 1][len] = 0;
            func_0889134C(arg0, D_089AD274, bufs[cur ^ 1]);
            len = 0;
            func_08890DFC(arg0, x, y);
            p = func_08894B0C(arg0, p, &code, 0, 1);
            switch (code & 0xFF00) {
            case 0:
                break;
            case 0x100:
                func_08890E38(arg0, code & 0xFF);
                continue;
            case 0x200:
                cur ^= 1;
                slot = &bufs[cur];
                func_08894EE4(arg0, *slot, code & 0xFF, 1);
                n = func_088169FC(D_089CBBE8, *slot);
                func_0880EF34(*slot, p, 0x300 - n);
                p = *slot;
                p[0x2FF] = 0;
                continue;
            case 0x400:
                func_08895220(arg0, x, y, *(u8 *) (arg0 + 0x12D), *(s8 *) (arg0 + 0x12E), code & 0xFF);
                x += *(u8 *) (arg0 + 0x12C);
                func_08890DFC(arg0, x, y);
                if ((s16) arg1 > 0) {
                    arg1 = (s16) (arg1 - 1);
                }
                if (arg1 == 0) {
                    *p = 0;
                }
                continue;
            case 0x800:
                mode = 1;
                continue;
            }
            if (*p == 0) {
                break;
            }
        }
    text:
        if (func_08891B5C(arg0, p) == 2) {
            kind = 0;
            if ((s16) arg1 > 0) {
                arg1 = (s16) (arg1 - 1);
            }
        } else if (*p == '\n') {
            kind = 2;
        } else {
            kind = 1;
            if ((s16) arg1 > 0) {
                arg1 = (s16) (arg1 - 1);
            }
        }
        n = func_08816930(D_089CBBE8, *(u8 *) p);
        if (len + n >= 0x2FF) {
            break;
        }
        for (i = 0; i < n; i++) {
            bufs[cur ^ 1][len] = *p;
            len++;
            p++;
        }
        if (len >= 0x2FF) {
            len = 0x2FF;
            break;
        }
        if (kind == 0) {
            x += *(u8 *) (arg0 + 0x12C);
        } else if (kind == 1) {
            x += (s16) ((u32) *(u8 *) (arg0 + 0x12C) >> 1);
        } else {
            y = (s16) (y + *(u8 *) (arg0 + 0x15F));
            x = x0;
            bufs[cur ^ 1][len - 1] = 0;
            func_0889134C(arg0, D_089AD274, bufs[cur ^ 1]);
            len = 0;
            func_08890DFC(arg0, x0, y);
        }
        if (arg1 == 0) {
            *p = 0;
        }
    }
    bufs[cur ^ 1][len] = 0;
    func_0889134C(arg0, D_089AD274, bufs[cur ^ 1]);
}
