/* See LICENSE file for copyright and license details. */
#ifndef POSIT_H
#define POSIT_H

#include <stdint.h>

/* Type definitions (availability of int*_t infers two's complement) */
typedef int8_t posit8;
typedef int16_t posit16;
typedef int32_t posit32;
typedef int64_t posit64;

typedef int8_t posit_log8;
typedef int16_t posit_log16;
typedef int32_t posit_log32;
typedef int64_t posit_log64;

/* NaR (Not a Real) */
#define POSIT8_NAR  (INT8_C(-127) - INT8_C(1))
#define POSIT16_NAR (INT16_C(-32767) - INT16_C(1))
#define POSIT32_NAR (INT32_C(-2147483647) - INT32_C(1))
#define POSIT64_NAR (INT64_C(-9223372036854775807) - INT64_C(1))

#define POSIT_LOG8_NAR  (INT8_C(-127) - INT8_C(1))
#define POSIT_LOG16_NAR (INT16_C(-32767) - INT16_C(1))
#define POSIT_LOG32_NAR (INT32_C(-2147483647) - INT32_C(1))
#define POSIT_LOG64_NAR (INT64_C(-9223372036854775807) - INT64_C(1))

/* Smallest Positive */
#define POSIT8_POSITIVE_MINIMUM  INT8_C(1)
#define POSIT16_POSITIVE_MINIMUM INT16_C(1)
#define POSIT32_POSITIVE_MINIMUM INT32_C(1)
#define POSIT64_POSITIVE_MINIMUM INT64_C(1)

#define POSIT_LOG8_POSITIVE_MINIMUM  INT8_C(1)
#define POSIT_LOG16_POSITIVE_MINIMUM INT16_C(1)
#define POSIT_LOG32_POSITIVE_MINIMUM INT32_C(1)
#define POSIT_LOG64_POSITIVE_MINIMUM INT64_C(1)

/* Largest Positive */
#define POSIT8_POSITIVE_MAXIMUM  INT8_MAX
#define POSIT16_POSITIVE_MAXIMUM INT16_MAX
#define POSIT32_POSITIVE_MAXIMUM INT32_MAX
#define POSIT64_POSITIVE_MAXIMUM INT64_MAX

#define POSIT_LOG8_POSITIVE_MAXIMUM  INT8_MAX
#define POSIT_LOG16_POSITIVE_MAXIMUM INT16_MAX
#define POSIT_LOG32_POSITIVE_MAXIMUM INT32_MAX
#define POSIT_LOG64_POSITIVE_MAXIMUM INT64_MAX

/* 2π */
#define POSIT8_2_PI  INT8_C(85)
#define POSIT16_2_PI INT16_C(21649)
#define POSIT32_2_PI INT32_C(1418788266)
#define POSIT64_2_PI INT64_C(6093649202990451747)

#define POSIT_LOG8_2_PI  INT8_C(85)
#define POSIT_LOG16_2_PI INT16_C(21814)
#define POSIT_LOG32_2_PI INT32_C(1429619610)
#define POSIT_LOG64_2_PI INT64_C(6140169471952616366)

/* 2π/3 */
#define POSIT8_2_PI_OVER_3  INT8_C(72)
#define POSIT16_2_PI_OVER_3 INT16_C(18529)
#define POSIT32_2_PI_OVER_3 INT32_C(1214294300)
#define POSIT64_2_PI_OVER_3 INT64_C(5215354306600481474)

#define POSIT_LOG8_2_PI_OVER_3  INT8_C(73)
#define POSIT_LOG16_2_PI_OVER_3 INT16_C(18568)
#define POSIT_LOG32_2_PI_OVER_3 INT32_C(1216889544)
#define POSIT_LOG64_2_PI_OVER_3 INT64_C(5226500796414183280)

/* 2π/5 */
#define POSIT8_2_PI_OVER_5  INT8_C(66)
#define POSIT16_2_PI_OVER_5 INT16_C(16910)
#define POSIT32_2_PI_OVER_5 INT32_C(1108187067)
#define POSIT64_2_PI_OVER_5 INT64_C(4759627211931676700)

#define POSIT_LOG8_2_PI_OVER_5  INT8_C(67)
#define POSIT_LOG16_2_PI_OVER_5 INT16_C(17059)
#define POSIT_LOG32_2_PI_OVER_5 INT32_C(1117975697)
#define POSIT_LOG64_2_PI_OVER_5 INT64_C(4801669055579392590)

/* 3π */
#define POSIT8_3_PI  INT8_C(89)
#define POSIT16_3_PI INT16_C(22893)
#define POSIT32_3_PI INT32_C(1500298816)
#define POSIT64_3_PI INT64_C(6443734347228965146)

#define POSIT_LOG8_3_PI  INT8_C(90)
#define POSIT_LOG16_3_PI INT16_C(23012)
#define POSIT_LOG32_3_PI INT32_C(1508131948)
#define POSIT_LOG64_3_PI INT64_C(6477377395187625962)

/* 3π/2 */
#define POSIT8_3_PI_OVER_2  INT8_C(81)
#define POSIT16_3_PI_OVER_2 INT16_C(20845)
#define POSIT32_3_PI_OVER_2 INT32_C(1366081088)
#define POSIT64_3_PI_OVER_2 INT64_C(5867273594925541658)

#define POSIT_LOG8_3_PI_OVER_2  INT8_C(82)
#define POSIT_LOG16_3_PI_OVER_2 INT16_C(20964)
#define POSIT_LOG32_3_PI_OVER_2 INT32_C(1373914220)
#define POSIT_LOG64_3_PI_OVER_2 INT64_C(5900916642884202474)

/* 3π/4 */
#define POSIT8_3_PI_OVER_4  INT8_C(73)
#define POSIT16_3_PI_OVER_4 INT16_C(18797)
#define POSIT32_3_PI_OVER_4 INT32_C(1231863360)
#define POSIT64_3_PI_OVER_4 INT64_C(5290812842622118170)

#define POSIT_LOG8_3_PI_OVER_4  INT8_C(74)
#define POSIT_LOG16_3_PI_OVER_4 INT16_C(18916)
#define POSIT_LOG32_3_PI_OVER_4 INT32_C(1239696492)
#define POSIT_LOG64_3_PI_OVER_4 INT64_C(5324455890580778987)

/* 3π/5 */
#define POSIT8_3_PI_OVER_5  INT8_C(71)
#define POSIT16_3_PI_OVER_5 INT16_C(18196)
#define POSIT32_3_PI_OVER_5 INT32_C(1192518553)
#define POSIT64_3_PI_OVER_5 INT64_C(5121828184835532842)

#define POSIT_LOG8_3_PI_OVER_5  INT8_C(71)
#define POSIT_LOG16_3_PI_OVER_5 INT16_C(18257)
#define POSIT_LOG32_3_PI_OVER_5 INT32_C(1196488035)
#define POSIT_LOG64_3_PI_OVER_5 INT64_C(5138876978814402187)

/* 4π */
#define POSIT8_4_PI  INT8_C(93)
#define POSIT16_4_PI INT16_C(23697)
#define POSIT32_4_PI INT32_C(1553005994)
#define POSIT64_4_PI INT64_C(6670109955293875235)

#define POSIT_LOG8_4_PI  INT8_C(93)
#define POSIT_LOG16_4_PI INT16_C(23862)
#define POSIT_LOG32_4_PI INT32_C(1563837338)
#define POSIT_LOG64_4_PI INT64_C(6716630224256039854)

