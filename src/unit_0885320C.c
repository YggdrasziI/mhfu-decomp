/* unit_0885320C: 0x0885320C-0x088534E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CBBE8;
extern u16 *func_08816818(char *, u16 *, u16 *);
extern int func_088167F4(char *, u16 *);
extern u8 func_088534E8(void *, u16);

s32 func_0885320C(void *arg0, u16 *arg1, u16 *arg2, u16 *arg3, s32 arg4, s8 arg5) {
    s32 hit;
    u16 *prev;
    u16 *d;
    s32 n;
    s32 m;
    u16 *p;
    s32 cnt;
    s32 count;

    count = 0;
    prev = arg1;
    if ((p = func_08816818(D_089CBBE8, arg1, arg3)) != 0) do {
        switch (arg5) {
        case 0:
        default:
            n = func_088167F4(D_089CBBE8, arg3);
            hit = 1;
            break;
        case 1:
            n = func_088167F4(D_089CBBE8, arg3);
            hit = 0;
            if (p == arg1) {
                hit = 1;
            } else if (func_088534E8(arg0, p[-1]) == 1) {
                hit = 1;
            } else {
                m = func_088167F4(D_089CBBE8, prev);
                if (p + n == prev + m) {
                    hit = 1;
                } else if (func_088534E8(arg0, p[n]) == 1) {
                    hit = 1;
                }
            }
            break;
        case 2:
            n = func_088167F4(D_089CBBE8, arg3);
            cnt = 0;
            m = func_088167F4(D_089CBBE8, prev);
            hit = 0;
            if (p == arg1) {
                cnt++;
            } else if (func_088534E8(arg0, p[-1]) == 1) {
                cnt++;
            }
            if (p + n == prev + m) {
                cnt++;
            } else if (func_088534E8(arg0, p[n]) == 1) {
                cnt++;
            }
            if (cnt == 2) {
                hit = 1;
            }
            break;
        }
        if (hit != 0) {
            d = (u16 *)((char *)arg2 + (((char *)p - (char *)arg1) & ~1));
            switch (arg5) {
            case 0:
            case 1:
                while (n > 0) {
                    if (arg4 != 0) {
                        *d++ = 0xFF0A;
                    }
                    n--;
                    p++;
                }
                break;
            case 2:
                while (n > 0) {
                    if (arg4 != 0) {
                        *d++ = 0x2A;
                    }
                    n--;
                    p++;
                }
                break;
            }
            count++;
        } else {
            p++;
        }
        prev = p;
    } while ((p = func_08816818(D_089CBBE8, p, arg3)) != 0);
    return count;
}
