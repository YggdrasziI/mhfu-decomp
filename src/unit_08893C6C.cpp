/* unit_08893C6C: 0x08893C6C-0x08894754 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. func_08893C6C formats fmt with a va_list
 * into buf (size bytes): %d %u %x %X %o %s %c %f go through func_0880E8F0,
 * %b writes up to 32 binary digits, %N% writes N percent signs; other bytes
 * are copied, multi-byte characters as a whole (func_08816930 when mode is 1,
 * Shift-JIS lead-byte ranges otherwise). Returns the length written.
 *
 * Speed setting (unrolled digit loops). C++: the unroll guard flag of the
 * digit loops is a bool (`andi 0xFF` from the register holding 1).
 * va_arg is `*(*(T **) &ap)++`: taking the address of ap gives the frame
 * size and the saved registers.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#include "libc/stdarg.h"

extern "C" {

extern void memcpy(void *, void *, s32);
extern int func_0880E8F0(char *, char *, ...);
extern int func_0880ED70(char *, char *);
extern s32 func_0880EDF8(char *);
extern int func_0880EB4C(char *, char *);
extern s32 func_088169FC(s32, char *);
extern s32 func_08816930(s32, s32);
extern s32 D_089CBBE8;

s32 func_08893C6C(char *arg0, char *buf, s32 size, char *fmt, va_list ap, u8 mode) {
    char out[0x300];
    char spec[0x300];
    s32 pos;
    s32 cont;
    s32 c;
    s32 again;
    s32 len;
    s32 width;
    s32 k;
    s32 val;
    s32 mult;
    char *p;
    s32 ch;
    s32 mult2;

    pos = 0;
    cont = 1;
    do {
        c = *(u8 *) fmt;
        switch (c) {
        case 0:
            buf[pos] = c;
            cont = 0;
            break;
        case '%':
            out[0] = 0;
            again = 1;
            c = 1;
            do {
                ch = ((u8 *) fmt)[c];
                switch (ch) {
                case 'd':
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    func_0880E8F0(out, spec, *(*(s32 **) &ap)++);
                    again = 0;
                    break;
                case 'u':
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    func_0880E8F0(out, spec, *(*(s32 **) &ap)++);
                    again = 0;
                    break;
                case 'x':
                case 'X':
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    func_0880E8F0(out, spec, *(*(s32 **) &ap)++);
                    again = 0;
                    break;
                case 'o':
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    func_0880E8F0(out, spec, *(*(s32 **) &ap)++);
                    again = 0;
                    break;
                case 'b':
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    val = *(*(s32 **) &ap)++;
                    width = 32;
                    mult = 1;
                    if (c > 2) {
                        width = 0;
                        for (k = c - 2; k > 0; k--) {
                            width += (spec[k] - '0') * mult;
                            mult *= 10;
                        }
                        if (width > 32) {
                            width = 32;
                        }
                    }
                    for (k = 0; k < width; k++) {
                        if (val & (1 << (width - 1 - k))) {
                            out[k] = '1';
                        } else {
                            out[k] = '0';
                        }
                    }
                    out[k] = 0;
                    again = 0;
                    break;
                case 'f':
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    if ((u32) ap & 7) {
                        ap += 8 - ((u32) ap & 7);
                    }
                    ap += (((u32) ap & 7) ? 4 : 0) + 8;
                    func_0880E8F0(out, spec, *(double *) (ap - 8));
                    again = 0;
                    break;
                case 'c':
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    func_0880E8F0(out, spec, *(s8 *) (*(s32 **) &ap)++);
                    again = 0;
                    break;
                case 's':
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    func_0880E8F0(out, spec, *(char **) ((ap += 4) - 4));
                    again = 0;
                    break;
                case '%':
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    mult2 = 1;
                    width = 1;
                    if (c > 2) {
                        width = 0;
                        for (k = c - 2; k > 0; k--) {
                            width += (spec[k] - '0') * mult2;
                            mult2 *= 10;
                        }
                    }
                    for (k = 0; k < width; k++) {
                        out[k] = '%';
                    }
                    out[k] = 0;
                    again = 0;
                    break;
                case 0:
                    c++;
                    memcpy(spec, fmt, c);
                    spec[c] = 0;
                    func_0880ED70(out, spec);
                    again = 0;
                    cont = 0;
                    break;
                default:
                    if ((ch < '0' || ch > '9') && ch != '.' && ch != '-' && ch != '+' && ch != '#' && ch != ' ') {
                        c++;
                        memcpy(spec, fmt, c);
                        spec[c] = 0;
                        func_0880ED70(out, spec);
                        again = 0;
                    } else {
                        c++;
                    }
                    break;
                }
            } while (again);
            if (mode == 1) {
                len = func_088169FC(D_089CBBE8, out);
            } else {
                len = func_0880EDF8(out);
            }
            if (pos + len >= size - 1) {
                buf[pos] = 0;
                cont = 0;
            } else {
                func_0880EB4C(buf, out);
                pos += len;
                fmt += c;
            }
            break;
        default:
            if (mode == 1) {
                switch (func_08816930(D_089CBBE8, c)) {
                default:
                    buf[pos] = 0;
                    cont = 0;
                    break;
                case 1:
                    buf[pos] = c;
                    pos++;
                    break;
                case 2:
                    if (pos + 2 >= size - 1) {
                        buf[pos] = 0;
                        cont = 0;
                    } else {
                        p = buf + pos;
                        p[0] = c;
                        fmt++;
                        p[1] = *fmt;
                        pos += 2;
                    }
                    break;
                case 3:
                    if (pos + 3 >= size - 1) {
                        buf[pos] = 0;
                        cont = 0;
                    } else {
                        p = buf + pos;
                        p[0] = c;
                        p[1] = fmt[1];
                        fmt += 2;
                        p[2] = *fmt;
                        pos += 3;
                    }
                    break;
                case 4:
                    if (pos + 4 >= size - 1) {
                        buf[pos] = 0;
                        cont = 0;
                    } else {
                        p = buf + pos;
                        p[0] = c;
                        p[1] = fmt[1];
                        p[2] = fmt[2];
                        fmt += 3;
                        p[3] = *fmt;
                        pos += 4;
                    }
                    break;
                }
                fmt++;
            } else {
                if ((c >= 0x20 && c <= 0x7E) || c == 0xA) {
                    buf[pos] = c;
                    pos++;
                } else if ((c >= 0x81 && c <= 0x9F) || (c >= 0xE0 && c < 0x100)) {
                    if (pos + 2 >= size - 1) {
                        buf[pos] = 0;
                        cont = 0;
                    } else {
                        p = buf + pos;
                        p[0] = c;
                        fmt++;
                        pos += 2;
                        if ((u8) (p[1] = *fmt) == 0) {
                            cont = 0;
                        }
                    }
                } else {
                    buf[pos] = c;
                    pos++;
                }
                fmt++;
            }
            if (pos >= size - 1) {
                pos = size - 1;
                buf[pos] = 0;
                cont = 0;
            }
            break;
        }
    } while (cont);
    return pos;
}

}