/* 4π/3 */
#define POSIT8_4_PI_OVER_3  INT8_C(80)
#define POSIT16_4_PI_OVER_3 INT16_C(20577)
#define POSIT32_4_PI_OVER_3 INT32_C(1348512028)
#define POSIT64_4_PI_OVER_3 INT64_C(5791815058903904962)

#define POSIT_LOG8_4_PI_OVER_3  INT8_C(81)
#define POSIT_LOG16_4_PI_OVER_3 INT16_C(20616)
#define POSIT_LOG32_4_PI_OVER_3 INT32_C(1351107272)
#define POSIT_LOG64_4_PI_OVER_3 INT64_C(5802961548717606768)

/* 4π/5 */
#define POSIT8_4_PI_OVER_5  INT8_C(74)
#define POSIT16_4_PI_OVER_5 INT16_C(18958)
#define POSIT32_4_PI_OVER_5 INT32_C(1242404795)
#define POSIT64_4_PI_OVER_5 INT64_C(5336087964235100188)

#define POSIT_LOG8_4_PI_OVER_5  INT8_C(75)
#define POSIT_LOG16_4_PI_OVER_5 INT16_C(19107)
#define POSIT_LOG32_4_PI_OVER_5 INT32_C(1252193425)
#define POSIT_LOG64_4_PI_OVER_5 INT64_C(5378129807882816078)

/* 5π */
#define POSIT8_5_PI  INT8_C(96)
#define POSIT16_5_PI INT16_C(24501)
#define POSIT32_5_PI INT32_C(1605713173)
#define POSIT64_5_PI INT64_C(6896485563358785324)

#define POSIT_LOG8_5_PI  INT8_C(96)
#define POSIT_LOG16_5_PI INT16_C(24522)
#define POSIT_LOG32_5_PI INT32_C(1607045796)
#define POSIT_LOG64_5_PI INT64_C(6902209136022416653)

/* 5π/2 */
#define POSIT8_5_PI_OVER_2  INT8_C(88)
#define POSIT16_5_PI_OVER_2 INT16_C(22453)
#define POSIT32_5_PI_OVER_2 INT32_C(1471495445)
#define POSIT64_5_PI_OVER_2 INT64_C(6320024811055361836)

#define POSIT_LOG8_5_PI_OVER_2  INT8_C(88)
#define POSIT_LOG16_5_PI_OVER_2 INT16_C(22474)
#define POSIT_LOG32_5_PI_OVER_2 INT32_C(1472828068)
#define POSIT_LOG64_5_PI_OVER_2 INT64_C(6325748383718993165)

/* 5π/3 */
#define POSIT8_5_PI_OVER_3  INT8_C(82)
#define POSIT16_5_PI_OVER_3 INT16_C(21113)
#define POSIT32_5_PI_OVER_3 INT32_C(1383650147)
#define POSIT64_5_PI_OVER_3 INT64_C(5942732130947178355)

#define POSIT_LOG8_5_PI_OVER_3  INT8_C(83)
#define POSIT_LOG16_5_PI_OVER_3 INT16_C(21276)
#define POSIT_LOG32_5_PI_OVER_3 INT32_C(1394315730)
#define POSIT_LOG64_5_PI_OVER_3 INT64_C(5988540460483983568)

/* 5π/4 */
#define POSIT8_5_PI_OVER_4  INT8_C(80)
#define POSIT16_5_PI_OVER_4 INT16_C(20405)
#define POSIT32_5_PI_OVER_4 INT32_C(1337277717)
#define POSIT64_5_PI_OVER_4 INT64_C(5743564058751938348)

#define POSIT_LOG8_5_PI_OVER_4  INT8_C(80)
#define POSIT_LOG16_5_PI_OVER_4 INT16_C(20426)
#define POSIT_LOG32_5_PI_OVER_4 INT32_C(1338610340)
#define POSIT_LOG64_5_PI_OVER_4 INT64_C(5749287631415569677)

/* 5π/6 */
#define POSIT8_5_PI_OVER_6  INT8_C(74)
#define POSIT16_5_PI_OVER_6 INT16_C(19065)
#define POSIT32_5_PI_OVER_6 INT32_C(1249432419)
#define POSIT64_5_PI_OVER_6 INT64_C(5366271378643754867)

#define POSIT_LOG8_5_PI_OVER_6  INT8_C(75)
#define POSIT_LOG16_5_PI_OVER_6 INT16_C(19228)
#define POSIT_LOG32_5_PI_OVER_6 INT32_C(1260098002)
#define POSIT_LOG64_5_PI_OVER_6 INT64_C(5412079708180560080)

/* 6π */
#define POSIT8_6_PI  INT8_C(97)
#define POSIT16_6_PI INT16_C(24758)
#define POSIT32_6_PI INT32_C(1622564640)
#define POSIT64_6_PI INT64_C(6968862063586735245)

#define POSIT_LOG8_6_PI  INT8_C(97)
#define POSIT_LOG16_6_PI INT16_C(24818)
#define POSIT_LOG32_6_PI INT32_C(1626481206)
#define POSIT_LOG64_6_PI INT64_C(6985683587566065653)

/* 6π/5 */
#define POSIT8_6_PI_OVER_5  INT8_C(79)
#define POSIT16_6_PI_OVER_5 INT16_C(20244)
#define POSIT32_6_PI_OVER_5 INT32_C(1326736281)
#define POSIT64_6_PI_OVER_5 INT64_C(5698288937138956330)

#define POSIT_LOG8_6_PI_OVER_5  INT8_C(79)
#define POSIT_LOG16_6_PI_OVER_5 INT16_C(20305)
#define POSIT_LOG32_6_PI_OVER_5 INT32_C(1330705763)
#define POSIT_LOG64_6_PI_OVER_5 INT64_C(5715337731117825675)

/* Euler-Mascheroni Constant γ */
#define POSIT8_GAMMA  INT8_C(57)
#define POSIT16_GAMMA INT16_C(14652)
#define POSIT32_GAMMA INT32_C(960251518)
#define POSIT64_GAMMA INT64_C(4124248866681457786)

#define POSIT_LOG8_GAMMA  INT8_C(58)
#define POSIT_LOG16_GAMMA INT16_C(14760)
#define POSIT_LOG32_GAMMA INT32_C(967331641)
#define POSIT_LOG64_GAMMA INT64_C(4154657764304223695)

/* lb(10) */
#define POSIT8_LB_10  INT8_C(77)
#define POSIT16_LB_10 INT16_C(19786)
#define POSIT32_LB_10 INT32_C(1296672645)
#define POSIT64_LB_10 INT64_C(5569166602765711536)

#define POSIT_LOG8_LB_10  INT8_C(78)
#define POSIT_LOG16_LB_10 INT16_C(19931)
#define POSIT_LOG32_LB_10 INT32_C(1306209727)
#define POSIT_LOG64_LB_10 INT64_C(5610128058112896900)

/* lb(e) */
#define POSIT8_LB_E  INT8_C(68)
#define POSIT16_LB_E INT16_C(17291)
#define POSIT32_LB_E INT32_C(1133159347)
#define POSIT64_LB_E INT64_C(4866882334739234572)

#define POSIT_LOG8_LB_E  INT8_C(68)
#define POSIT_LOG16_LB_E INT16_C(17467)
#define POSIT_LOG32_LB_E INT32_C(1144711645)
#define POSIT_LOG64_LB_E INT64_C(4916499079567956174)

/* lg(2) */
#define POSIT8_LG_2  INT8_C(50)
#define POSIT16_LG_2 INT16_C(12706)
#define POSIT32_LG_2 INT32_C(832702888)
#define POSIT64_LG_2 INT64_C(3576431672582537082)

