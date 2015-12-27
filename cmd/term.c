/*** term.c ********************************************************************
** 
** This file is part of BibTool.
** It is distributed under the GNU General Public License.
** See the file COPYING for details.
** 
** (c) 2015 Gerd Neugebauer
** 
** Net: gene@gerd-neugebauer.de
** 
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <bibtool/error.h>
#include "term.h"

/*****************************************************************************/
/* Internal Programs                                                         */
/*===========================================================================*/

#ifdef __STDC__
#define _ARG(A) A
#else
#define _ARG(A) ()
#endif



/*****************************************************************************/
/* External Programs                                                         */
/*===========================================================================*/

/*---------------------------------------------------------------------------*/


 Term term_eof;
 Term term_true;
 Term term_false;
 Term term_mod;

/*-----------------------------------------------------------------------------
** Function:	new_term()
** Type:	Term
** Purpose:	
**		
** Arguments:
**	op	
**	 a1	
**	 a2	
** Returns:	
**___________________________________________________			     */
Term new_term(sym, a1, a2)			   /*                        */
  SymDef sym;				   	   /*                        */
  Term a1;					   /*                        */
  Term a2;					   /*                        */
{						   /*                        */
  Term t = (Term)malloc(sizeof(STerm));		   /*                        */
  if (t == NIL) OUT_OF_MEMORY("term");		   /*                        */
  TSym(t) = sym;			   	   /*                        */
  Car(t) = a1;				   	   /*                        */
  Cdr(t) = a2;				   	   /*                        */
  return t;					   /*                        */
}						   /*------------------------*/

/*-----------------------------------------------------------------------------
** Function:	new_term_num()
** Type:	Term
** Purpose:	
**		
** Arguments:
**	n	
** Returns:	
**___________________________________________________			     */
Term new_term_num(n)				   /*                        */
  long n;					   /*                        */
{						   /*                        */
  Term t     = (Term)malloc(sizeof(STerm));	   /*                        */
  if (t == NIL) OUT_OF_MEMORY("term");		   /*                        */
  TSym(t)    = sym_number;			   /*                        */
  TNumber(t) = n;				   /*                        */
  Cdr(t)     = NIL;				   /*                        */
  return t;					   /*                        */
}						   /*------------------------*/

/*-----------------------------------------------------------------------------
** Function:	new_t_string()
** Type:	Term
** Purpose:	
**		
** Arguments:
**	op	
**	 s	
** Returns:	
**___________________________________________________			     */
Term new_t_string(sym, s)		   	   /*                        */
  SymDef sym;					   /*                        */
  String s;					   /*                        */
{						   /*                        */
  Term t     = (Term)malloc(sizeof(STerm));	   /*                        */
  if (t == NIL) OUT_OF_MEMORY("term");		   /*                        */
  TSym(t)    = sym;			   	   /*                        */
  TString(t) = s;				   /*                        */
  Cdr(t)     = NIL;			   	   /*                        */
  return t;					   /*                        */
}						   /*------------------------*/

/*-----------------------------------------------------------------------------
** Function:	free_term()
** Type:	void
** Purpose:	
**		
** Arguments:
**	t	
** Returns:	nothing
**___________________________________________________			     */
void free_term(t)				   /*                        */
  Term t;					   /*                        */
{						   /*                        */
#ifdef NEVER
  switch (TOp(t))				   /*                        */
  { case STRING:				   /*                        */
    case FIELD:				   	   /*                        */
    case NUMBER:				   /*                        */
      break;					   /*                        */
    default:					   /*                        */
      if (Car(t)) { free_term(Car(t)); } 	   /*                        */
  }						   /*                        */
  if (Cdr(t)) { free_term(Cdr(t)); }   	   	   /*                        */
#endif
  free(t);					   /*                        */
}						   /*------------------------*/

/*-----------------------------------------------------------------------------
** Function:	print_term()
** Type:	void
** Purpose:	
**		
** Arguments:
**	file	
**	 t	
** Returns:	nothing
**___________________________________________________			     */
void print_term(file, t)
  FILE * file;
  Term t;
{
  if (t == NIL) {
    fputs(" nil ", file);
    return;
  }
  if (TSym(t) != NULL && SymPrint(TSym(t)) != NULL) {
    SymPrint(TSym(t))(file, t);
  } else {
    fputs(" ??? ", file);
  }

}
