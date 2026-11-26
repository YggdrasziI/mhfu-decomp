/* unit_0884CBD8: 0x0884CBD8-0x0884CDBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884CBD8: 0x0884CBD8-0x0884CDBC (ULES01213)
 *
 * Inserts a node into bucket list idx (0..19), slot chosen from its depth;
 * list 7 is kept sorted by depth. Pointer locals np/lp force the reloads
 * the original does after the stores.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;

typedef struct Node {
    s32 pad0[2];
    struct Node *next;
    f32 z;
} Node;

extern char *D_089CBBE4;
extern s8 D_0893B7BC[];

s32 func_0884CBD8(char *arg0, s32 arg1, Node *arg2, f32 *arg3, s32 arg4) {
    s32 i = (u8)arg1;
    f32 d;
    f32 t;
    u8 idx;
    s32 k;
    Node *p;
    Node *prev;
    s8 *np;
    Node ***lp;

    if (i < 0 || i >= 20) {
        return 0;
    }
    arg2->next = 0;
    t = arg3[0] * *(f32 *)(D_089CBBE4 + 0xB88) + arg3[1] * *(f32 *)(D_089CBBE4 + 0xB98)
         + arg3[2] * *(f32 *)(D_089CBBE4 + 0xBA8) + *(f32 *)(D_089CBBE4 + 0xBB8);
    d = t;
    d *= -1.0f;
    if (d < 0.0f) {
        if ((arg4 & 0xFF) == 1) {
            d = 0.0f;
        } else if (d < -1600.0f) {
            return 0;
        } else {
            d = 0.0f;
        }
    }
    idx = (u8)arg1;
    arg2->z = d;
    t = (d - *(f32 *)(D_089CBBE4 + 0)) / (*(f32 *)(D_089CBBE4 + 4) - *(f32 *)(D_089CBBE4 + 0));
    np = &D_0893B7BC[idx];
    k = (s32)(*np * t);
    if (k >= *np) {
        return 0;
    }
    lp = (Node ***)((char *)(idx * 4) + (s32)arg0 + 0x1BC);
    p = (*lp)[*np - 1 - k];
    if (i == 7) {
        prev = 0;
        if (p != 0) {
            while (1) {
                if (!(!(d >= p->z))) {
                    arg2->next = p;
                    if (prev != 0) {
                        prev->next = arg2;
                    } else {
                        (*lp)[*np - 1 - k] = arg2;
                    }
                    break;
                }
                if (p->next == 0) {
                    p->next = arg2;
                    break;
                }
                prev = p;
                p = p->next;
            }
        } else {
            (*lp)[*np - 1 - k] = arg2;
        }
    } else {
        arg2->next = p;
        (*lp)[*np - 1 - k] = arg2;
    }
    return 1;
}