#define POSIT_LOG8_LG_2  INT8_C(50)
#define POSIT_LOG16_LG_2 INT16_C(12837)
#define POSIT_LOG32_LG_2 INT32_C(841273921)
#define POSIT_LOG64_LG_2 INT64_C(3613243978741878908)

/* lg(e) */
#define POSIT8_LG_E  INT8_C(54)
#define POSIT16_LG_E INT16_C(13798)
#define POSIT32_LG_E INT32_C(904248715)
#define POSIT64_LG_E INT64_C(3883718656553813785)

#define POSIT_LOG8_LG_E  INT8_C(54)
#define POSIT_LOG16_LG_E INT16_C(13920)
#define POSIT_LOG32_LG_E INT32_C(912243742)
#define POSIT_LOG64_LG_E INT64_C(3918057039882447178)

/* ln(10) */
#define POSIT8_LN_10  INT8_C(73)
#define POSIT16_LN_10 INT16_C(18742)
#define POSIT32_LN_10 INT32_C(1228265694)
#define POSIT64_LN_10 INT64_C(5275360985902385857)

#define POSIT_LOG8_LN_10  INT8_C(74)
#define POSIT_LOG16_LN_10 INT16_C(18848)
#define POSIT_LOG32_LN_10 INT32_C(1235239906)
#define POSIT_LOG64_LN_10 INT64_C(5305314996972328630)

/* ln(2) */
#define POSIT8_LN_2  INT8_C(59)
#define POSIT16_LN_2 INT16_C(15127)
#define POSIT32_LN_2 INT32_C(991371647)
#define POSIT64_LN_2 INT64_C(4257908804145706907)

#define POSIT_LOG8_LN_2  INT8_C(60)
#define POSIT_LOG16_LN_2 INT16_C(15301)
#define POSIT_LOG32_LN_2 INT32_C(1002772003)
#define POSIT_LOG64_LN_2 INT64_C(4306872957286819634)

/* constant 1 */
#define POSIT8_ONE  INT8_C(64)
#define POSIT16_ONE INT16_C(16384)
#define POSIT32_ONE INT32_C(1073741824)
#define POSIT64_ONE INT64_C(4611686018427387904)

#define POSIT_LOG8_ONE  INT8_C(64)
#define POSIT_LOG16_ONE INT16_C(16384)
#define POSIT_LOG32_ONE INT32_C(1073741824)
#define POSIT_LOG64_ONE INT64_C(4611686018427387904)

/* Golden Ratio φ */
#define POSIT8_PHI  INT8_C(69)
#define POSIT16_PHI INT16_C(17650)
#define POSIT32_PHI INT32_C(1156692942)
#define POSIT64_PHI INT64_C(4967958356531237857)

#define POSIT_LOG8_PHI  INT8_C(70)
#define POSIT_LOG16_PHI INT16_C(17806)
#define POSIT_LOG32_PHI INT32_C(1166921396)
#define POSIT_LOG64_PHI INT64_C(5011889234239461907)

/* π */
#define POSIT8_PI  INT8_C(77)
#define POSIT16_PI INT16_C(19601)
#define POSIT32_PI INT32_C(1284570538)
#define POSIT64_PI INT64_C(5517188450687028259)

#define POSIT_LOG8_PI  INT8_C(77)
#define POSIT_LOG16_PI INT16_C(19766)
#define POSIT_LOG32_PI INT32_C(1295401882)
#define POSIT_LOG64_PI INT64_C(5563708719649192878)

/* π/2 */
#define POSIT8_PI_OVER_2  INT8_C(69)
#define POSIT16_PI_OVER_2 INT16_C(17553)
#define POSIT32_PI_OVER_2 INT32_C(1150352810)
#define POSIT64_PI_OVER_2 INT64_C(4940727698383604771)

#define POSIT_LOG8_PI_OVER_2  INT8_C(69)
#define POSIT_LOG16_PI_OVER_2 INT16_C(17718)
#define POSIT_LOG32_PI_OVER_2 INT32_C(1161184154)
#define POSIT_LOG64_PI_OVER_2 INT64_C(4987247967345769390)

/* π/3 */
#define POSIT8_PI_OVER_3  INT8_C(64)
#define POSIT16_PI_OVER_3 INT16_C(16481)
#define POSIT32_PI_OVER_3 INT32_C(1080076572)
#define POSIT64_PI_OVER_3 INT64_C(4638893554297057986)

#define POSIT_LOG8_PI_OVER_3  INT8_C(65)
#define POSIT_LOG16_PI_OVER_3 INT16_C(16520)
#define POSIT_LOG32_PI_OVER_3 INT32_C(1082671816)
#define POSIT_LOG64_PI_OVER_3 INT64_C(4650040044110759792)

/* π/4 */
#define POSIT8_PI_OVER_4  INT8_C(61)
#define POSIT16_PI_OVER_4 INT16_C(15505)
#define POSIT32_PI_OVER_4 INT32_C(1016135082)
#define POSIT64_PI_OVER_4 INT64_C(4364266946080181283)

#define POSIT_LOG8_PI_OVER_4  INT8_C(61)
#define POSIT_LOG16_PI_OVER_4 INT16_C(15670)
#define POSIT_LOG32_PI_OVER_4 INT32_C(1026966426)
#define POSIT_LOG64_PI_OVER_4 INT64_C(4410787215042345902)

/* π/5 */
#define POSIT8_PI_OVER_5  INT8_C(58)
#define POSIT16_PI_OVER_5 INT16_C(14862)
#define POSIT32_PI_OVER_5 INT32_C(973969339)
#define POSIT64_PI_OVER_5 INT64_C(4183166459628253212)

#define POSIT_LOG8_PI_OVER_5  INT8_C(59)
#define POSIT_LOG16_PI_OVER_5 INT16_C(15011)
#define POSIT_LOG32_PI_OVER_5 INT32_C(983757969)
#define POSIT_LOG64_PI_OVER_5 INT64_C(4225208303275969102)

/* π/6 */
#define POSIT8_PI_OVER_6  INT8_C(56)
#define POSIT16_PI_OVER_6 INT16_C(14433)
#define POSIT32_PI_OVER_6 INT32_C(945858844)
#define POSIT64_PI_OVER_6 INT64_C(4062432801993634498)

#define POSIT_LOG8_PI_OVER_6  INT8_C(57)
#define POSIT_LOG16_PI_OVER_6 INT16_C(14472)
#define POSIT_LOG32_PI_OVER_6 INT32_C(948454088)
#define POSIT_LOG64_PI_OVER_6 INT64_C(4073579291807336305)

/* √2 */
#define POSIT8_SQUARE_ROOT_2  INT8_C(67)
#define POSIT16_SQUARE_ROOT_2 INT16_C(17232)
#define POSIT32_SQUARE_ROOT_2 INT32_C(1129336627)
#define POSIT64_SQUARE_ROOT_2 INT64_C(4850463880207263304)

#define POSIT_LOG8_SQUARE_ROOT_2  INT8_C(68)
#define POSIT_LOG16_SQUARE_ROOT_2 INT16_C(17408)
#define POSIT_LOG32_SQUARE_ROOT_2 INT32_C(1140850688)
#define POSIT_LOG64_SQUARE_ROOT_2 INT64_C(4899916394579099648)

/* √3 */
#define POSIT8_SQUARE_ROOT_3  INT8_C(70)
#define POSIT16_SQUARE_ROOT_3 INT16_C(17883)
#define POSIT32_SQUARE_ROOT_3 INT32_C(1171996020)
#define POSIT64_SQUARE_ROOT_3 INT64_C(5033684577682871610)

