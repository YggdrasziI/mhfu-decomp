/* unit_08901924: 0x08901924-0x08901A60 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern char D_089B9168;
extern char D_09B056D0;
extern char D_09B05A18;
extern s32 D_09B22D70;
extern int func_0880EB4C(s8 *, char *);
extern char *func_09A7B790(s32, u16);

void func_08901924(s32 arg0, s8 *arg1, char *arg2) {
    u16 temp_v1;

    if (arg2 != 0) {
        *arg1 = 0;
        temp_v1 = *(u16 *)arg2;
        if (temp_v1 != 0) {
            func_0880EB4C(arg1, func_09A7B790(D_09B22D70, ((u16 *)&D_09B056D0)[temp_v1]));
        }
        if (*(u16 *)(arg2 + 2) != 0) {
            if (*(u16 *)arg2 != 0) {
                func_0880EB4C(arg1, &D_089B9168);
            }
            func_0880EB4C(arg1, func_09A7B790(D_09B22D70, ((u16 *)&D_09B05A18)[*(u16 *)(arg2 + 2)]));
        }
        if (*(u16 *)(arg2 + 4) != 0) {
            if (*(u16 *)(arg2 + 2) != 0) {
                func_0880EB4C(arg1, &D_089B9168);
            } else {
                if (*(u16 *)arg2 != 0) {
                    func_0880EB4C(arg1, &D_089B9168);
                }
            }
            func_0880EB4C(arg1, func_09A7B790(D_09B22D70, ((u16 *)&D_09B056D0)[*(u16 *)(arg2 + 4)]));
        }
    }
}
