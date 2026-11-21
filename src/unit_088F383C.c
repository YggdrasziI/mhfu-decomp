/* unit_088F383C: 0x088F383C-0x088F4210 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * .rodata 0x0893296C-0x08932990: the jump table of the switch.
 * Second part of the pad handling of the nine-entry list of func_088F368C:
 * each entry (+0xE) has its own cursor(s) and limits.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern s32 D_08A62D8C;
extern s32 D_08A62C6C;
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

#define S8(o) (*(s8 *)(arg0 + (o)))
#define SOUND(n) func_08883988(D_08A62D8C, 0, (n), 0, 0, 0, 0, 0, 0)

void func_088F383C(char *arg0, u16 arg1, char *arg2) {
    s32 col;
    s32 row;
    u32 max;
    u32 i;
    s32 v;
    s32 j;
    s32 cur;
    s32 idx;
    s32 k;

    if (*(u8 *)(arg0 + 0xA72C) == 0) {
        return;
    }
    switch (S8(0xE)) {
    case 0:
        break;
    case 1:
        max = 0;
        for (i = 0; i < 11; i++) {
            if (max < *(u16 *)(arg2 + 0x628 + i * 2)) {
                max = *(u16 *)(arg2 + 0x628 + i * 2);
            }
        }
        S8(0x1D) = 0;
        if (max > 100) {
            S8(0x1D) = 1;
        }
        if (max > 500) {
            S8(0x1D) = 2;
        }
        if (max > 1000) {
            S8(0x1D) = 3;
        }
        if (arg1 & 0x8000) {
            S8(0x10)++;
            v = S8(0x10);
            v = v < 0 ? S8(0x1D) : (v > S8(0x1D) ? 0 : v);
            S8(0x10) = v;
            if (S8(0x1D) != 0) {
                SOUND(9);
            }
        }
        break;
    case 2:
        if (S8(0x24) > 13) {
            if (arg1 & 0x10) {
                if (S8(0x23) != 0) {
                    S8(0x23)--;
                    SOUND(0x17);
                }
            } else if (arg1 & 0x40) {
                if (S8(0x24) - 13 > S8(0x23)) {
                    S8(0x23)++;
                    SOUND(0x17);
                }
            }
        }
        break;
    case 3:
        if (arg1 & 0x8000) {
            S8(0x10)++;
            SOUND(9);
        } else if (S8(0x22) != 0) {
            if (arg1 & 0x80) {
                S8(0x1E)--;
                if (S8(0x22) > 1) {
                    SOUND(0x17);
                }
            } else if (arg1 & 0x20) {
                S8(0x1E)++;
                if (S8(0x22) > 1) {
                    SOUND(0x17);
                }
            }
        }
        v = S8(0x1E);
        v = v < 0 ? S8(0x22) - 1 : (v > S8(0x22) - 1 ? 0 : v);
        S8(0x1E) = v;
        v = S8(0x10);
        v = v < 0 ? 2 : (v > 2 ? 0 : v);
        S8(0x10) = v;
        break;
    case 4:
        col = S8(0x10) % 5;
        row = S8(0x10) / 5;
        if (D_08A62C6C & 0x10) {
            row--;
            if (row < 0) {
                row = 6;
            }
            SOUND(0x17);
        } else if (D_08A62C6C & 0x40) {
            row++;
            if (row > 6) {
                row = 0;
            }
            SOUND(0x17);
        } else if (D_08A62C6C & 0x80) {
            col--;
            if (col < 0) {
                col = 4;
            }
            SOUND(0x17);
        } else if (D_08A62C6C & 0x20) {
            col++;
            if (col > 4) {
                col = 0;
            }
            SOUND(0x17);
        }
        S8(0x10) = col + row * 5;
        break;
    case 5:
        if (arg1 & 0x8000) {
            S8(0xF)++;
            v = S8(0xF);
            v = v < 0 ? 1 : (v > 1 ? 0 : v);
            S8(0xF) = v;
            SOUND(9);
        } else {
            col = S8(0x10) % 8;
            row = S8(0x10) / 8;
            if (D_08A62C6C & 0x10) {
                row--;
                if (row < 0) {
                    row = 2;
                }
                SOUND(0x17);
            } else if (D_08A62C6C & 0x40) {
                row++;
                if (row > 2) {
                    row = 0;
                }
                SOUND(0x17);
            } else if (D_08A62C6C & 0x80) {
                col--;
                if (col < 0) {
                    col = 7;
                }
                SOUND(0x17);
            } else if (D_08A62C6C & 0x20) {
                col++;
                if (col > 7) {
                    col = 0;
                }
                SOUND(0x17);
            }
            S8(0x10) = col + row * 8;
        }
        break;
    case 6:
        if (S8(0x1F) > 1 && (arg1 & 0x8000)) {
            S8(0x10)++;
            v = S8(0x10);
            v = v < 0 ? S8(0x1F) - 1 : (v > S8(0x1F) - 1 ? 0 : v);
            S8(0x10) = v;
            SOUND(9);
        }
        break;
    case 7:
        if (S8(0x20) > 1 && (arg1 & 0x8000)) {
            S8(0x10)++;
            v = S8(0x10);
            v = v < 0 ? S8(0x20) - 1 : (v > S8(0x20) - 1 ? 0 : v);
            S8(0x10) = v;
            SOUND(0x17);
        }
        break;
    case 8:
        if (S8(0x21) > 1) {
            if (arg1 & 0x10) {
                S8(0x10)--;
                if (S8(0x10) < 0) {
                    S8(0x10) = 0;
                    if (S8(0x21) <= 10) {
                        break;
                    }
                    cur = S8(0xA72A);
                    for (j = 1; j < 20; j++) {
                        idx = (cur - j + 20) % 20;
                        if (*(u32 *)(arg2 + idx * 20 + 0x2AC) >> 15 != 0) {
                            S8(0xA72A) = idx;
                            break;
                        }
                    }
                }
                SOUND(0x17);
            } else if (arg1 & 0x40) {
                S8(0x10)++;
                if (S8(0x10) > 9) {
                    S8(0x10) = 9;
                    if (S8(0x21) <= 10) {
                        break;
                    }
                    cur = S8(0xA72A) + 1;
                    for (k = 1; k < 20; k++, cur++) {
                        idx = cur % 20;
                        if (*(u32 *)(arg2 + idx * 20 + 0x2AC) >> 15 != 0) {
                            S8(0xA72A) = idx;
                            break;
                        }
                    }
                } else if (S8(0x10) > S8(0x21) - 1) {
                    S8(0x10) = S8(0x21) - 1;
                    break;
                }
                SOUND(0x17);
            }
        }
        break;
    }
}