#define POSIT_LOG8_SQUARE_ROOT_3  INT8_C(70)
#define POSIT_LOG16_SQUARE_ROOT_3 INT16_C(18007)
#define POSIT_LOG32_SQUARE_ROOT_3 INT32_C(1180106857)
#define POSIT_LOG64_SQUARE_ROOT_3 INT64_C(5068520356196604446)

/* √5 */
#define POSIT8_SQUARE_ROOT_5  INT8_C(73)
#define POSIT16_SQUARE_ROOT_5 INT16_C(18674)
#define POSIT32_SQUARE_ROOT_5 INT32_C(1223801806)
#define POSIT64_SQUARE_ROOT_5 INT64_C(5256188732682949601)

#define POSIT_LOG8_SQUARE_ROOT_5  INT8_C(73)
#define POSIT_LOG16_SQUARE_ROOT_5 INT16_C(18762)
#define POSIT_LOG32_SQUARE_ROOT_5 INT32_C(1229563781)
#define POSIT_LOG64_SQUARE_ROOT_5 INT64_C(5280936226613999792)

/* √6 */
#define POSIT8_SQUARE_ROOT_6  INT8_C(74)
#define POSIT16_SQUARE_ROOT_6 INT16_C(18892)
#define POSIT32_SQUARE_ROOT_6 INT32_C(1238124298)
#define POSIT64_SQUARE_ROOT_6 INT64_C(5317703368369542974)

#define POSIT_LOG8_SQUARE_ROOT_6  INT8_C(74)
#define POSIT_LOG16_SQUARE_ROOT_6 INT16_C(19031)
#define POSIT_LOG32_SQUARE_ROOT_6 INT32_C(1247215721)
#define POSIT_LOG64_SQUARE_ROOT_6 INT64_C(5356750732348316190)

/* Base 10 Exponential Function */
posit8 posit8_10_raised(posit8);
posit16 posit16_10_raised(posit16);
posit32 posit32_10_raised(posit32);
posit64 posit64_10_raised(posit64);

posit_log8 posit_log8_10_raised(posit_log8);
posit_log16 posit_log16_10_raised(posit_log16);
posit_log32 posit_log32_10_raised(posit_log32);
posit_log64 posit_log64_10_raised(posit_log64);

/* Base 10 Exponential Function Minus 1 */
posit8 posit8_10_raised_minus_1(posit8);
posit16 posit16_10_raised_minus_1(posit16);
posit32 posit32_10_raised_minus_1(posit32);
posit64 posit64_10_raised_minus_1(posit64);

posit_log8 posit_log8_10_raised_minus_1(posit_log8);
posit_log16 posit_log16_10_raised_minus_1(posit_log16);
posit_log32 posit_log32_10_raised_minus_1(posit_log32);
posit_log64 posit_log64_10_raised_minus_1(posit_log64);

/* Base 2 Exponential Function */
posit8 posit8_2_raised(posit8);
posit16 posit16_2_raised(posit16);
posit32 posit32_2_raised(posit32);
posit64 posit64_2_raised(posit64);

posit_log8 posit_log8_2_raised(posit_log8);
posit_log16 posit_log16_2_raised(posit_log16);
posit_log32 posit_log32_2_raised(posit_log32);
posit_log64 posit_log64_2_raised(posit_log64);

/* Base 2 Exponential Function Minus 1 */
posit8 posit8_2_raised_minus_1(posit8);
posit16 posit16_2_raised_minus_1(posit16);
posit32 posit32_2_raised_minus_1(posit32);
posit64 posit64_2_raised_minus_1(posit64);

posit_log8 posit_log8_2_raised_minus_1(posit_log8);
posit_log16 posit_log16_2_raised_minus_1(posit_log16);
posit_log32 posit_log32_2_raised_minus_1(posit_log32);
posit_log64 posit_log64_2_raised_minus_1(posit_log64);

/* Absolute */
posit8 posit8_absolute(posit8 t);
posit16 posit16_absolute(posit16 t);
posit32 posit32_absolute(posit32 t);
posit64 posit64_absolute(posit64 t);

posit_log8 posit_log8_absolute(posit_log8 t);
posit_log16 posit_log16_absolute(posit_log16 t);
posit_log32 posit_log32_absolute(posit_log32 t);
posit_log64 posit_log64_absolute(posit_log64 t);

/* Addition */
posit8 posit8_addition(posit8, posit8);
posit16 posit16_addition(posit16, posit16);
posit32 posit32_addition(posit32, posit32);
posit64 posit64_addition(posit64, posit64);

posit_log8 posit_log8_addition(posit_log8, posit_log8);
posit_log16 posit_log16_addition(posit_log16, posit_log16);
posit_log32 posit_log32_addition(posit_log32, posit_log32);
posit_log64 posit_log64_addition(posit_log64, posit_log64);

/* Arccosine */
posit8 posit8_arccos(posit8);
posit16 posit16_arccos(posit16);
posit32 posit32_arccos(posit32);
posit64 posit64_arccos(posit64);

posit_log8 posit_log8_arccos(posit_log8);
posit_log16 posit_log16_arccos(posit_log16);
posit_log32 posit_log32_arccos(posit_log32);
posit_log64 posit_log64_arccos(posit_log64);

/* Arccosine Over π */
posit8 posit8_arccos_over_pi(posit8);
posit16 posit16_arccos_over_pi(posit16);
posit32 posit32_arccos_over_pi(posit32);
posit64 posit64_arccos_over_pi(posit64);

posit_log8 posit_log8_arccos_over_pi(posit_log8);
posit_log16 posit_log16_arccos_over_pi(posit_log16);
posit_log32 posit_log32_arccos_over_pi(posit_log32);
posit_log64 posit_log64_arccos_over_pi(posit_log64);

/* Arccotangent */
posit8 posit8_arccot(posit8);
posit16 posit16_arccot(posit16);
posit32 posit32_arccot(posit32);
posit64 posit64_arccot(posit64);

posit_log8 posit_log8_arccot(posit_log8);
posit_log16 posit_log16_arccot(posit_log16);
posit_log32 posit_log32_arccot(posit_log32);
posit_log64 posit_log64_arccot(posit_log64);

/* Arccotangent Over π */
posit8 posit8_arccot_over_pi(posit8);
posit16 posit16_arccot_over_pi(posit16);
posit32 posit32_arccot_over_pi(posit32);
posit64 posit64_arccot_over_pi(posit64);

posit_log8 posit_log8_arccot_over_pi(posit_log8);
posit_log16 posit_log16_arccot_over_pi(posit_log16);
posit_log32 posit_log32_arccot_over_pi(posit_log32);
posit_log64 posit_log64_arccot_over_pi(posit_log64);

/* Arccosecant */
posit8 posit8_arccsc(posit8);
posit16 posit16_arccsc(posit16);
posit32 posit32_arccsc(posit32);
posit64 posit64_arccsc(posit64);

posit_log8 posit_log8_arccsc(posit_log8);
posit_log16 posit_log16_arccsc(posit_log16);
posit_log32 posit_log32_arccsc(posit_log32);
posit_log64 posit_log64_arccsc(posit_log64);

/* Arccosecant Over π */
posit8 posit8_arccsc_over_pi(posit8);
posit16 posit16_arccsc_over_pi(posit16);
posit32 posit32_arccsc_over_pi(posit32);
posit64 posit64_arccsc_over_pi(posit64);

