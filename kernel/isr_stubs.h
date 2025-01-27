/*
 *    __  __                      
 *   |  \/  |__ _ __ _ _ __  __ _ 
 *   | |\/| / _` / _` | '  \/ _` |
 *   |_|  |_\__,_\__, |_|_|_\__,_|
 *               |___/        
 * 
 *  Magma is a UNIX-like operating system that consists of a kernel written in C and
 *  i?86 assembly, and userland binaries written in C.
 *     
 *  Copyright (c) 2023 Nexuss, John Paul Wohlscheid, rilysh, Milton612, and FueledByCocaine
 * 
 *  This file may or may not contain code from https://github.com/mosmeh/yagura, and/or
 *  https://github.com/mit-pdos/xv6-public. Both projects have the same license as this
 *  project, and the license can be seen below:
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#pragma once

/*
 *  Not sure if this is i?86-exclusive, so we're making this for i?86
 *  only (for now).
 */

#if defined(__i386__)
#define ENUMERATE_ISR_STUBS(F)                                                 \
    F(17)                                                                      \
    F(18)                                                                      \
    F(19)                                                                      \
    F(20)                                                                      \
    F(21)                                                                      \
    F(22)                                                                      \
    F(23)                                                                      \
    F(24)                                                                      \
    F(25)                                                                      \
    F(26)                                                                      \
    F(27)                                                                      \
    F(28)                                                                      \
    F(29)                                                                      \
    F(30)                                                                      \
    F(31)                                                                      \
    F(32)                                                                      \
    F(33)                                                                      \
    F(34)                                                                      \
    F(35)                                                                      \
    F(36)                                                                      \
    F(37)                                                                      \
    F(38)                                                                      \
    F(39)                                                                      \
    F(40)                                                                      \
    F(41)                                                                      \
    F(42)                                                                      \
    F(43)                                                                      \
    F(44)                                                                      \
    F(45)                                                                      \
    F(46)                                                                      \
    F(47)                                                                      \
    F(48)                                                                      \
    F(49)                                                                      \
    F(50)                                                                      \
    F(51)                                                                      \
    F(52)                                                                      \
    F(53)                                                                      \
    F(54)                                                                      \
    F(55)                                                                      \
    F(56)                                                                      \
    F(57)                                                                      \
    F(58)                                                                      \
    F(59)                                                                      \
    F(60)                                                                      \
    F(61)                                                                      \
    F(62)                                                                      \
    F(63)                                                                      \
    F(64)                                                                      \
    F(65)                                                                      \
    F(66)                                                                      \
    F(67)                                                                      \
    F(68)                                                                      \
    F(69)                                                                      \
    F(70)                                                                      \
    F(71)                                                                      \
    F(72)                                                                      \
    F(73)                                                                      \
    F(74)                                                                      \
    F(75)                                                                      \
    F(76)                                                                      \
    F(77)                                                                      \
    F(78)                                                                      \
    F(79)                                                                      \
    F(80)                                                                      \
    F(81)                                                                      \
    F(82)                                                                      \
    F(83)                                                                      \
    F(84)                                                                      \
    F(85)                                                                      \
    F(86)                                                                      \
    F(87)                                                                      \
    F(88)                                                                      \
    F(89)                                                                      \
    F(90)                                                                      \
    F(91)                                                                      \
    F(92)                                                                      \
    F(93)                                                                      \
    F(94)                                                                      \
    F(95)                                                                      \
    F(96)                                                                      \
    F(97)                                                                      \
    F(98)                                                                      \
    F(99)                                                                      \
    F(100)                                                                     \
    F(101)                                                                     \
    F(102)                                                                     \
    F(103)                                                                     \
    F(104)                                                                     \
    F(105)                                                                     \
    F(106)                                                                     \
    F(107)                                                                     \
    F(108)                                                                     \
    F(109)                                                                     \
    F(110)                                                                     \
    F(111)                                                                     \
    F(112)                                                                     \
    F(113)                                                                     \
    F(114)                                                                     \
    F(115)                                                                     \
    F(116)                                                                     \
    F(117)                                                                     \
    F(118)                                                                     \
    F(119)                                                                     \
    F(120)                                                                     \
    F(121)                                                                     \
    F(122)                                                                     \
    F(123)                                                                     \
    F(124)                                                                     \
    F(125)                                                                     \
    F(126)                                                                     \
    F(127)                                                                     \
    F(128)                                                                     \
    F(129)                                                                     \
    F(130)                                                                     \
    F(131)                                                                     \
    F(132)                                                                     \
    F(133)                                                                     \
    F(134)                                                                     \
    F(135)                                                                     \
    F(136)                                                                     \
    F(137)                                                                     \
    F(138)                                                                     \
    F(139)                                                                     \
    F(140)                                                                     \
    F(141)                                                                     \
    F(142)                                                                     \
    F(143)                                                                     \
    F(144)                                                                     \
    F(145)                                                                     \
    F(146)                                                                     \
    F(147)                                                                     \
    F(148)                                                                     \
    F(149)                                                                     \
    F(150)                                                                     \
    F(151)                                                                     \
    F(152)                                                                     \
    F(153)                                                                     \
    F(154)                                                                     \
    F(155)                                                                     \
    F(156)                                                                     \
    F(157)                                                                     \
    F(158)                                                                     \
    F(159)                                                                     \
    F(160)                                                                     \
    F(161)                                                                     \
    F(162)                                                                     \
    F(163)                                                                     \
    F(164)                                                                     \
    F(165)                                                                     \
    F(166)                                                                     \
    F(167)                                                                     \
    F(168)                                                                     \
    F(169)                                                                     \
    F(170)                                                                     \
    F(171)                                                                     \
    F(172)                                                                     \
    F(173)                                                                     \
    F(174)                                                                     \
    F(175)                                                                     \
    F(176)                                                                     \
    F(177)                                                                     \
    F(178)                                                                     \
    F(179)                                                                     \
    F(180)                                                                     \
    F(181)                                                                     \
    F(182)                                                                     \
    F(183)                                                                     \
    F(184)                                                                     \
    F(185)                                                                     \
    F(186)                                                                     \
    F(187)                                                                     \
    F(188)                                                                     \
    F(189)                                                                     \
    F(190)                                                                     \
    F(191)                                                                     \
    F(192)                                                                     \
    F(193)                                                                     \
    F(194)                                                                     \
    F(195)                                                                     \
    F(196)                                                                     \
    F(197)                                                                     \
    F(198)                                                                     \
    F(199)                                                                     \
    F(200)                                                                     \
    F(201)                                                                     \
    F(202)                                                                     \
    F(203)                                                                     \
    F(204)                                                                     \
    F(205)                                                                     \
    F(206)                                                                     \
    F(207)                                                                     \
    F(208)                                                                     \
    F(209)                                                                     \
    F(210)                                                                     \
    F(211)                                                                     \
    F(212)                                                                     \
    F(213)                                                                     \
    F(214)                                                                     \
    F(215)                                                                     \
    F(216)                                                                     \
    F(217)                                                                     \
    F(218)                                                                     \
    F(219)                                                                     \
    F(220)                                                                     \
    F(221)                                                                     \
    F(222)                                                                     \
    F(223)                                                                     \
    F(224)                                                                     \
    F(225)                                                                     \
    F(226)                                                                     \
    F(227)                                                                     \
    F(228)                                                                     \
    F(229)                                                                     \
    F(230)                                                                     \
    F(231)                                                                     \
    F(232)                                                                     \
    F(233)                                                                     \
    F(234)                                                                     \
    F(235)                                                                     \
    F(236)                                                                     \
    F(237)                                                                     \
    F(238)                                                                     \
    F(239)                                                                     \
    F(240)                                                                     \
    F(241)                                                                     \
    F(242)                                                                     \
    F(243)                                                                     \
    F(244)                                                                     \
    F(245)                                                                     \
    F(246)                                                                     \
    F(247)                                                                     \
    F(248)                                                                     \
    F(249)                                                                     \
    F(250)                                                                     \
    F(251)                                                                     \
    F(252)                                                                     \
    F(253)                                                                     \
    F(254)                                                                     \
    F(255)
#endif