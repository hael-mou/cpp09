/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:05:31 by hael-mou          #+#    #+#             */
/*   Updated: 2023/12/15 18:46:32 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP
# define _VECTOR_HPP

/*#################################################################################
#        Includes:                                                                #
#################################################################################*/
# include "IContainer.hpp"
# include <iostream>
# include <vector>
# include <algorithm>

/*#################################################################################
#        Vector Class:                                                            #
#################################################################################*/
class Vector : public IContainer {

	public:
		// === typedef : ===================================================
		typedef std::vector<unsigned int>					    vector_uint;
		typedef std::vector<vector_uint>::iterator			   mainIterator;
		typedef std::vector<vector_uint>::const_iterator	  CmainIterator;
		typedef vector_uint::iterator						   uintIterator;
		typedef vector_uint::const_iterator					  CuintIterator;
		typedef std::vector<std::pair<vector_uint, mainIterator> >::iterator
															   pendIterator;

		// === Constructor & Destructor : ==================================
		Vector(void);
		Vector(const Vector &other);
		virtual		~Vector(void);

		// === Operators : =================================================
		Vector&		operator=(const Vector &other);

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
		// === Attributes  : ===============================================
		std::vector<vector_uint>									mMain;
		std::vector< std::pair<vector_uint, mainIterator> >			mPend;
		const static unsigned long					 	   jacobsthal[63];
};

#endif // _VECTOR_HPP