posit_log8 posit_log8_arccsc_over_pi(posit_log8);
posit_log16 posit_log16_arccsc_over_pi(posit_log16);
posit_log32 posit_log32_arccsc_over_pi(posit_log32);
posit_log64 posit_log64_arccsc_over_pi(posit_log64);

/* Area Hyperbolic Cosine */
posit8 posit8_arcosh(posit8);
posit16 posit16_arcosh(posit16);
posit32 posit32_arcosh(posit32);
posit64 posit64_arcosh(posit64);

posit_log8 posit_log8_arcosh(posit_log8);
posit_log16 posit_log16_arcosh(posit_log16);
posit_log32 posit_log32_arcosh(posit_log32);
posit_log64 posit_log64_arcosh(posit_log64);

/* Area Hyperbolic Cotangent */
posit8 posit8_arcoth(posit8);
posit16 posit16_arcoth(posit16);
posit32 posit32_arcoth(posit32);
posit64 posit64_arcoth(posit64);

posit_log8 posit_log8_arcoth(posit_log8);
posit_log16 posit_log16_arcoth(posit_log16);
posit_log32 posit_log32_arcoth(posit_log32);
posit_log64 posit_log64_arcoth(posit_log64);

/* Area Hyperbolic Cosecant */
posit8 posit8_arcsch(posit8);
posit16 posit16_arcsch(posit16);
posit32 posit32_arcsch(posit32);
posit64 posit64_arcsch(posit64);

posit_log8 posit_log8_arcsch(posit_log8);
posit_log16 posit_log16_arcsch(posit_log16);
posit_log32 posit_log32_arcsch(posit_log32);
posit_log64 posit_log64_arcsch(posit_log64);

/* Arcsecant */
posit8 posit8_arcsec(posit8);
posit16 posit16_arcsec(posit16);
posit32 posit32_arcsec(posit32);
posit64 posit64_arcsec(posit64);

posit_log8 posit_log8_arcsec(posit_log8);
posit_log16 posit_log16_arcsec(posit_log16);
posit_log32 posit_log32_arcsec(posit_log32);
posit_log64 posit_log64_arcsec(posit_log64);

/* Arcsecant Over π */
posit8 posit8_arcsec_over_pi(posit8);
posit16 posit16_arcsec_over_pi(posit16);
posit32 posit32_arcsec_over_pi(posit32);
posit64 posit64_arcsec_over_pi(posit64);

posit_log8 posit_log8_arcsec_over_pi(posit_log8);
posit_log16 posit_log16_arcsec_over_pi(posit_log16);
posit_log32 posit_log32_arcsec_over_pi(posit_log32);
posit_log64 posit_log64_arcsec_over_pi(posit_log64);

/* Arcsine */
posit8 posit8_arcsin(posit8);
posit16 posit16_arcsin(posit16);
posit32 posit32_arcsin(posit32);
posit64 posit64_arcsin(posit64);

posit_log8 posit_log8_arcsin(posit_log8);
posit_log16 posit_log16_arcsin(posit_log16);
posit_log32 posit_log32_arcsin(posit_log32);
posit_log64 posit_log64_arcsin(posit_log64);

/* Arcsine Over π */
posit8 posit8_arcsin_over_pi(posit8);
posit16 posit16_arcsin_over_pi(posit16);
posit32 posit32_arcsin_over_pi(posit32);
posit64 posit64_arcsin_over_pi(posit64);

posit_log8 posit_log8_arcsin_over_pi(posit_log8);
posit_log16 posit_log16_arcsin_over_pi(posit_log16);
posit_log32 posit_log32_arcsin_over_pi(posit_log32);
posit_log64 posit_log64_arcsin_over_pi(posit_log64);

/* 2-Argument Arctangent */
posit8 posit8_arctan2(posit8, posit8);
posit16 posit16_arctan2(posit16, posit16);
posit32 posit32_arctan2(posit32, posit32);
posit64 posit64_arctan2(posit64, posit64);

posit_log8 posit_log8_arctan2(posit_log8, posit_log8);
posit_log16 posit_log16_arctan2(posit_log16, posit_log16);
posit_log32 posit_log32_arctan2(posit_log32, posit_log32);
posit_log64 posit_log64_arctan2(posit_log64, posit_log64);

/* 2-Argument Arctangent Over π */
posit8 posit8_arctan2_over_pi(posit8, posit8);
posit16 posit16_arctan2_over_pi(posit16, posit16);
posit32 posit32_arctan2_over_pi(posit32, posit32);
posit64 posit64_arctan2_over_pi(posit64, posit64);

posit_log8 posit_log8_arctan2_over_pi(posit_log8, posit_log8);
posit_log16 posit_log16_arctan2_over_pi(posit_log16, posit_log16);
posit_log32 posit_log32_arctan2_over_pi(posit_log32, posit_log32);
posit_log64 posit_log64_arctan2_over_pi(posit_log64, posit_log64);

/* Arctangent */
posit8 posit8_arctan(posit8);
posit16 posit16_arctan(posit16);
posit32 posit32_arctan(posit32);
posit64 posit64_arctan(posit64);

posit_log8 posit_log8_arctan(posit_log8);
posit_log16 posit_log16_arctan(posit_log16);
posit_log32 posit_log32_arctan(posit_log32);
posit_log64 posit_log64_arctan(posit_log64);

/* Arctangent Over π */
posit8 posit8_arctan_over_pi(posit8);
posit16 posit16_arctan_over_pi(posit16);
posit32 posit32_arctan_over_pi(posit32);
posit64 posit64_arctan_over_pi(posit64);

posit_log8 posit_log8_arctan_over_pi(posit_log8);
posit_log16 posit_log16_arctan_over_pi(posit_log16);
posit_log32 posit_log32_arctan_over_pi(posit_log32);
posit_log64 posit_log64_arctan_over_pi(posit_log64);

/* Area Hyperbolic Secant */
posit8 posit8_arsech(posit8);
posit16 posit16_arsech(posit16);
posit32 posit32_arsech(posit32);
posit64 posit64_arsech(posit64);

posit_log8 posit_log8_arsech(posit_log8);
posit_log16 posit_log16_arsech(posit_log16);
posit_log32 posit_log32_arsech(posit_log32);
posit_log64 posit_log64_arsech(posit_log64);

/* Area Hyperbolic Sine */
posit8 posit8_arsinh(posit8);
posit16 posit16_arsinh(posit16);
posit32 posit32_arsinh(posit32);
posit64 posit64_arsinh(posit64);

posit_log8 posit_log8_arsinh(posit_log8);
posit_log16 posit_log16_arsinh(posit_log16);
posit_log32 posit_log32_arsinh(posit_log32);
posit_log64 posit_log64_arsinh(posit_log64);

/* Area Hyperbolic Tangent */
posit8 posit8_artanh(posit8);
posit16 posit16_artanh(posit16);
posit32 posit32_artanh(posit32);
posit64 posit64_artanh(posit64);

posit_log8 posit_log8_artanh(posit_log8);
posit_log16 posit_log16_artanh(posit_log16);
posit_log32 posit_log32_artanh(posit_log32);
posit_log64 posit_log64_artanh(posit_log64);

/* Cosine */
posit8 posit8_cos(posit8);
posit16 posit16_cos(posit16);
posit32 posit32_cos(posit32);
posit64 posit64_cos(posit64);

posit_log8 posit_log8_cos(posit_log8);
posit_log16 posit_log16_cos(posit_log16);
posit_log32 posit_log32_cos(posit_log32);
posit_log64 posit_log64_cos(posit_log64);

