/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:05:31 by hael-mou          #+#    #+#             */
/*   Updated: 2023/11/28 13:16:04 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*##############################################################################
#       * Methods  :                                                           #
##############################################################################*/

//=== calculate : ==============================================================
int		RPN::calculate(const char *equation) 
{
	std::stack<int>		operandStack;
	RPN::type 			characterType;

	while (equation != NULL && *equation != '\0')
	{
		characterType = getType(equation);

		if (characterType == RPN::IsDigit) {
			operandStack.push(charToint(*equation));
		}
		if (characterType == RPN::IsOperater) {
			performCalculation(operandStack, *equation);
		}
		++equation;
	}
	if (operandStack.size() != 1){
		throw (std::invalid_argument("Error : invalid_form"));
	}
	return (operandStack.top());
}

//=== getType : ================================================================
RPN::type RPN::getType(const char* eqPtr)
{
	if (std::strchr("+-/*", eqPtr[0]) && std::strchr(" \0", eqPtr[1])) {
		return (RPN::IsOperater);
	}
	if (std::isdigit(eqPtr[0]) && std::strchr(" \0", eqPtr[1])) {
		return (RPN::IsDigit);
	}
	if (eqPtr[0] != ' ') {
		throw (std::invalid_argument("Error : invalid_form"));
	}
	return (RPN::IsSpace);
}

//=== my pop : =================================================================
static int	pop(std::stack<int> &stack)
{
	int	value = stack.top();
	return (stack.pop(), value);
}

//=== performCalculation : =====================================================
void RPN::performCalculation(std::stack<int> &operandStack, char operater)
{
	if (operandStack.size() < 2)
		throw (std::invalid_argument("Error : invalid_form"));
	
	int		numb1 = ::pop(operandStack);
	int		numb2 = ::pop(operandStack);
	switch (operater)
	{
		case '-':  operandStack.push(numb2 - numb1); break;
		case '+':  operandStack.push(numb2 + numb1); break;
		case '*':  operandStack.push(numb2 * numb1); break;
		case '/':  operandStack.push(numb2 / numb1); break;
		default: break;
	}
}

//=== charToint : ==============================================================
int RPN::charToint(char character)
{
	return (character - '0');
}
