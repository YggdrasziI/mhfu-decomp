/* unit_08894B0C: 0x08894B0C-0x08894EE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, a text control-code parser.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern void func_08894EE4(s32 arg0, char *arg1, s16 arg2, s32 arg3);
extern s32 func_08890E48(s32 arg0, char *arg1);
extern s32 func_08890F68(s32 arg0, char *arg1);
extern s32 func_08891F1C(s32 arg0, char *arg1);
extern s32 func_08891F88(s32 arg0, char *arg1);

char *func_08894B0C(s32 arg0, char *arg1, s16 *arg2, s16 arg3, s32 arg4) {
    char buf[0x300];
    s16 n;
    s16 d;

    *arg2 = 0;
    arg1++;
    switch (*arg1) {
    case '~':
        switch (arg3) {
        case 0:
            *arg2 = 0;
            break;
        case 1:
            arg1++;
            *arg2 = -1;
            break;
        case 2:
            arg1++;
            *arg2 = 1;
            break;
        }
        break;
    case 'C':
        arg1++;
        switch (arg3) {
        case 0:
            n = 0;
            if (*arg1 >= '0' && *arg1 <= '9') {
                n = *arg1++ - '0';
                if (*arg1 >= '0' && *arg1 <= '9') {
                    d = *arg1++ - '0';
                    n = d + n * 10;
                }
            }
            *arg2 = n | 0x100;
            break;
        case 1:
            arg1 += 2;
            *arg2 = -4;
            break;
        case 2:
            *arg2 = 0;
            arg1 += 2;
            break;
        }
        break;
    case 'A':
        arg1++;
        n = 0;
        if (*arg1 >= '0' && *arg1 <= '9') {
            n = *arg1++ - '0';
            if (*arg1 >= '0' && *arg1 <= '9') {
                d = *arg1++ - '0';
                    n = d + n * 10;
            }
        }
        switch (arg3) {
        case 0:
            *arg2 = n | 0x200;
            break;
        case 1:
            func_08894EE4(arg0, buf, n, arg4);
            if ((u8)arg4 == 1) {
                *arg2 = func_08890E48(arg0, buf) - 4;
            } else {
                *arg2 = func_08890F68(arg0, buf) - 4;
            }
            break;
        case 2:
            func_08894EE4(arg0, buf, n, arg4);
            if ((u8)arg4 == 1) {
                *arg2 = func_08891F1C(arg0, buf);
            } else {
                *arg2 = func_08891F88(arg0, buf);
            }
            break;
        }
        break;
    case 'B':
        arg1++;
        switch (arg3) {
        case 0:
            n = 0;
            if (*arg1 >= '0' && *arg1 <= '9') {
                n = *arg1++ - '0';
                if (*arg1 >= '0' && *arg1 <= '9') {
                    d = *arg1++ - '0';
                    n = d + n * 10;
                }
            }
            *arg2 = n | 0x400;
            break;
        case 1:
            arg1 += 2;
            *arg2 = -2;
            break;
        case 2:
            arg1 += 2;
            *arg2 = 1;
            break;
        }
        break;
    case '%':
        arg1++;
        switch (arg3) {
        case 0:
            *arg2 = 0x800;
            break;
        case 1:
            *arg2 = -2;
            break;
        case 2:
            *arg2 = 0;
            break;
        }
        break;
    default:
        switch (arg3) {
        case 0:
            *arg2 = 0;
            break;
        case 1:
            *arg2 = -1;
            break;
        case 2:
            *arg2 = 0;
            break;
        }
        break;
    }
    return arg1;
}