/* Cosine π Times */
posit8 posit8_cos_pi_times(posit8);
posit16 posit16_cos_pi_times(posit16);
posit32 posit32_cos_pi_times(posit32);
posit64 posit64_cos_pi_times(posit64);

posit_log8 posit_log8_cos_pi_times(posit_log8);
posit_log16 posit_log16_cos_pi_times(posit_log16);
posit_log32 posit_log32_cos_pi_times(posit_log32);
posit_log64 posit_log64_cos_pi_times(posit_log64);

/* Hyperbolic Cosine */
posit8 posit8_cosh(posit8);
posit16 posit16_cosh(posit16);
posit32 posit32_cosh(posit32);
posit64 posit64_cosh(posit64);

posit_log8 posit_log8_cosh(posit_log8);
posit_log16 posit_log16_cosh(posit_log16);
posit_log32 posit_log32_cosh(posit_log32);
posit_log64 posit_log64_cosh(posit_log64);

/* Cotangent */
posit8 posit8_cot(posit8);
posit16 posit16_cot(posit16);
posit32 posit32_cot(posit32);
posit64 posit64_cot(posit64);

posit_log8 posit_log8_cot(posit_log8);
posit_log16 posit_log16_cot(posit_log16);
posit_log32 posit_log32_cot(posit_log32);
posit_log64 posit_log64_cot(posit_log64);

/* Cotangent π Times */
posit8 posit8_cot_pi_times(posit8);
posit16 posit16_cot_pi_times(posit16);
posit32 posit32_cot_pi_times(posit32);
posit64 posit64_cot_pi_times(posit64);

posit_log8 posit_log8_cot_pi_times(posit_log8);
posit_log16 posit_log16_cot_pi_times(posit_log16);
posit_log32 posit_log32_cot_pi_times(posit_log32);
posit_log64 posit_log64_cot_pi_times(posit_log64);

/* Hyperbolic Cotangent */
posit8 posit8_coth(posit8);
posit16 posit16_coth(posit16);
posit32 posit32_coth(posit32);
posit64 posit64_coth(posit64);

posit_log8 posit_log8_coth(posit_log8);
posit_log16 posit_log16_coth(posit_log16);
posit_log32 posit_log32_coth(posit_log32);
posit_log64 posit_log64_coth(posit_log64);

/* Cosecant */
posit8 posit8_csc(posit8);
posit16 posit16_csc(posit16);
posit32 posit32_csc(posit32);
posit64 posit64_csc(posit64);

posit_log8 posit_log8_csc(posit_log8);
posit_log16 posit_log16_csc(posit_log16);
posit_log32 posit_log32_csc(posit_log32);
posit_log64 posit_log64_csc(posit_log64);

/* Cosecant π Times */
posit8 posit8_csc_pi_times(posit8);
posit16 posit16_csc_pi_times(posit16);
posit32 posit32_csc_pi_times(posit32);
posit64 posit64_csc_pi_times(posit64);

posit_log8 posit_log8_csc_pi_times(posit_log8);
posit_log16 posit_log16_csc_pi_times(posit_log16);
posit_log32 posit_log32_csc_pi_times(posit_log32);
posit_log64 posit_log64_csc_pi_times(posit_log64);

/* Hyperbolic Cosecant */
posit8 posit8_csch(posit8);
posit16 posit16_csch(posit16);
posit32 posit32_csch(posit32);
posit64 posit64_csch(posit64);

posit_log8 posit_log8_csch(posit_log8);
posit_log16 posit_log16_csch(posit_log16);
posit_log32 posit_log32_csch(posit_log32);
posit_log64 posit_log64_csch(posit_log64);

/* Division */
posit8 posit8_division(posit8, posit8);
posit16 posit16_division(posit16, posit16);
posit32 posit32_division(posit32, posit32);
posit64 posit64_division(posit64, posit64);

posit_log8 posit_log8_division(posit_log8, posit_log8);
posit_log16 posit_log16_division(posit_log16, posit_log16);
posit_log32 posit_log32_division(posit_log32, posit_log32);
posit_log64 posit_log64_division(posit_log64, posit_log64);

/* Exponential Function */
posit8 posit8_exp(posit8);
posit16 posit16_exp(posit16);
posit32 posit32_exp(posit32);
posit64 posit64_exp(posit64);

posit_log8 posit_log8_exp(posit_log8);
posit_log16 posit_log16_exp(posit_log16);
posit_log32 posit_log32_exp(posit_log32);
posit_log64 posit_log64_exp(posit_log64);

/* Exponential Function Minus 1 */
posit8 posit8_exp_minus_1(posit8);
posit16 posit16_exp_minus_1(posit16);
posit32 posit32_exp_minus_1(posit32);
posit64 posit64_exp_minus_1(posit64);

posit_log8 posit_log8_exp_minus_1(posit_log8);
posit_log16 posit_log16_exp_minus_1(posit_log16);
posit_log32 posit_log32_exp_minus_1(posit_log32);
posit_log64 posit_log64_exp_minus_1(posit_log64);

/* Conversion from extended float */
posit8 posit8_from_extended_float(long double);
posit16 posit16_from_extended_float(long double);
posit32 posit32_from_extended_float(long double);
posit64 posit64_from_extended_float(long double);

posit_log8 posit_log8_from_extended_float(long double);
posit_log16 posit_log16_from_extended_float(long double);
posit_log32 posit_log32_from_extended_float(long double);
posit_log64 posit_log64_from_extended_float(long double);

/* Conversion from float32 */
posit8 posit8_from_float32(float);
posit16 posit16_from_float32(float);
posit32 posit32_from_float32(float);
posit64 posit64_from_float32(float);

posit_log8 posit_log8_from_float32(float);
posit_log16 posit_log16_from_float32(float);
posit_log32 posit_log32_from_float32(float);
posit_log64 posit_log64_from_float32(float);

/* Conversion from float64 */
posit8 posit8_from_float64(double);
posit16 posit16_from_float64(double);
posit32 posit32_from_float64(double);
posit64 posit64_from_float64(double);

posit_log8 posit_log8_from_float64(double);
posit_log16 posit_log16_from_float64(double);
posit_log32 posit_log32_from_float64(double);
posit_log64 posit_log64_from_float64(double);

/* Conversion from posit8 */
posit16 posit16_from_posit8(posit8);
posit32 posit32_from_posit8(posit8);
posit64 posit64_from_posit8(posit8);

posit_log8 posit_log8_from_posit8(posit8);
posit_log16 posit_log16_from_posit8(posit8);
posit_log32 posit_log32_from_posit8(posit8);
posit_log64 posit_log64_from_posit8(posit8);

/* Conversion from posit16 */
posit8 posit8_from_posit16(posit16);
posit32 posit32_from_posit16(posit16);
posit64 posit64_from_posit16(posit16);

posit_log8 posit_log8_from_posit16(posit16);
posit_log16 posit_log16_from_posit16(posit16);
posit_log32 posit_log32_from_posit16(posit16);
posit_log64 posit_log64_from_posit16(posit16);

/* Conversion from posit32 */
posit8 posit8_from_posit32(posit32);
posit16 posit16_from_posit32(posit32);
posit64 posit64_from_posit32(posit32);

posit_log8 posit_log8_from_posit32(posit32);
posit_log16 posit_log16_from_posit32(posit32);
posit_log32 posit_log32_from_posit32(posit32);
posit_log64 posit_log64_from_posit32(posit32);

/* Conversion from posit64 */
posit8 posit8_from_posit64(posit64);
posit16 posit16_from_posit64(posit64);
posit32 posit32_from_posit64(posit64);

