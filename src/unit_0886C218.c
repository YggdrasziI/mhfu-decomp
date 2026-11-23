/* unit_0886C218: 0x0886C218-0x0886C59C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    s8 count;
    u8 pad;
} Slot;

typedef struct {
    char pad0[0x6C];
    Slot slot[5];
    s8 next;
    s8 active;
} Box;

extern char *D_08A631A0;
extern char *D_089CC438;
extern char *D_089CBBEC;
extern s8 D_089A77BC[];
extern u16 func_088900C4(char *, s32);
extern s32 func_088D6A54(char *, u8);
extern u16 func_088D72A4(char *, u16, s16, s32);
extern u8 func_08830728(char *, s8, s16, s16);

static inline u8 is_local(char *p) {
    return *(u16 *)(p + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

void func_0886C218(Box *arg0, char *arg1) {
    s32 i;
    s32 found;
    s32 kind;

    found = 0;
    if (arg0->active != 0) {
        kind = D_089A77BC[func_088900C4(D_08A631A0, 0) & 7];
        if ((u8)func_088D6A54(arg1, 3) == 1) {
            kind = 0;
        }
        switch (kind) {
        default:
            for (i = 0; i < 5; i++) {
                if (arg0->slot[i].id != 0) {
                    switch (func_088D72A4(arg1, arg0->slot[i].id, arg0->slot[i].count, 0)) {
                    case 0:
                    case 1:
                    case 2:
                        if (is_local(arg1) == 1) {
                            func_08830728(D_089CBBEC, 1, 0, arg0->slot[i].id);
                        }
                        found = 1;
                        break;
                    case 3:
                        if (is_local(arg1) == 1) {
                            func_08830728(D_089CBBEC, 1, 3, arg0->slot[i].id);
                        }
                        found = 1;
                        break;
                    }
                }
            }
            if (found == 0) {
                if (is_local(arg1) == 1) {
                    func_08830728(D_089CBBEC, 0, 0, 0);
                }
            }
            break;
        case 1:
            switch (func_088D72A4(arg1, 0xF6, 1, 0)) {
            case 0:
            case 1:
            case 2:
                if (is_local(arg1) == 1) {
                    func_08830728(D_089CBBEC, 1, 0, 0xF6);
                }
                break;
            case 3:
                if (is_local(arg1) == 1) {
                    func_08830728(D_089CBBEC, 1, 3, 0xF6);
                }
            default:
                if (is_local(arg1) == 1) {
                    func_08830728(D_089CBBEC, 0, 0, 0);
                }
                break;
            }
            break;
        case 2:
            if (is_local(arg1) == 1) {
                func_08830728(D_089CBBEC, 0, 0, 0);
            }
            break;
        }
        arg0->active = 0;
        for (i = 0; i < 5; i++) {
            arg0->slot[i].id = 0;
            arg0->slot[i].count = 0;
        }
        arg0->next = 0;
        arg0->active = 0;
    } else {
        if (is_local(arg1) == 1) {
            func_08830728(D_089CBBEC, 0, 0, 0);
        }
    }
}
