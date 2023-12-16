/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:05:31 by hael-mou          #+#    #+#             */
/*   Updated: 2023/12/15 18:13:39 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LINKEDLIST_HPP
# define _LINKEDLIST_HPP

/*#################################################################################
#        Includes:                                                                #
#################################################################################*/
# include "IContainer.hpp"
# include <iostream>
# include <list>
# include <algorithm>

/*#################################################################################
#        Vector Class:                                                            #
#################################################################################*/
class LinkedList : public IContainer {

	public:
		// === typedef : ===================================================
		typedef std::list<unsigned int>							  list_uint;
		typedef std::list<list_uint>::iterator				   mainIterator;
		typedef std::list<list_uint>::const_iterator		  CmainIterator;
		typedef list_uint::iterator							   uintIterator;
		typedef list_uint::const_iterator					  CuintIterator;
		typedef std::list<std::pair<list_uint, mainIterator> >::iterator
															   pendIterator;

		// === Constructor & Destructor : ==================================
		LinkedList(void);
		LinkedList(const LinkedList &other);
		virtual		~LinkedList(void);

		// === Operators : =================================================
		LinkedList&		operator=(const LinkedList &other);

		// === Method : ====================================================
		size_t		size(void) const;
		void		display(void) const;
		void		reserve(size_t __size);
		void		push(unsigned int nbr);
		bool		hasAtLeastTwoPairs(void);
		void		combinePairs(void);
		void		sortPair(void);
		void		splitPairs(void);
		void		CreatePend(void);
		void		InsertPend(void);

	private:
		// ===  Attributes  : ==============================================
		std::list<list_uint>										  mMain;
		std::list< std::pair<list_uint, mainIterator> >				  mPend;
		const static unsigned long					     	 jacobsthal[63];
};

#endif // _LINKEDLIST_HPP