posit_log8 posit_log8_from_posit64(posit64);
posit_log16 posit_log16_from_posit64(posit64);
posit_log32 posit_log32_from_posit64(posit64);
posit_log64 posit_log64_from_posit64(posit64);

/* Conversion from posit_log8 */
posit8 posit8_from_posit_log8(posit_log8 t);
posit16 posit16_from_posit_log8(posit_log8 t);
posit32 posit32_from_posit_log8(posit_log8 t);
posit64 posit64_from_posit_log8(posit_log8 t);

posit_log16 posit_log16_from_posit_log8(posit_log8);
posit_log32 posit_log32_from_posit_log8(posit_log8);
posit_log64 posit_log64_from_posit_log8(posit_log8);

/* Conversion from posit_log16 */
posit8 posit8_from_posit_log16(posit_log16 t);
posit16 posit16_from_posit_log16(posit_log16 t);
posit32 posit32_from_posit_log16(posit_log16 t);
posit64 posit64_from_posit_log16(posit_log16 t);

posit_log8 posit_log8_from_posit_log16(posit_log16);
posit_log32 posit_log32_from_posit_log16(posit_log16);
posit_log64 posit_log64_from_posit_log16(posit_log16);

/* Conversion from posit_log32 */
posit8 posit8_from_posit_log32(posit_log32 t);
posit16 posit16_from_posit_log32(posit_log32 t);
posit32 posit32_from_posit_log32(posit_log32 t);
posit64 posit64_from_posit_log32(posit_log32 t);

posit_log8 posit_log8_from_posit_log32(posit_log32);
posit_log16 posit_log16_from_posit_log32(posit_log32);
posit_log64 posit_log64_from_posit_log32(posit_log32);

/* Conversion from posit_log64 */
posit8 posit8_from_posit_log64(posit_log64 t);
posit16 posit16_from_posit_log64(posit_log64 t);
posit32 posit32_from_posit_log64(posit_log64 t);
posit64 posit64_from_posit_log64(posit_log64 t);

posit_log8 posit_log8_from_posit_log64(posit_log64);
posit_log16 posit_log16_from_posit_log64(posit_log64);
posit_log32 posit_log32_from_posit_log64(posit_log64);

/* Hypotenuse sqrt(a^2+b^2) */
posit8 posit8_hypotenuse(posit8, posit8);
posit16 posit16_hypotenuse(posit16, posit16);
posit32 posit32_hypotenuse(posit32, posit32);
posit64 posit64_hypotenuse(posit64, posit64);

posit_log8 posit_log8_hypotenuse(posit_log8, posit_log8);
posit_log16 posit_log16_hypotenuse(posit_log16, posit_log16);
posit_log32 posit_log32_hypotenuse(posit_log32, posit_log32);
posit_log64 posit_log64_hypotenuse(posit_log64, posit_log64);

/* Integer Power */
posit8 posit8_integer_power(posit8, int64_t);
posit16 posit16_integer_power(posit16, int64_t);
posit32 posit32_integer_power(posit32, int64_t);
posit64 posit64_integer_power(posit64, int64_t);

posit_log8 posit_log8_integer_power(posit_log8, int64_t);
posit_log16 posit_log16_integer_power(posit_log16, int64_t);
posit_log32 posit_log32_integer_power(posit_log32, int64_t);
posit_log64 posit_log64_integer_power(posit_log64, int64_t);

/* Integer Root */
posit8 posit8_root(posit8, int64_t);
posit16 posit16_root(posit16, int64_t);
posit32 posit32_root(posit32, int64_t);
posit64 posit64_root(posit64, int64_t);

posit_log8 posit_log8_root(posit_log8, int64_t);
posit_log16 posit_log16_root(posit_log16, int64_t);
posit_log32 posit_log32_root(posit_log32, int64_t);
posit_log64 posit_log64_root(posit_log64, int64_t);

/* Inversion */
posit8 posit8_inversion(posit8);
posit16 posit16_inversion(posit16);
posit32 posit32_inversion(posit32);
posit64 posit64_inversion(posit64);

posit_log8 posit_log8_inversion(posit_log8);
posit_log16 posit_log16_inversion(posit_log16);
posit_log32 posit_log32_inversion(posit_log32);
posit_log64 posit_log64_inversion(posit_log64);

/* Binary Logarithm (following ISO 80000) */
posit8 posit8_lb(posit8);
posit16 posit16_lb(posit16);
posit32 posit32_lb(posit32);
posit64 posit64_lb(posit64);

posit_log8 posit_log8_lb(posit_log8);
posit_log16 posit_log16_lb(posit_log16);
posit_log32 posit_log32_lb(posit_log32);
posit_log64 posit_log64_lb(posit_log64);

/* Binary Logarithm 1 Plus (following ISO 80000) */
posit8 posit8_lb_1_plus(posit8);
posit16 posit16_lb_1_plus(posit16);
posit32 posit32_lb_1_plus(posit32);
posit64 posit64_lb_1_plus(posit64);

posit_log8 posit_log8_lb_1_plus(posit_log8);
posit_log16 posit_log16_lb_1_plus(posit_log16);
posit_log32 posit_log32_lb_1_plus(posit_log32);
posit_log64 posit_log64_lb_1_plus(posit_log64);

/* Decadic Logarithm (following ISO 80000) */
posit8 posit8_lg(posit8);
posit16 posit16_lg(posit16);
posit32 posit32_lg(posit32);
posit64 posit64_lg(posit64);

posit_log8 posit_log8_lg(posit_log8);
posit_log16 posit_log16_lg(posit_log16);
posit_log32 posit_log32_lg(posit_log32);
posit_log64 posit_log64_lg(posit_log64);

/* Decadic Logarithm 1 Plus (following ISO 80000) */
posit8 posit8_lg_1_plus(posit8);
posit16 posit16_lg_1_plus(posit16);
posit32 posit32_lg_1_plus(posit32);
posit64 posit64_lg_1_plus(posit64);

posit_log8 posit_log8_lg_1_plus(posit_log8);
posit_log16 posit_log16_lg_1_plus(posit_log16);
posit_log32 posit_log32_lg_1_plus(posit_log32);
posit_log64 posit_log64_lg_1_plus(posit_log64);

/* Natural Logarithm (following ISO 80000) */
posit8 posit8_ln(posit8);
posit16 posit16_ln(posit16);
posit32 posit32_ln(posit32);
posit64 posit64_ln(posit64);

posit_log8 posit_log8_ln(posit_log8);
posit_log16 posit_log16_ln(posit_log16);
posit_log32 posit_log32_ln(posit_log32);
posit_log64 posit_log64_ln(posit_log64);

/* Natural Logarithm 1 Plus (following ISO 80000) */
posit8 posit8_ln_1_plus(posit8);
posit16 posit16_ln_1_plus(posit16);
posit32 posit32_ln_1_plus(posit32);
posit64 posit64_ln_1_plus(posit64);

posit_log8 posit_log8_ln_1_plus(posit_log8);
posit_log16 posit_log16_ln_1_plus(posit_log16);
posit_log32 posit_log32_ln_1_plus(posit_log32);
posit_log64 posit_log64_ln_1_plus(posit_log64);

/* Multiplication */
posit8 posit8_multiplication(posit8, posit8);
posit16 posit16_multiplication(posit16, posit16);
posit32 posit32_multiplication(posit32, posit32);
posit64 posit64_multiplication(posit64, posit64);

