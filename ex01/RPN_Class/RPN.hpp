/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:05:31 by hael-mou          #+#    #+#             */
/*   Updated: 2023/11/28 13:16:06 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RPN_HPP
# define _RPN_HPP

/*##############################################################################
#        Includes:                                                             #
##############################################################################*/
# include <iostream>
# include <cstring>
# include <cctype>
# include <stack>

/*##############################################################################
#        RPN Class:                                                            #
##############################################################################*/
class RPN {

	public:
		// === type define : =========================================
		typedef int			type;
		static const int	IsDigit = 1;
		static const int	IsOperater = 2;
		static const int	IsSpace = 3;

		// == Methods : ==============================================
		static int	calculate(const char *eq);

	private:
		// === Constructor : ========================================
		RPN(void);

		// == Methods : ==============================================
		static void			performCalculation(std::stack<int>& stack, char op);
		static type			getType(const char* eqPtr);
		inline static int	charToint(char character);
};

#endif // _RPN_HPP
