/* unit_08892708: 0x08892708-0x08892A88 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * NonMatching (99.26 %): where the count reaches the limit, the original
 * turns the 1/0 result into an if/else and sign-extends it (`seh v0, v0`)
 * in the delay slot of its own branch to the exit, which the `ret = 4` path
 * skips; ours has no `seh` there. Copies, casts, inline helpers, a switch
 * and a goto diamond were tried (they give `xori`/`sltiu`, or move the
 * `seh` to the shared exit).
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern s32 D_089CBBE8;

extern char *func_08894B0C(s32 arg0, char *arg1, s16 *arg2, s32 arg3, s32 arg4);
extern void func_08894EE4(s32 arg0, char *arg1, s16 arg2, s32 arg3);
extern s32 func_08894F7C(s32 arg0, s16 arg1, char *arg2, char **arg3, s32 arg4);
extern s32 func_08816930(s32 arg0, s32 arg1);
extern s32 func_08891B5C(s32 arg0, u8 *arg1);

s16 func_08892708(s32 arg0, s16 limit, char *dst, char *arg3, char **out) {
    char *src;
    char *save;
    s16 ret;
    char buf[0x300];
    s16 code;
    s32 n;
    s16 r;
    s16 cur;
    char *bp;
    s32 i;
    s32 flag;
    s16 count;

    src = arg3;
    flag = 0;
    count = 0;
    while (1) {
        if (*src == 0) {
            *dst = 0;
            ret = 4;
            break;
        }
        if (*src == '~') {
            save = src;
            src = func_08894B0C(arg0, src, &code, 0, 1);
            if ((code & 0xFF00) == 0x800) {
                flag ^= 1;
                continue;
            }
            src = save;
            if (flag == 0) {
                src = func_08894B0C(arg0, src, &code, 2, 1);
                cur = count;
                if (limit < cur + code) {
                    func_08894B0C(arg0, save, &code, 0, 1);
                    switch (code & 0xFF00) {
                    case 0:
                        func_08894B0C(arg0, save, &code, 2, 1);
                        if (code == 0) {
                            continue;
                        }
                        dst[0] = '~';
                        dst[1] = 0;
                        *out = src;
                        return 0;
                    case 0x100:
                        continue;
                    case 0x200:
                        bp = buf;
                        func_08894EE4(arg0, buf, code & 0xFF, 1);
                        r = func_08894F7C(arg0, limit - cur, dst, &bp, 1);
                        *out = bp;
                        return r;
                    case 0x400:
                        dst[0] = code;
                        dst[1] = 0;
                        *out = src;
                        return 2;
                    }
                }
                count += code;
                continue;
            }
        }
        n = func_08816930(D_089CBBE8, *(u8 *) src);
        if (count == limit) {
            r = func_08891B5C(arg0, (u8 *) src);
            for (i = 0; i < n; i++) {
                *dst++ = *src++;
            }
            *dst = 0;
            if (r == 2) {
                ret = 1;
            } else {
                ret = 0;
            }
            break;
        }
        for (i = 0; i < n; i++) {
            src++;
        }
        count++;
    }
    *out = src;
    return ret;
}
