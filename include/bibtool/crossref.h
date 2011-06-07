/******************************************************************************
** $Id: crossref.h,v 1.3 2011-06-07 20:01:06 gene Exp $
**=============================================================================
** 
** This file is part of BibTool.
** It is distributed under the GNU General Public License.
** See the file COPYING for details.
** 
** (c) 2007-2011 Gerd Neugebauer
** 
** Net: gene@gerd-neugebauer.de
** 
**-----------------------------------------------------------------------------
** Description:
**	This header file makes available the function defined in
**	|crossref.c|. This file includes the header files |database.h| and
**      |record.h|.
******************************************************************************/

#include <bibtool/database.h>
#include <bibtool/record.h>

#ifdef __STDC__
#define _ARG(A) A
#else
#define _ARG(A) ()
#endif
 int expand_crossref _ARG((DB db,Record rec));
