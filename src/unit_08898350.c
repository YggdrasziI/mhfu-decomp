/* unit_08898350: 0x08898350-0x0889842C (ULES01213)
 *
 * Bounds (hypothesis): a run of setters that store their argument in a global
 * pointer and return it (some also clear one byte of the object); the function
 * before is unrelated, the one after (func_0889842C) is larger and stays in
 * assembly for now.
 */

extern char *D_089CBBE0;
extern char *D_089CBBE8;
extern char *D_08A62C50;
extern char *D_08A62C54;
extern char *D_08A62C60;
extern char *D_08A62C7C;
extern char *D_08A62CB4;
extern char *D_08A631A8;
extern char *D_09A0B544;
extern char *D_09A1DAEC;
extern char *D_09A1FDDC;
extern char *D_09A44C60;
extern char *D_09A4F06C;

char *func_08898350(char *p) {
    D_09A44C60 = p;
    return p;
}

char *func_08898360(char *p) {
    D_09A4F06C = p;
    return p;
}

char *func_08898370(char *p) {
    D_08A62C54 = p;
    return p;
}

char *func_08898380(char *p) {
    D_08A62C50 = p;
    return p;
}

char *func_08898390(char *p) {
    D_08A62CB4 = p;
    return p;
}

char *func_088983A0(char *p) {
    D_08A62C7C = p;
    return p;
}

char *func_088983B0(char *p) {
    D_09A1DAEC = p;
    p[0x0] = 0;
    return p;
}

char *func_088983C4(char *p) {
    D_09A0B544 = p;
    p[0x4] = 0;
    return p;
}

char *func_088983D8(char *p) {
    D_09A1FDDC = p;
    return p;
}

char *func_088983E8(char *p) {
    D_08A62C60 = p;
    p[0x74] = 0;
    return p;
}

char *func_088983FC(char *p) {
    D_089CBBE8 = p;
    return p;
}

char *func_0889840C(char *p) {
    D_08A631A8 = p;
    return p;
}

char *func_0889841C(char *p) {
    D_089CBBE0 = p;
    return p;
}