posit_log8 posit_log8_multiplication(posit_log8, posit_log8);
posit_log16 posit_log16_multiplication(posit_log16, posit_log16);
posit_log32 posit_log32_multiplication(posit_log32, posit_log32);
posit_log64 posit_log64_multiplication(posit_log64, posit_log64);

/* Power */
posit8 posit8_power(posit8, posit8);
posit16 posit16_power(posit16, posit16);
posit32 posit32_power(posit32, posit32);
posit64 posit64_power(posit64, posit64);

posit_log8 posit_log8_power(posit_log8, posit_log8);
posit_log16 posit_log16_power(posit_log16, posit_log16);
posit_log32 posit_log32_power(posit_log32, posit_log32);
posit_log64 posit_log64_power(posit_log64, posit_log64);

/* Precision */
uint8_t posit8_precision(posit8);
uint8_t posit16_precision(posit16);
uint8_t posit32_precision(posit32);
uint8_t posit64_precision(posit64);

uint8_t posit_log8_precision(posit_log8);
uint8_t posit_log16_precision(posit_log16);
uint8_t posit_log32_precision(posit_log32);
uint8_t posit_log64_precision(posit_log64);

/* Secant */
posit8 posit8_sec(posit8);
posit16 posit16_sec(posit16);
posit32 posit32_sec(posit32);
posit64 posit64_sec(posit64);

posit_log8 posit_log8_sec(posit_log8);
posit_log16 posit_log16_sec(posit_log16);
posit_log32 posit_log32_sec(posit_log32);
posit_log64 posit_log64_sec(posit_log64);

/* Secant π Times */
posit8 posit8_sec_pi_times(posit8);
posit16 posit16_sec_pi_times(posit16);
posit32 posit32_sec_pi_times(posit32);
posit64 posit64_sec_pi_times(posit64);

posit_log8 posit_log8_sec_pi_times(posit_log8);
posit_log16 posit_log16_sec_pi_times(posit_log16);
posit_log32 posit_log32_sec_pi_times(posit_log32);
posit_log64 posit_log64_sec_pi_times(posit_log64);

/* Hyperbolic Secant */
posit8 posit8_sech(posit8);
posit16 posit16_sech(posit16);
posit32 posit32_sech(posit32);
posit64 posit64_sech(posit64);

posit_log8 posit_log8_sech(posit_log8);
posit_log16 posit_log16_sech(posit_log16);
posit_log32 posit_log32_sech(posit_log32);
posit_log64 posit_log64_sech(posit_log64);

/* Sign */
posit8 posit8_sign(posit8);
posit16 posit16_sign(posit16);
posit32 posit32_sign(posit32);
posit64 posit64_sign(posit64);

posit_log8 posit_log8_sign(posit_log8);
posit_log16 posit_log16_sign(posit_log16);
posit_log32 posit_log32_sign(posit_log32);
posit_log64 posit_log64_sign(posit_log64);

/* Sine */
posit8 posit8_sin(posit8);
posit16 posit16_sin(posit16);
posit32 posit32_sin(posit32);
posit64 posit64_sin(posit64);

posit_log8 posit_log8_sin(posit_log8);
posit_log16 posit_log16_sin(posit_log16);
posit_log32 posit_log32_sin(posit_log32);
posit_log64 posit_log64_sin(posit_log64);

/* Sine π Times */
posit8 posit8_sin_pi_times(posit8);
posit16 posit16_sin_pi_times(posit16);
posit32 posit32_sin_pi_times(posit32);
posit64 posit64_sin_pi_times(posit64);

posit_log8 posit_log8_sin_pi_times(posit_log8);
posit_log16 posit_log16_sin_pi_times(posit_log16);
posit_log32 posit_log32_sin_pi_times(posit_log32);
posit_log64 posit_log64_sin_pi_times(posit_log64);

/* Hyperbolic Sine */
posit8 posit8_sinh(posit8);
posit16 posit16_sinh(posit16);
posit32 posit32_sinh(posit32);
posit64 posit64_sinh(posit64);

posit_log8 posit_log8_sinh(posit_log8);
posit_log16 posit_log16_sinh(posit_log16);
posit_log32 posit_log32_sinh(posit_log32);
posit_log64 posit_log64_sinh(posit_log64);

/* Square Root */
posit8 posit8_square_root(posit8);
posit16 posit16_square_root(posit16);
posit32 posit32_square_root(posit32);
posit64 posit64_square_root(posit64);

posit_log8 posit_log8_square_root(posit_log8);
posit_log16 posit_log16_square_root(posit_log16);
posit_log32 posit_log32_square_root(posit_log32);
posit_log64 posit_log64_square_root(posit_log64);

/* Subtraction */
posit8 posit8_subtraction(posit8, posit8);
posit16 posit16_subtraction(posit16, posit16);
posit32 posit32_subtraction(posit32, posit32);
posit64 posit64_subtraction(posit64, posit64);

posit_log8 posit_log8_subtraction(posit_log8, posit_log8);
posit_log16 posit_log16_subtraction(posit_log16, posit_log16);
posit_log32 posit_log32_subtraction(posit_log32, posit_log32);
posit_log64 posit_log64_subtraction(posit_log64, posit_log64);

/* Tangent */
posit8 posit8_tan(posit8);
posit16 posit16_tan(posit16);
posit32 posit32_tan(posit32);
posit64 posit64_tan(posit64);

posit_log8 posit_log8_tan(posit_log8);
posit_log16 posit_log16_tan(posit_log16);
posit_log32 posit_log32_tan(posit_log32);
posit_log64 posit_log64_tan(posit_log64);

/* Tangent π Times */
posit8 posit8_tan_pi_times(posit8);
posit16 posit16_tan_pi_times(posit16);
posit32 posit32_tan_pi_times(posit32);
posit64 posit64_tan_pi_times(posit64);

posit_log8 posit_log8_tan_pi_times(posit_log8);
posit_log16 posit_log16_tan_pi_times(posit_log16);
posit_log32 posit_log32_tan_pi_times(posit_log32);
posit_log64 posit_log64_tan_pi_times(posit_log64);

/* Hyperbolic Tangent */
posit8 posit8_tanh(posit8);
posit16 posit16_tanh(posit16);
posit32 posit32_tanh(posit32);
posit64 posit64_tanh(posit64);

posit_log8 posit_log8_tanh(posit_log8);
posit_log16 posit_log16_tanh(posit_log16);
posit_log32 posit_log32_tanh(posit_log32);
posit_log64 posit_log64_tanh(posit_log64);

/* Conversion to extended float */
long double posit8_to_extended_float(posit8);
long double posit16_to_extended_float(posit16);
long double posit32_to_extended_float(posit32);
long double posit64_to_extended_float(posit64);

long double posit_log8_to_extended_float(posit_log8);
long double posit_log16_to_extended_float(posit_log16);
long double posit_log32_to_extended_float(posit_log32);
long double posit_log64_to_extended_float(posit_log64);

/* Conversion to float32 */
float posit8_to_float32(posit8);
float posit16_to_float32(posit16);
float posit32_to_float32(posit32);
float posit64_to_float32(posit64);

float posit_log8_to_float32(posit_log8);
float posit_log16_to_float32(posit_log16);
float posit_log32_to_float32(posit_log32);
float posit_log64_to_float32(posit_log64);

/* Conversion to float64 */
double posit8_to_float64(posit8);
double posit16_to_float64(posit16);
double posit32_to_float64(posit32);
double posit64_to_float64(posit64);

double posit_log8_to_float64(posit_log8);
double posit_log16_to_float64(posit_log16);
double posit_log32_to_float64(posit_log32);
double posit_log64_to_float64(posit_log64);

#endif /* POSIT_H */
