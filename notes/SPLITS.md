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
| `unit_08813574` | 0x08813574-0x08813594 | 1 function (flag set once) | 100 % |
| `unit_088140C4` | 0x088140C4-0x08814104 | 2 vector copies | 100 % |
| `unit_088167F4` | 0x088167F4-0x08816818 | 1 function (16-bit string length) | 100 % |
| `unit_0881CB0C` | 0x0881CB0C-0x0881CB2C | 1 function (clears flags) | 100 % |
| `unit_0884FC74` | 0x0884FC74-0x0884FC94 | 1 table lookup | 100 % |
| `unit_08850704` | 0x08850704-0x08850724 | 1 entry test | 100 % |
| `unit_0885148C` | 0x0885148C-0x088516A4 | section and entry lookup in the block at `D_089CC440`, 21 wrappers with a fixed section number | 23/23 functions, 100 % |
| `unit_088520A8` | 0x088520A8-0x088520C8 | 1 entry getter | 100 % |
| `unit_08852DF8` | 0x08852DF8-0x08852E38 | 1 slot scan | 100 % |
| `unit_08856D60` | 0x08856D60-0x08856DA0 | 1 byte search | 100 % |
| `unit_088571C8` | 0x088571C8-0x088571E8 | 1 bit test | 100 % |
| `unit_08857D2C` | 0x08857D2C-0x08857D6C | 1 bit clear | 100 % |
| `unit_08859728` | 0x08859728-0x08859768 | 1 display-list enqueue | 100 % |
| `unit_088615E4` | 0x088615E4-0x08861604 | 1 table-address initialiser | 100 % |
| `unit_0886421C` | 0x0886421C-0x0886423C | 1 element address | 100 % |
| `unit_08865A9C` | 0x08865A9C-0x08865ADC | 1 flag clear | 100 % |
| `unit_08866284` | 0x08866284-0x088662B8 | one function (switch on a byte field) | 100 % |
| `unit_08867008` | 0x08867008-0x08867058 | 4 forwarders building a byte index | 100 % |
| `unit_0886A73C` | 0x0886A73C-0x0886A77C | 1 counter | 100 % |
| `unit_0886D26C` | 0x0886D26C-0x0886D28C | 1 forwarder | 100 % |
| `unit_08879158` | 0x08879158-0x08879198 | 1 sum | 100 % |
| `unit_0887FDAC` | 0x0887FDAC-0x0887FE5C | 7 getters on an array of 20-byte entries | 100 % |
| `unit_08880384` | 0x08880384-0x088803FC | 2 forwarders with a computed step, 4 setters | 100 % |
| `unit_0888076C` | 0x0888076C-0x0888080C | 3 forwarders | 100 % |
| `unit_08886048` | 0x08886048-0x088860A0 | 8 field getters and setters | 100 % |
| `unit_088865B0` | 0x088865B0-0x088865D0 | 1 entry reset | 100 % |
| `unit_08886618` | 0x08886618-0x08886638 | 1 entry setter | 100 % |
| `unit_0888E1F8` | 0x0888E1F8-0x0888E218 | 1 dot product (x, z) | 100 % |
| `unit_08890080` | 0x08890080-0x088900A0 | 1 setter | 100 % |
| `unit_08898350` | 0x08898350-0x0889842C | 13 setters of global pointers | 100 % |
| `unit_0889A024` | 0x0889A024-0x0889A064 | 2 flag + callback registrations | 100 % |
| `unit_0889EA4C` | 0x0889EA4C-0x0889EAE8 | 19 forwarders (tail calls) | 100 % |
| `unit_0889EC78` | 0x0889EC78-0x0889ECB8 | 8 forwarders | 100 % |
| `unit_0889EE40` | 0x0889EE40-0x0889EEA0 | 12 forwarders | 100 % |
| `unit_0889EF20` | 0x0889EF20-0x0889EF40 | 1 semaphore wait | 100 % |
| `unit_0889F47C` | 0x0889F47C-0x0889F4BC | 1 list cursor step | 100 % |
| `unit_0889F744` | 0x0889F744-0x0889F764 | 1 element address | 100 % |
| `unit_088A0938` | 0x088A0938-0x088A0958 | 1 initialiser | 100 % |
| `unit_088A0BE4` | 0x088A0BE4-0x088A0C10 | 3 forwarders, 1 flag setter | 100 % |
| `unit_088A0D70` | 0x088A0D70-0x088A0DB0 | 1 entry reset | 100 % |
| `unit_088A6024` | 0x088A6024-0x088A6040 | one function (table store) | 100 % |
| `unit_088A8028` | 0x088A8028-0x088A8048 | 1 setter | 100 % |
| `unit_088AB490` | 0x088AB490-0x088AB4B0 | 1 bit set | 100 % |
| `unit_088AEFCC` | 0x088AEFCC-0x088AF020 | 4 tests and getters on small globals | 100 % |
| `unit_088B0044` | 0x088B0044-0x088B0084 | 1 big-endian append | 100 % |
| `unit_088B650C` | 0x088B650C-0x088B652C | 1 counter increment | 100 % |
| `unit_088B7958` | 0x088B7958-0x088B7978 | 1 global reset | 100 % |
| `unit_088CC4D8` | 0x088CC4D8-0x088CC508 | six functions returning 0 | 100 % |
| `unit_088DC6E8` | 0x088DC6E8-0x088DC720 | 6 accessors | 100 % |
| `unit_088EF348` | 0x088EF348-0x088EF380 | 4 forwarders with a fixed first argument, 1 empty function | 100 % |
| `unit_088EF488` | 0x088EF488-0x088EF4A8 | 4 empty callbacks | 100 % |

## Method

Throw-away scripts over `asm/ULES01213/boot/text*.s` (one function per `glabel`);
re-run them after any change of the splat config. A tool for this belongs in
`tools/psp` once a second use appears.
