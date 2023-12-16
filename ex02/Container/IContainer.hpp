/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IContainer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:07:30 by hael-mou          #+#    #+#             */
/*   Updated: 2023/12/16 10:57:33 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _ICONTAINER_HPP
# define _ICONTAINER_HPP

/*##############################################################################
#        Include :                                                             #
##############################################################################*/
#include <cstddef>

/*##############################################################################
#        IContainer Interface :                                                #
##############################################################################*/
class IContainer {	
	public:
		virtual			~IContainer(void) {};
	
		virtual size_t	size(void) const = 0;
		virtual void	display(void) const = 0;

		virtual void	reserve(size_t __size) = 0;
		virtual void	push(unsigned int nbr) = 0;

		virtual bool	hasAtLeastTwoPairs(void) = 0;
		virtual void	combinePairs(void) = 0;
		virtual void	sortPair(void) = 0;
		virtual void	splitPairs(void) = 0;
		
		virtual void	CreatePend(void) = 0;
		virtual void	InsertPend(void) = 0;
};

/*##############################################################################
#        Utils :                                                               #
##############################################################################*/
// *** return the prev iterator *** :
template<typename iterator>
iterator	prev(iterator it)
{
	return (--it);
}

// *** return the next iterator *** :
template<typename iterator>
iterator	next(iterator it)
{
	return (++it);
}

// *** Cmp last element of container *** :
template<typename __container>
bool	container_cmp(__container& a, __container b)
{
	return (a.back() < b.back());
}

#endif // _ICONTAINER_HPP
