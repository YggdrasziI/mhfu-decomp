# Region map of `BOOT.BIN` `.text` (ULES01213)

`.text` runs from 0x08804000 to 0x0890DE38 (3572 functions found by splat), then
`.sceStub.text` (system call stubs) to 0x0890E6B8.

## Regions

| Range (approximate) | Code | Evidence |
|---|---|---|
| 0x08804000 - ~0x08811C00 | not Metrowerks style (library code, hypothesis) | below |
| ~0x08811C00 - ~0x08904000 | Metrowerks `mwccpsp` (game and engine) | 6 probe functions match (`notes/COMPILER.md`) |
| ~0x08904000 - 0x0890DE38 | not Metrowerks style; holds the entry point 0x08906934 | below |

The edges are only known to a few functions: the first edge lies between
0x08811B3C and 0x08811C84, the second between 0x08903ED0 and 0x089040A0. A few
functions inside the middle region also have the outer style (0x08901FDC,
0x089030D8, 0x08903A94, 0x08903C64), so the edges may be ragged or the measures
noisy.

## Evidence

Three measures over the splat output, all pointing to the same two outer regions:

1. **Loading a global into `$v0`.** mwccpsp writes `lui $v0, %hi(sym)` then
   `lw $v0, %lo(sym)($v0)`. In the middle region all 380 such loads use `$v0` as the
   base. In the outer regions 12 use another register (`lui $v1` /
   `lw $v0, ($v1)`), from 0x08808764 to 0x0880C57C and from 0x08907254 to
   0x089073F8; 3 use `$v0` (0x0890C20C-0x0890C254, small getters near the end of
   `.text`, maybe another object).
2. **Prologue order.** In functions that open a stack frame, mwccpsp saves `$ra`
   first: 1981 of 2051 functions between 0x08820000 and 0x08900000. Between
   0x08804000 and 0x0880C600 it is 16 of 46, between 0x08904000 and 0x08907400 it is
   5 of 24.
3. **Allegrex instructions.** `movn`, `movz`, `ext`, `ins`, `min`, `max` are dense in
   0x08804000-0x08813000 and 0x08904000-0x0890C000, rare in between (use not identified;
   0x088E9B78-0x088EB01C has a small group).

Probes: the two functions mwccpsp 3.0.1 does not reproduce (`func_0880B420`,
`func_0880EDF8`) are in the first outer region; the six it reproduces are at
0x08822990 and above.

## Compiler of the outer regions

Probe: `tools/probes/lib_leaf.c`, 5 small functions of the first outer region
(`func_0880B420` global getter, `func_0880C53C` / `func_0880C578` interrupt
suspend and resume around a nesting counter, `func_0880D97C` push on a hash
bucket, `func_0880EDF8` string length). 2026-11-11:

| Compiler | Flags | Result |
|---|---|---|
| `mwccpsp_3.0.1` builds 121, 134, 139, 147, 219 | `-O1` to `-O4`, `-O4,s` (with `-sdatathreshold 0`) | 0/5 |
| `pspsnc_1.2.7503.0` (from the sibling project) | `-O1`, `-O2`, `-O3`, `-O2 -g` | 0/5 |
| `psp-gcc-1.3.1` (GCC 3.3.3, allegrex 2.2.1), decomp.me archive | `-O1`, `-O2`, `-O3`, `-Os` (with `-G0`), `-O2 -G0 -fno-optimize-sibling-calls` | **1/5 at `-O2`**: `func_0880B420` identical; `func_0880C53C` identical but for 2 swapped instructions |
| `psp-gcc-1.7.1` (GCC 3.3.3, allegrex 2.2.2), assembler of 1.3.1 | same | same output as 1.3.1 |

psp-gcc is Linux-only (32-bit x86): it runs in the manual `Compiler probe` workflow
(`.github/workflows/probe.yml`, inputs `compiler`, `as_from`, `probe`, `flags`).

What rules each one out, or not:

- **mwccpsp**: saves `$ra` at the top of the frame (`sw $ra, 0xC($sp)` in a 16-byte
  frame) and does not turn a final call into a jump; the original has
  `sw $ra, 0x0($sp)` and `j sceKernelCpuResumeIntr`.
- **SNC 1.2.7503.0**: same frame as the original (`$ra` at 0), same instruction
  shapes on `func_0880D97C`, but it writes moves as `or $rd, $rs, $zero` and
  prefers `$a0`-`$a3`; `BOOT.BIN` has no `or $rd, $rs, $zero` at all (moves are
  `addu $rd, $rs, $zero`, 2131 in the outer regions) and the original uses
  `$v0`/`$v1`. Another SNC version is not excluded.
