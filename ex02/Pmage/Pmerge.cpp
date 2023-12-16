/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:05:31 by hael-mou          #+#    #+#             */
/*   Updated: 2023/12/16 10:56:02 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

/*##############################################################################
#       * Constructor & Destructor  :                                          #
##############################################################################*/

//=== Default Constructor : ====================================================
Pmerge::Pmerge(IContainer *container)
{
	mContainer = container;
}

//=== Copy Constructor : =======================================================
Pmerge::Pmerge(const Pmerge &other)
{

	(void)other;
}

//=== Destructor : =============================================================
Pmerge::~Pmerge(void)
{
	delete	(mContainer);
}

/*##############################################################################
#       *  Operators  :                                                        #
##############################################################################*/

//=== Assignment Operators : ===================================================
Pmerge&	Pmerge::operator=(const Pmerge &other)
{
	(void)other;
	return (*this);
}

/*##############################################################################
#       * Methods  :                                                           #
##############################################################################*/

//=== init Container : =========================================================
void Pmerge::initContainer(const char **list)
{
	char   *endptr;
	while (*list != NULL)
	{
		long nbr = std::strtol(*list++, &endptr, 10);
		if (errno == ERANGE || *endptr != '\0' || nbr < 0 || nbr > INT_MAX) {
			throw (std::invalid_argument("invalid argument !!"));
		}
		mContainer->push(static_cast<unsigned int>(nbr));
	}
	mContainer->reserve(mContainer->size());
}

//== mergeInsertionSort : ======================================================
void Pmerge::mergeInsertionSort(void)
{
	mContainer->sortPair();
	if (mContainer->hasAtLeastTwoPairs())
	{
	 	mContainer->combinePairs();
		this->mergeInsertionSort();
	}
	mContainer->CreatePend();
	mContainer->InsertPend();
	mContainer->splitPairs();
}

//== display=================================================================
void Pmerge::display(void)
{
	mContainer->display();
}
