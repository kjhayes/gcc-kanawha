/****************************************************************************
 *                                                                          *
 *                         GNAT COMPILER COMPONENTS                         *
 *                                                                          *
 *                                 RUNTIME                                  *
 *                                                                          *
 *                              C Header File                               *
 *                                                                          *
 *          Copyright (C) 2019-2025, Free Software Foundation, Inc.         *
 *                                                                          *
 * GNAT is free software;  you can  redistribute it  and/or modify it under *
 * terms of the  GNU General Public License as published  by the Free Soft- *
 * ware  Foundation;  either version 3,  or (at your option) any later ver- *
 * sion.  GNAT is distributed in the hope that it will be useful, but WITH- *
 * OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE.                                     *
 *                                                                          *
 * As a special exception under Section 7 of GPL version 3, you are granted *
 * additional permissions described in the GCC Runtime Library Exception,   *
 * version 3.1, as published by the Free Software Foundation.               *
 *                                                                          *
 * You should have received a copy of the GNU General Public License and    *
 * a copy of the GCC Runtime Library Exception along with this program;     *
 * see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see    *
 * <http://www.gnu.org/licenses/>.                                          *
 *                                                                          *
 * GNAT was originally developed  by the GNAT team at  New York University. *
 * Extensive contributions were provided by Ada Core Technologies Inc.      *
 *                                                                          *
 ****************************************************************************/

/* This file provides common definitions used by GNAT C runtime files.  */

/* The following include is here to meet the published VxWorks requirement
   that the vxWorks.h header appear before any other header.  */
#ifdef __vxworks
#include "vxWorks.h"
#endif

#ifndef ATTRIBUTE_UNUSED
#define ATTRIBUTE_UNUSED __attribute__((unused))
#endif

#ifndef ATTRIBUTE_NORETURN
#define ATTRIBUTE_NORETURN __attribute__((noreturn))
#endif