- **GCC** (psp-gcc 1.3.1 / 1.7.1 at `-O2 -G0`): the same family. Frame layout
  (`$ra` alone at 0 in a 16-byte frame), `lui $v1` / `lw $v0, ($v1)` for a global
  load and `addu` moves all match; `func_0880B420` is identical and `func_0880C53C`
  only orders `lw $ra` before the last `sw` where the original does the opposite.
  Not the same version: these GCC 3.3.3 builds never turn the final call of
  `func_0880C578` into `j sceKernelCpuResumeIntr` (the original has no frame at
  all there), even at `-O3`. A later GCC (one that emits MIPS sibling calls) is
  the next candidate; none is in the decomp.me archive.
- `func_0880D97C` and `func_0880EDF8` still differ in register choice with every
  compiler; their source shape may be wrong too.

Other hints that these regions are libraries (not proven): C string functions at
0x0880ED04-0x0880EE10; `.data` starts with libc strings (`"_exit"`,
`"libc:%s: should be called from main thread\n"` at 0x0890F900 and 0x0890F908); the
second region holds the entry point.

## Units

All in the Metrowerks region; bounds are hypotheses until neighbours are split.

| Unit | Range | Content | Status |
|---|---|---|---|
| `unit_088124D8` | 0x088124D8-0x088125A4 | 2 small functions | 100 % |
| `unit_088129B8` | 0x088129B8-0x088129F8 | 1 function (calls func_0890BFA4 on the object when the flag is positive, returns it) | 100 % |
| `unit_088129F8` | 0x088129F8-0x08812A08 | 1 small function | 100 % |
| `unit_08813188` | 0x08813188-0x088131B8 | 1 small function (C++) | 100 % |
| `unit_088131B8` | 0x088131B8-0x088131FC | 1 field update guarded by a bool comparison (C++) | 100 % |
| `unit_08813558` | 0x08813558-0x08813560 | 1 small function | 100 % |
| `unit_08813560` | 0x08813560-0x08813574 | 1 small function | 100 % |
| `unit_08813574` | 0x08813574-0x08813594 | 1 function (flag set once) | 100 % |
| `unit_08813C8C` | 0x08813C8C-0x08813CC8 | 1 small function | 100 % |
| `unit_08813DAC` | 0x08813DAC-0x08813DD8 | 1 small function | 100 % |
| `unit_08813E10` | 0x08813E10-0x08813E20 | 2 small functions | 100 % |
| `unit_088140C4` | 0x088140C4-0x08814104 | 2 vector copies | 100 % |
| `unit_08814984` | 0x08814984-0x08814A14 | 1 small function | 100 % |
| `unit_088167EC` | 0x088167EC-0x088167F4 | 1 small function | 100 % |
| `unit_088167F4` | 0x088167F4-0x08816818 | 1 function (16-bit string length) | 100 % |
| `unit_08816AE4` | 0x08816AE4-0x08816B64 | 2 functions with the shape of func_088129B8 | 100 % |
| `unit_08816B64` | 0x08816B64-0x08816B6C | 1 small function | 100 % |
| `unit_0881CAC8` | 0x0881CAC8-0x0881CB0C | 1 reset (call, byte and flag clear) | 100 % |
| `unit_0881CB0C` | 0x0881CB0C-0x0881CB2C | 1 function (clears flags) | 100 % |
| `unit_0881E8F8` | 0x0881E8F8-0x0881E92C | 1 small function | 100 % |
| `unit_08823DB0` | 0x08823DB0-0x08823DEC | 1 small function | 100 % |
| `unit_08823DEC` | 0x08823DEC-0x08823E18 | 1 small function | 100 % |
| `unit_08825104` | 0x08825104-0x08825148 | 1 section-0 entry lookup through a table | 100 % |
| `unit_08826688` | 0x08826688-0x088266CC | 1 field reset | 100 % |
| `unit_08826EEC` | 0x08826EEC-0x08826EF4 | 1 small function | 100 % |
| `unit_08826F80` | 0x08826F80-0x08826FCC | 1 count of used slots, divided | 100 % |
| `unit_088298E4` | 0x088298E4-0x08829928 | 1 pointer chosen by a bool flag (C++) | 100 % |
| `unit_0882A248` | 0x0882A248-0x0882A28C | 1 free-slot search | 100 % |
| `unit_0882A8B8` | 0x0882A8B8-0x0882A8FC | 1 state code from a byte field | 100 % |
| `unit_08830354` | 0x08830354-0x088303A0 | 1 colour lookup through two tables | 100 % |
| `unit_088306DC` | 0x088306DC-0x08830728 | 1 reset (bytes, clear, copy) | 100 % |
| `unit_08832838` | 0x08832838-0x08832884 | 1 flag test and clear with a call | 100 % |
| `unit_0883448C` | 0x0883448C-0x088344FC | 1 small function | 100 % |
| `unit_088344FC` | 0x088344FC-0x08834548 | 1 two-way step on a byte field | 100 % |
| `unit_08834548` | 0x08834548-0x088345B8 | 1 small function | 100 % |
| `unit_088345B8` | 0x088345B8-0x088345FC | 1 call guarded by another call | 100 % |
| `unit_0883AB4C` | 0x0883AB4C-0x0883AB8C | 1 forwarder with fixed arguments | 100 % |
| `unit_0883D274` | 0x0883D274-0x0883D290 | 1 small function | 100 % |
| `unit_08844390` | 0x08844390-0x088443EC | 1 small function | 100 % |
| `unit_08844654` | 0x08844654-0x0884469C | 1 test on a call result | 100 % |
| `unit_0884860C` | 0x0884860C-0x08848630 | 2 small functions | 100 % |
| `unit_088490C8` | 0x088490C8-0x08849120 | 1 small function | 100 % |
| `unit_0884B010` | 0x0884B010-0x0884B058 | 1 function (stores a table address in the object, then a call when the flag is positive) | 100 % |
| `unit_0884B19C` | 0x0884B19C-0x0884B234 | 1 small function | 100 % |
| `unit_0884DE34` | 0x0884DE34-0x0884DE3C | 1 small function | 100 % |
| `unit_0884ECAC` | 0x0884ECAC-0x0884ED24 | 1 small function | 100 % |
| `unit_0884F2CC` | 0x0884F2CC-0x0884F2E0 | 1 small function | 100 % |
| `unit_0884F3FC` | 0x0884F3FC-0x0884F440 | 1 comparison of a 20-byte entry | 100 % |
| `unit_0884F510` | 0x0884F510-0x0884F5F4 | 3 tests with a fallback call | 100 % |
| `unit_0884FB6C` | 0x0884FB6C-0x0884FBA4 | 1 small function | 100 % |
| `unit_0884FC74` | 0x0884FC74-0x0884FC94 | 1 table lookup | 100 % |
| `unit_08850704` | 0x08850704-0x08850724 | 1 entry test | 100 % |
| `unit_08850EC4` | 0x08850EC4-0x08850EFC | 1 small function | 100 % |
| `unit_08851144` | 0x08851144-0x0885115C | 1 small function | 100 % |
| `unit_0885148C` | 0x0885148C-0x088516A4 | section and entry lookup in the block at `D_089CC440`, 21 wrappers with a fixed section number | 23/23 functions, 100 % |
| `unit_0885205C` | 0x0885205C-0x088520A8 | 1 byte table lookup | 100 % |
| `unit_088520A8` | 0x088520A8-0x088520C8 | 1 entry getter | 100 % |
| `unit_088520C8` | 0x088520C8-0x088520D0 | 1 small function | 100 % |
| `unit_088520D0` | 0x088520D0-0x08852114 | 1 non-zero 16-bit counter | 100 % |
| `unit_08852A44` | 0x08852A44-0x08852A50 | 1 small function | 100 % |
| `unit_08852DF8` | 0x08852DF8-0x08852E38 | 1 slot scan | 100 % |
| `unit_08855410` | 0x08855410-0x08855428 | 1 small function | 100 % |
| `unit_08856550` | 0x08856550-0x0885658C | 2 small functions | 100 % |
| `unit_088567B4` | 0x088567B4-0x088567C8 | 1 small function | 100 % |
| `unit_0885683C` | 0x0885683C-0x08856884 | 1 state set with two calls | 100 % |
| `unit_08856884` | 0x08856884-0x088568AC | 1 small function | 100 % |
| `unit_08856C94` | 0x08856C94-0x08856CA0 | 1 small function | 100 % |
| `unit_08856D60` | 0x08856D60-0x08856DA0 | 1 byte search | 100 % |
| `unit_088571C8` | 0x088571C8-0x088571E8 | 1 bit test | 100 % |
| `unit_088571E8` | 0x088571E8-0x088571F8 | 1 small function | 100 % |
| `unit_08857C18` | 0x08857C18-0x08857C2C | 2 small functions | 100 % |
| `unit_08857D2C` | 0x08857D2C-0x08857D6C | 1 bit clear | 100 % |
| `unit_08859728` | 0x08859728-0x08859768 | 1 display-list enqueue | 100 % |
| `unit_088597FC` | 0x088597FC-0x0885981C | 2 small functions | 100 % |
| `unit_08859AF0` | 0x08859AF0-0x08859B44 | 1 small function | 100 % |
| `unit_0885A8E0` | 0x0885A8E0-0x0885A8F0 | 1 small function | 100 % |
| `unit_0885AC8C` | 0x0885AC8C-0x0885ACA0 | 1 small function | 100 % |
| `unit_0885ACA0` | 0x0885ACA0-0x0885ACA8 | 1 small function | 100 % |
| `unit_0885FBB4` | 0x0885FBB4-0x0885FBF4 | 1 lookup then call | 100 % |
| `unit_08860710` | 0x08860710-0x08860758 | 1 function with the shape of func_0884B010 | 100 % |
| `unit_08860760` | 0x08860760-0x08860768 | 1 small function | 100 % |
| `unit_0886159C` | 0x0886159C-0x088615E4 | 1 function with the shape of func_0884B010 | 100 % |
| `unit_088615E4` | 0x088615E4-0x08861604 | 1 table-address initialiser | 100 % |
| `unit_088626DC` | 0x088626DC-0x088626E4 | 1 small function | 100 % |
| `unit_08862710` | 0x08862710-0x08862768 | 4 small functions | 100 % |
| `unit_088627AC` | 0x088627AC-0x088627B4 | 1 small function | 100 % |
| `unit_08862E54` | 0x08862E54-0x08862E64 | 1 small function | 100 % |
| `unit_0886421C` | 0x0886421C-0x0886423C | 1 element address | 100 % |
| `unit_088642FC` | 0x088642FC-0x08864348 | 1 small function | 100 % |
| `unit_0886454C` | 0x0886454C-0x08864554 | 1 small function | 100 % |
| `unit_088646A4` | 0x088646A4-0x088646B4 | 2 small functions | 100 % |
| `unit_08865A24` | 0x08865A24-0x08865A2C | 1 small function | 100 % |
| `unit_08865A9C` | 0x08865A9C-0x08865ADC | 1 flag clear | 100 % |
| `unit_08865BAC` | 0x08865BAC-0x08865BD0 | 1 small function | 100 % |
| `unit_08865CB8` | 0x08865CB8-0x08865CEC | 1 small function | 100 % |
| `unit_08865DBC` | 0x08865DBC-0x08865DC4 | 1 small function | 100 % |
| `unit_08865E40` | 0x08865E40-0x08865E78 | 2 small functions | 100 % |
| `unit_08865EC0` | 0x08865EC0-0x08865F24 | 1 small function | 100 % |
| `unit_08866284` | 0x08866284-0x088662B8 | one function (switch on a byte field) | 100 % |
| `unit_08867008` | 0x08867008-0x08867058 | 4 forwarders building a byte index | 100 % |
| `unit_08869564` | 0x08869564-0x08869570 | 1 small function | 100 % |
| `unit_088698EC` | 0x088698EC-0x08869904 | 1 small function | 100 % |
| `unit_0886A444` | 0x0886A444-0x0886A4CC | 1 small function | 100 % |
| `unit_0886A73C` | 0x0886A73C-0x0886A77C | 1 counter | 100 % |
| `unit_0886BE34` | 0x0886BE34-0x0886BE50 | 1 small function | 100 % |
| `unit_0886D248` | 0x0886D248-0x0886D26C | 1 small function | 100 % |
| `unit_0886D26C` | 0x0886D26C-0x0886D28C | 1 forwarder | 100 % |
| `unit_0886DFAC` | 0x0886DFAC-0x0886E000 | 1 small function | 100 % |
| `unit_0886E000` | 0x0886E000-0x0886E008 | 1 small function | 100 % |
| `unit_0886F78C` | 0x0886F78C-0x0886F79C | 1 small function | 100 % |
| `unit_08870194` | 0x08870194-0x0887019C | 1 small function | 100 % |
| `unit_08872E2C` | 0x08872E2C-0x08872E48 | 1 small function | 100 % |
| `unit_08872E84` | 0x08872E84-0x08872ED4 | 3 small functions | 100 % |
| `unit_08873980` | 0x08873980-0x088739A4 | 1 small function | 100 % |
| `unit_08879158` | 0x08879158-0x08879198 | 1 sum | 100 % |
| `unit_0887D0B4` | 0x0887D0B4-0x0887D0D0 | 1 small function | 100 % |
| `unit_0887FAB4` | 0x0887FAB4-0x0887FAEC | 1 small function | 100 % |
| `unit_0887FBBC` | 0x0887FBBC-0x0887FBC4 | 1 small function | 100 % |
| `unit_0887FCBC` | 0x0887FCBC-0x0887FD04 | 3 small functions | 100 % |
| `unit_0887FDAC` | 0x0887FDAC-0x0887FE5C | 7 getters on an array of 20-byte entries | 100 % |
| `unit_0887FF1C` | 0x0887FF1C-0x0887FF24 | 1 small function | 100 % |
| `unit_0887FF24` | 0x0887FF24-0x0887FF74 | 1 small function | 100 % |
| `unit_08880378` | 0x08880378-0x08880384 | 1 small function | 100 % |
| `unit_08880384` | 0x08880384-0x088803FC | 2 forwarders with a computed step, 4 setters | 100 % |
| `unit_0888076C` | 0x0888076C-0x0888080C | 3 forwarders | 100 % |
| `unit_08881824` | 0x08881824-0x08881840 | 1 small function | 100 % |
| `unit_08882CFC` | 0x08882CFC-0x08882D20 | 1 small function | 100 % |
| `unit_08882F64` | 0x08882F64-0x08882FA4 | 1 small function | 100 % |
| `unit_08885D80` | 0x08885D80-0x08885DB0 | 1 small function | 100 % |
| `unit_08886048` | 0x08886048-0x088860A0 | 8 field getters and setters | 100 % |
| `unit_08886124` | 0x08886124-0x0888617C | 4 small functions | 100 % |
| `unit_08886530` | 0x08886530-0x08886568 | 1 small function | 100 % |
| `unit_088865B0` | 0x088865B0-0x088865D0 | 1 entry reset | 100 % |
| `unit_08886618` | 0x08886618-0x08886638 | 1 entry setter | 100 % |
| `unit_08886638` | 0x08886638-0x0888664C | 1 small function | 100 % |
| `unit_08886664` | 0x08886664-0x08886674 | 1 small function | 100 % |
| `unit_0888670C` | 0x0888670C-0x08886734 | 2 small functions | 100 % |
| `unit_08886734` | 0x08886734-0x08886780 | 1 small function | 100 % |
| `unit_08886870` | 0x08886870-0x08886898 | 1 small function | 100 % |
| `unit_08886898` | 0x08886898-0x088868A0 | 1 small function | 100 % |
| `unit_088883B8` | 0x088883B8-0x088883C0 | 1 small function | 100 % |
| `unit_08889C90` | 0x08889C90-0x08889CAC | 1 small function | 100 % |
| `unit_0888A164` | 0x0888A164-0x0888A190 | 1 small function | 100 % |
| `unit_0888A1D0` | 0x0888A1D0-0x0888A1FC | 1 small function | 100 % |
| `unit_0888E1F8` | 0x0888E1F8-0x0888E218 | 1 dot product (x, z) | 100 % |
| `unit_08890080` | 0x08890080-0x088900A0 | 1 setter | 100 % |
| `unit_08890C94` | 0x08890C94-0x08890CE0 | 1 small function | 100 % |
| `unit_08890DE8` | 0x08890DE8-0x08890E08 | 2 small functions | 100 % |
| `unit_08890E38` | 0x08890E38-0x08890E48 | 2 small functions | 100 % |
| `unit_088930A0` | 0x088930A0-0x088930A8 | 1 small function | 100 % |
| `unit_08897298` | 0x08897298-0x088972A0 | 1 small function | 100 % |
| `unit_08898350` | 0x08898350-0x0889842C | 13 setters of global pointers | 100 % |
| `unit_088984A8` | 0x088984A8-0x088984B8 | 1 small function | 100 % |
| `unit_08898510` | 0x08898510-0x08898540 | 3 small functions | 100 % |
| `unit_08898948` | 0x08898948-0x08898980 | 1 small function | 100 % |
| `unit_0889A024` | 0x0889A024-0x0889A064 | 2 flag + callback registrations | 100 % |
| `unit_0889E1BC` | 0x0889E1BC-0x0889E1E0 | 1 small function | 100 % |
| `unit_0889E440` | 0x0889E440-0x0889E47C | 1 small function | 100 % |
| `unit_0889E670` | 0x0889E670-0x0889E6A4 | 1 small function | 100 % |
| `unit_0889E9D4` | 0x0889E9D4-0x0889E9DC | 1 small function | 100 % |
| `unit_0889EA4C` | 0x0889EA4C-0x0889EAE8 | 19 forwarders (tail calls) | 100 % |
| `unit_0889EC14` | 0x0889EC14-0x0889EC50 | 1 small function | 100 % |
| `unit_0889EC78` | 0x0889EC78-0x0889ECB8 | 8 forwarders | 100 % |
| `unit_0889EE40` | 0x0889EE40-0x0889EEA0 | 12 forwarders | 100 % |
| `unit_0889EF20` | 0x0889EF20-0x0889EF40 | 1 semaphore wait | 100 % |
| `unit_0889F42C` | 0x0889F42C-0x0889F444 | 2 small functions | 100 % |
| `unit_0889F47C` | 0x0889F47C-0x0889F4BC | 1 list cursor step | 100 % |
| `unit_0889F744` | 0x0889F744-0x0889F764 | 1 element address | 100 % |
| `unit_0889F9A0` | 0x0889F9A0-0x0889F9C4 | 1 small function | 100 % |
| `unit_088A0938` | 0x088A0938-0x088A0958 | 1 initialiser | 100 % |
| `unit_088A0A80` | 0x088A0A80-0x088A0A90 | 1 small function | 100 % |
| `unit_088A0A9C` | 0x088A0A9C-0x088A0AB0 | 1 small function | 100 % |
| `unit_088A0AB0` | 0x088A0AB0-0x088A0AFC | 1 small function | 100 % |
| `unit_088A0BE4` | 0x088A0BE4-0x088A0C10 | 3 forwarders, 1 flag setter | 100 % |
| `unit_088A0D70` | 0x088A0D70-0x088A0DB0 | 1 entry reset | 100 % |
| `unit_088A13A4` | 0x088A13A4-0x088A13AC | 1 small function | 100 % |
| `unit_088A232C` | 0x088A232C-0x088A2338 | 1 small function | 100 % |
| `unit_088A2404` | 0x088A2404-0x088A2410 | 1 small function | 100 % |
| `unit_088A3244` | 0x088A3244-0x088A32A0 | 1 small function | 100 % |
| `unit_088A3554` | 0x088A3554-0x088A356C | 2 small functions | 100 % |
| `unit_088A3ED4` | 0x088A3ED4-0x088A3F30 | 1 small function | 100 % |
| `unit_088A3FF4` | 0x088A3FF4-0x088A4004 | 1 small function | 100 % |
| `unit_088A407C` | 0x088A407C-0x088A412C | 2 small functions | 100 % |
| `unit_088A464C` | 0x088A464C-0x088A4654 | 1 small function | 100 % |
| `unit_088A4BE8` | 0x088A4BE8-0x088A4BF0 | 1 small function | 100 % |
| `unit_088A5ECC` | 0x088A5ECC-0x088A5EF8 | 1 small function | 100 % |
| `unit_088A600C` | 0x088A600C-0x088A6024 | 2 small functions | 100 % |
| `unit_088A6024` | 0x088A6024-0x088A6040 | one function (table store) | 100 % |
| `unit_088A72F0` | 0x088A72F0-0x088A7308 | 3 small functions | 100 % |
| `unit_088A7368` | 0x088A7368-0x088A7378 | 2 small functions | 100 % |
| `unit_088A73A8` | 0x088A73A8-0x088A73B8 | 2 small functions | 100 % |
| `unit_088A8018` | 0x088A8018-0x088A8028 | 1 small function | 100 % |
| `unit_088A8028` | 0x088A8028-0x088A8048 | 1 setter | 100 % |
| `unit_088A91F4` | 0x088A91F4-0x088A920C | 1 small function | 100 % |
| `unit_088A9CDC` | 0x088A9CDC-0x088A9CFC | 2 small functions | 100 % |
| `unit_088A9DF4` | 0x088A9DF4-0x088A9E28 | 1 small function | 100 % |
| `unit_088AA368` | 0x088AA368-0x088AA370 | 1 small function | 100 % |
| `unit_088AB1A0` | 0x088AB1A0-0x088AB1CC | 1 small function | 100 % |
| `unit_088AB490` | 0x088AB490-0x088AB4B0 | 1 bit set | 100 % |
| `unit_088AB4B0` | 0x088AB4B0-0x088AB4DC | 1 small function | 100 % |
| `unit_088AB500` | 0x088AB500-0x088AB514 | 1 small function | 100 % |
| `unit_088AC0D0` | 0x088AC0D0-0x088AC0E8 | 3 small functions | 100 % |
| `unit_088ACD38` | 0x088ACD38-0x088ACD60 | 1 small function | 100 % |
| `unit_088AD0F0` | 0x088AD0F0-0x088AD0F8 | 1 small function | 100 % |
| `unit_088AD12C` | 0x088AD12C-0x088AD134 | 1 small function | 100 % |
| `unit_088ADE7C` | 0x088ADE7C-0x088ADEAC | 1 small function | 100 % |
| `unit_088ADEF0` | 0x088ADEF0-0x088ADF58 | 2 small functions | 100 % |
| `unit_088AE25C` | 0x088AE25C-0x088AE274 | 1 small function | 100 % |
| `unit_088AE354` | 0x088AE354-0x088AE368 | 1 small function | 100 % |
| `unit_088AE4EC` | 0x088AE4EC-0x088AE4FC | 1 small function | 100 % |
| `unit_088AEFCC` | 0x088AEFCC-0x088AF020 | 4 tests and getters on small globals | 100 % |
| `unit_088AFC28` | 0x088AFC28-0x088AFC34 | 1 small function | 100 % |
| `unit_088AFFD0` | 0x088AFFD0-0x088B0010 | 2 small functions | 100 % |
| `unit_088B0044` | 0x088B0044-0x088B0084 | 1 big-endian append | 100 % |
| `unit_088B03BC` | 0x088B03BC-0x088B03CC | 1 small function | 100 % |
| `unit_088B03CC` | 0x088B03CC-0x088B040C | 2 small functions | 100 % |
| `unit_088B04B4` | 0x088B04B4-0x088B04EC | 1 small function | 100 % |
| `unit_088B099C` | 0x088B099C-0x088B09A4 | 1 small function | 100 % |
| `unit_088B1584` | 0x088B1584-0x088B158C | 1 small function | 100 % |
| `unit_088B1A04` | 0x088B1A04-0x088B1A18 | 1 small function | 100 % |
| `unit_088B30CC` | 0x088B30CC-0x088B3118 | 1 small function | 100 % |
| `unit_088B41B4` | 0x088B41B4-0x088B41E0 | 1 small function | 100 % |
| `unit_088B650C` | 0x088B650C-0x088B652C | 1 counter increment | 100 % |
| `unit_088B7958` | 0x088B7958-0x088B7978 | 1 global reset | 100 % |
| `unit_088B7A38` | 0x088B7A38-0x088B7A5C | 2 small functions | 100 % |
| `unit_088B863C` | 0x088B863C-0x088B86D4 | 2 small functions | 100 % |
| `unit_088B89A8` | 0x088B89A8-0x088B89B0 | 1 small function | 100 % |
| `unit_088B97A0` | 0x088B97A0-0x088B97BC | 1 small function | 100 % |
| `unit_088C2F88` | 0x088C2F88-0x088C2FD8 | 1 small function | 100 % |
| `unit_088C33E0` | 0x088C33E0-0x088C33E8 | 1 small function | 100 % |
| `unit_088C6AC8` | 0x088C6AC8-0x088C6AD4 | 1 small function | 100 % |
| `unit_088C6AD4` | 0x088C6AD4-0x088C6ADC | 1 small function | 100 % |
| `unit_088C7764` | 0x088C7764-0x088C7774 | 1 small function | 100 % |
| `unit_088CA2D8` | 0x088CA2D8-0x088CA2E0 | 1 small function | 100 % |
| `unit_088CAB2C` | 0x088CAB2C-0x088CAB34 | 1 small function | 100 % |
| `unit_088CACCC` | 0x088CACCC-0x088CACD4 | 1 small function | 100 % |
| `unit_088CAF4C` | 0x088CAF4C-0x088CAF54 | 1 small function | 100 % |
| `unit_088CB46C` | 0x088CB46C-0x088CB474 | 1 small function | 100 % |
| `unit_088CC0E4` | 0x088CC0E4-0x088CC128 | 1 small function | 100 % |
| `unit_088CC4D8` | 0x088CC4D8-0x088CC508 | six functions returning 0 | 100 % |
| `unit_088CC558` | 0x088CC558-0x088CC568 | 2 small functions | 100 % |
| `unit_088CDCB0` | 0x088CDCB0-0x088CDCC8 | 1 small function | 100 % |
| `unit_088CE754` | 0x088CE754-0x088CE75C | 1 small function | 100 % |
| `unit_088D2BEC` | 0x088D2BEC-0x088D2C14 | 1 small function | 100 % |
| `unit_088D5C2C` | 0x088D5C2C-0x088D5C34 | 1 small function | 100 % |
| `unit_088D5C74` | 0x088D5C74-0x088D5C7C | 1 small function | 100 % |
| `unit_088D6488` | 0x088D6488-0x088D64E0 | 1 small function | 100 % |
| `unit_088D71F0` | 0x088D71F0-0x088D722C | 1 small function | 100 % |
| `unit_088D81E4` | 0x088D81E4-0x088D81F0 | 1 small function | 100 % |
| `unit_088D88F0` | 0x088D88F0-0x088D8900 | 2 small functions | 100 % |
| `unit_088DAA98` | 0x088DAA98-0x088DAAA0 | 1 small function | 100 % |
| `unit_088DAE98` | 0x088DAE98-0x088DAEB0 | 2 small functions | 100 % |
| `unit_088DB49C` | 0x088DB49C-0x088DB4C8 | 1 small function | 100 % |
| `unit_088DC6E8` | 0x088DC6E8-0x088DC720 | 6 accessors | 100 % |
| `unit_088DC748` | 0x088DC748-0x088DC774 | 2 small functions | 100 % |
| `unit_088DCD94` | 0x088DCD94-0x088DCDEC | 1 small function | 100 % |
| `unit_088DD264` | 0x088DD264-0x088DD26C | 1 small function | 100 % |
| `unit_088DD3E4` | 0x088DD3E4-0x088DD3EC | 1 small function | 100 % |
| `unit_088DD7D8` | 0x088DD7D8-0x088DD7E8 | 1 small function | 100 % |
| `unit_088DD838` | 0x088DD838-0x088DD868 | 1 small function | 100 % |
| `unit_088DEA14` | 0x088DEA14-0x088DEA1C | 1 small function | 100 % |
| `unit_088DF698` | 0x088DF698-0x088DF6A0 | 1 small function | 100 % |
| `unit_088E1084` | 0x088E1084-0x088E108C | 1 small function | 100 % |
| `unit_088E62EC` | 0x088E62EC-0x088E6310 | 1 small function | 100 % |
| `unit_088E744C` | 0x088E744C-0x088E7460 | 1 small function | 100 % |
| `unit_088E9048` | 0x088E9048-0x088E9060 | 1 small function | 100 % |
| `unit_088EC3E0` | 0x088EC3E0-0x088EC3E8 | 1 small function | 100 % |
| `unit_088ED680` | 0x088ED680-0x088ED688 | 1 small function | 100 % |
| `unit_088EEE38` | 0x088EEE38-0x088EEE40 | 1 small function | 100 % |
| `unit_088EEFF0` | 0x088EEFF0-0x088EF000 | 1 small function | 100 % |
| `unit_088EF1F4` | 0x088EF1F4-0x088EF224 | 2 small functions | 100 % |
| `unit_088EF2C0` | 0x088EF2C0-0x088EF2C8 | 1 small function | 100 % |
| `unit_088EF348` | 0x088EF348-0x088EF380 | 4 forwarders with a fixed first argument, 1 empty function | 100 % |
| `unit_088EF380` | 0x088EF380-0x088EF3E0 | 3 small functions | 100 % |
| `unit_088EF3E0` | 0x088EF3E0-0x088EF460 | 1 small function | 100 % |
| `unit_088EF488` | 0x088EF488-0x088EF4A8 | 4 empty callbacks | 100 % |
| `unit_088EFC04` | 0x088EFC04-0x088EFC14 | 2 small functions | 100 % |
| `unit_088EFF78` | 0x088EFF78-0x088EFF88 | 1 small function | 100 % |
| `unit_088F0018` | 0x088F0018-0x088F0020 | 1 small function | 100 % |

## Method

Throw-away scripts over `asm/ULES01213/boot/text*.s` (one function per `glabel`);
re-run them after any change of the splat config. A tool for this belongs in
`tools/psp` once a second use appears.

Units of "small functions" (up to 0x80 bytes, at most two calls, no VFPU): m2c
`--valid-syntax` drafts, each field access written as `*(type *)(p + offset)`, compiled
as they are, kept only when every instruction matches and the unit file as a whole
still matches; then a mechanical clean-up and a full build. When m2c calls a
function with no arguments because the caller passes its own incoming registers
unchanged, the call gets the caller's first arguments, as many as the callee reads
(`$a0`-`$a3` read before written in a straight-line scan of the callee, following tail
jumps). The compiled code is the same whatever that count, so it is a reading aid,
not evidence. Drafts still calling a function without a prototype are left out.
Contiguous matching functions share a unit; the bounds are no more than that.
