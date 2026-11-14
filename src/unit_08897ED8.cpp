/* unit_08897ED8: 0x08897ED8-0x08898350 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef short s16;
typedef int s32;
typedef struct V08_0 { virtual void vfunc_08(s32); } V08_0;

extern "C" {

extern char D_089BAAA8;
extern char D_089BABAC;
extern char D_089BAC20;
extern s32 D_089CBBE0;
extern s32 D_089CBBE4;
extern s32 D_089CBBE8;
extern s32 D_089CC434;
extern s32 D_08A62C40;
extern s32 D_08A62C50;
extern s32 D_08A62C54;
extern s32 D_08A62C60;
extern s32 D_08A62C64;
extern s32 D_08A62C7C;
extern s32 D_08A62CB4;
extern s32 D_08A631A0;
extern s32 D_08A631A8;
extern s32 D_08A8B1E8;
extern s32 D_09A0B544;
extern s32 D_09A1DAEC;
extern s32 D_09A1FDDC;
extern s32 D_09A44C60;
extern s32 D_09A4F06C;
extern char func_088129B8;
extern int func_08816B6C(s32, s32);
extern int func_0884B234(s32, s32);
extern int func_0884FA0C(s32, s32);
extern int func_08859C40(char *, char **);
extern int func_088607A8(s32, s32);
extern int func_088664A8(s32, s32);
extern int func_08880498(s32, s32);
extern int func_08898540(s32, s32);
extern int func_088DD7E8(s32, s32);
extern int func_0890BE54(s32, char *, s32, s32);
extern int func_0890BFA4(char *);

char *func_08897ED8(char *arg0, s16 arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 var_s1;
    char **temp_a0_2;
    char *temp_v0_14;
    char *var_s0;

    if (arg0 != 0) {
        temp_v0 = (int) (arg0 + 0xF7A590);
        if ((temp_v0 != 0) && (temp_v0 != 0)) {
            D_09A44C60 = 0;
        }
        func_088DD7E8((int) (arg0 + 0xF7A33C), -1);
        temp_v0_2 = (int) (arg0 + 0xF7A29C);
        if ((temp_v0_2 != 0) && (temp_v0_2 != 0)) {
            D_09A4F06C = 0;
        }
        temp_v0_3 = (int) (arg0 + 0xF7A299);
        if ((temp_v0_3 != 0) && (temp_v0_3 != 0)) {
            D_08A62C54 = 0;
        }
        temp_v0_4 = (int) (arg0 + 0xF7A298);
        if ((temp_v0_4 != 0) && (temp_v0_4 != 0)) {
            D_08A62C50 = 0;
        }
        temp_v0_5 = (int) (arg0 + 0xF7A168);
        if ((temp_v0_5 != 0) && (temp_v0_5 != 0)) {
            D_08A62CB4 = 0;
        }
        temp_v0_6 = (int) (arg0 + 0xF798C0);
        if ((temp_v0_6 != 0) && (temp_v0_6 != 0)) {
            D_08A62C7C = 0;
        }
        func_08816B6C((int) (arg0 + 0xF786A0), -1);
        func_0884FA0C((int) (arg0 + 0xF0D760), -1);
        func_088607A8((int) (arg0 + 0xF0D600), -1);
        if ((arg0 + 0xF0C830) != 0) {
            func_0890BE54((int) (arg0 + 0xF0C8E0), &func_088129B8, 0x1A0, 6);
            if ((arg0 + 0xF0C830) != 0) {
                D_089CBBE4 = 0;
            }
        }
        temp_v0_7 = (int) (arg0 + 0xF0C6B0);
        if ((temp_v0_7 != 0) && (temp_v0_7 != 0)) {
            D_09A1DAEC = 0;
        }
        temp_v0_8 = (int) (arg0 + 0xF0AB48);
        if ((temp_v0_8 != 0) && (temp_v0_8 != 0)) {
            D_09A0B544 = 0;
        }
        temp_v0_9 = (int) (arg0 + 0xF0AB38);
        if ((temp_v0_9 != 0) && (temp_v0_9 != 0)) {
            D_09A1FDDC = 0;
        }
        temp_v0_10 = (int) (arg0 + 0xF0AABC);
        if ((temp_v0_10 != 0) && (temp_v0_10 != 0)) {
            D_08A62C60 = 0;
        }
        temp_v0_11 = (int) (arg0 + 0xF0AAB8);
        if ((temp_v0_11 != 0) && (temp_v0_11 != 0)) {
            D_089CBBE8 = 0;
        }
        temp_v0_12 = (int) (arg0 + 0xEE4DC0);
        if ((temp_v0_12 != 0) && (temp_v0_12 != 0)) {
            D_08A631A8 = 0;
        }
        func_08898540((int) (arg0 + 0x6A7590), -1);
        func_0884B234((int) (arg0 + 0x6A7368), -1);
        func_088664A8((int) (arg0 + 0x626F00), -1);
        func_08880498((int) (arg0 + 0xC4A80), -1);
        temp_v0_13 = (int) (arg0 + 0xC3E00);
        if ((temp_v0_13 != 0) && (temp_v0_13 != 0)) {
            D_089CBBE0 = 0;
        }
        temp_a0 = (int) (arg0 + 0x94200);
        if (temp_a0 != 0) {
            *(char **)(arg0 + 0x94200) = &D_089BABAC;
            if (temp_a0 != 0) {
                *(char **)(arg0 + 0x94200) = &D_089BAAA8;
                if (temp_a0 != 0) {
                    *(char **)(arg0 + 0x94200) = &D_089BAC20;
                }
            }
            if ((arg0 + 0x94200) != 0) {
                D_089CC434 = 0;
            }
        }
        temp_v0_14 = arg0 + 0x941DC;
        if ((temp_v0_14 != 0) && (temp_v0_14 != 0)) {
            D_08A62C64 = 0;
        }
        if ((arg0 + 0x801A4) != 0) {
            var_s1 = 0;
            var_s0 = arg0;
            do {
                temp_a0_2 = *(char ***)(var_s0 + 0x801A4);
                if (temp_a0_2 != 0) {
                    if (temp_a0_2 != 0) {
                        ((V08_0 *) (temp_a0_2))->vfunc_08(1);
                    }
                    func_08859C40(arg0 + 0x941B4, *(char ***)(var_s0 + 0x801A4));
                    *(char ***)(var_s0 + 0x801A4) = 0;
                }
                var_s1 += 1;
                var_s0 += 4;
            } while (var_s1 < 4);
            if ((arg0 + 0x801A4) != 0) {
                D_08A8B1E8 = 0;
            }
        }
        if ((arg0 != 0) && (arg0 != 0)) {
            D_08A62C40 = 0;
        }
        if (arg0 != 0) {
            D_08A631A0 = 0;
        }
        if (arg1 > 0) {
            func_0890BFA4(arg0);
        }
    }
    return arg0;
}

}
